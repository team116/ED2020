/**
 * Feeder.h
 *
 *  Created on: Feb 05, 2020
 *      Author: Mike A.
 */
#ifndef SRC_FEEDER_H_
#define SRC_FEEDER_H_

#include <Ports.h>
#include "rev/CANSparkMax.h"

class FeederEndEffector {
 public:
  // default PID coefficients
  double kP = 6e-5, kI = 1e-6, kD = 0, kIz = 0, kFF = 0.000015, kMaxOutput = 1.0,
         kMinOutput = -1.0;

  // motor max RPM
  const double MaxRPM = 5700;
  // read setpoint from joystick and scale by max rpm
  double SetPoint = 0.0;  // = MaxRPM*m_stick.GetY();

  static FeederEndEffector* getInstance();
  void feederPID(double setpoint);
  void process();
  // Should be a NEO motor
  rev::CANSparkMax m_FeederMotor{RobotPorts::kFeederID,
                                 rev::CANSparkMax::MotorType::kBrushless};
  /**
   * In order to use PID functionality for a controller, a CANPIDController object
   * is constructed by calling the GetPIDController() method on an existing
   * CANSparkMax object
   */
  rev::CANPIDController m_pidController = m_FeederMotor.GetPIDController();

  // Encoder object created to display velocity values
  //  rev::CANEncoder m_encoder = m_FeederMotor.GetEncoder(); // for display purposes

  FeederEndEffector() {
    // Reset motor defaults and switch to Coast mode
    m_FeederMotor.RestoreFactoryDefaults();
    m_FeederMotor.SetIdleMode(rev::CANSparkMax::IdleMode::kCoast);

    // set PID coefficients
    m_pidController.SetP(kP);
    m_pidController.SetI(kI);
    m_pidController.SetD(kD);
    m_pidController.SetIZone(kIz);
    m_pidController.SetFF(kFF);
    m_pidController.SetOutputRange(kMinOutput, kMaxOutput);
  }

 private:
  static FeederEndEffector* INSTANCE;
};

#endif /* SRC_FEEDER_H_ */