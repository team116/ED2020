/**
 * Shooter.h
 *
 *  Created on: Feb 05, 2020
 *      Author: Mike A.
 */
#ifndef SRC_SHOOTER_H_
#define SRC_SHOOTER_H_

#include <Ports.h>
#include <frc/DoubleSolenoid.h>
#include "rev/CANSparkMax.h"
#include "networktables/NetworkTable.h"
#include "networktables/NetworkTableInstance.h"

class ShooterEndEffector {
   public:
    // default PID coefficients
    double kP = 6e-5, kI = 1e-6, kD = 0, kIz = 0, kFF = 0.000015, kMaxOutput = 1.0,
           kMinOutput = -1.0;

    // motor max RPM
    const double MaxRPM = -5700;  // NOTE: We want the RPM to be negative
    // read setpoint from joystick and scale by max rpm
    double SetPoint = 0.0;  // = MaxRPM*m_stick.GetY();

    static ShooterEndEffector* getInstance();

    void process();
    void launchLimelightInterfaceThread();

    #ifdef USE_PID_FOR_NEOS
    void shooterPID(double setpoint);
    #endif // USE_PID_FOR_NEOS

    #ifndef USE_PID_FOR_NEOS
    void setSpeed(double percentPower);
    double getSpeed();
    #endif // ! USE_PID_FOR_NEOS

    #ifdef HAVE_SHOOTER_MOTORS
    // rename these when design is more final
    // These have to be declared outside of the constructor for it to work
    rev::CANSparkMax m_Shooter1Motor{RobotPorts::kShooter1ID,
                                     rev::CANSparkMax::MotorType::kBrushless};

    rev::CANSparkMax m_Shooter2Motor{RobotPorts::kShooter2ID,
                                     rev::CANSparkMax::MotorType::kBrushless};

    rev::CANEncoder m_Shooter1Encoder{m_Shooter1Motor};
    rev::CANEncoder m_Shooter2Encoder{m_Shooter2Motor};

    //frc::DoubleSolenoid m_ShooterHood{PCM0Ports::kPCM0CANID,
    //                                  PCM0Ports::kShooterHoodExtend,
    //                                  PCM0Ports::kShooterHoodRetract};
    /**
     * In order to use PID functionality for a controller, a CANPIDController object
     * is constructed by calling the GetPIDController() method on an existing
     * CANSparkMax object
     */
    #ifdef USE_PID_FOR_NEOS
    rev::CANPIDController m_pidController = m_Shooter1Motor.GetPIDController();
    #endif // USE_PID_FOR_NEOS
    #endif // HAVE_SHOOTER_MOTORS

    // Encoder object created to display velocity values
    //  rev::CANEncoder m_encoder = m_Shooter1Motor.GetEncoder();  // for display purposes

    static std::shared_ptr<NetworkTable> table;

    ShooterEndEffector() {
        #ifdef HAVE_SHOOTER_MOTORS
        // Initialize motors to factory defaults and set IdleMode
        m_Shooter1Motor.RestoreFactoryDefaults();
        m_Shooter2Motor.RestoreFactoryDefaults();
        m_Shooter1Motor.SetIdleMode(rev::CANSparkMax::IdleMode::kCoast);
        m_Shooter2Motor.SetIdleMode(rev::CANSparkMax::IdleMode::kCoast);

        // Have Shooter2 follow Shooter1 -- we only need to send commands to Shooter1
        m_Shooter2Motor.Follow(m_Shooter1Motor, true);

        #ifdef USE_PID_FOR_NEOS
        // set PID coefficients
        m_pidController.SetP(kP);
        m_pidController.SetI(kI);
        m_pidController.SetD(kD);
        m_pidController.SetIZone(kIz);
        m_pidController.SetFF(kFF);
        m_pidController.SetOutputRange(kMinOutput, kMaxOutput);
        #endif // USE_PID_FOR_NEOS
        #endif // HAVE_SHOOTER_MOTORS

        try {
            //      oi = OI::getInstance();
        } catch (std::exception& e) {
            // add some kind of error message that means something
        }
    }

   private:
    static ShooterEndEffector* INSTANCE;
};

#endif /* SRC_SHOOTER_H_ */