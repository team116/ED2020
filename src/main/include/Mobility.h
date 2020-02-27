/**
 * Mobility.h
 *
 *  Created on: Feb 05, 2020
 *      Author: Mike A.
 */
#ifndef SRC_MOBILITY_H_
#define SRC_MOBILITY_H_

#include <OI.h>
#include <Ports.h>
#include <ctre/Phoenix.h>
#include <frc/drive/DifferentialDrive.h>

class Mobility {
   public:
    void process();
    static Mobility* getInstance();

#ifdef ED2020
    WPI_TalonSRX m_LeftFrontMotor{RobotPorts::kLeftFrontID};
    WPI_TalonSRX m_LeftRearMotor{RobotPorts::kLeftRearID};
    WPI_TalonSRX m_RightFrontMotor{RobotPorts::kRightFrontID};
    WPI_TalonSRX m_RightRearMotor{RobotPorts::kRightRearID};

    frc::DifferentialDrive m_RobotDrive{m_LeftFrontMotor, m_RightFrontMotor};
#else
    // Test bot
#endif
    // Constructor for class
#ifdef HASPIGEONIMU
    PigeonIMU* pigeon = new PigeonIMU(RobotPorts::kPigeonID);

    enum {
        GoStraightOff,
        GoStraightWithPidgeon,
        GoStraightSameThrottle
    } goStraight = GoStraightOff;

    /* Some gains for heading servo,
     * these were tweaked by using the web-based config (CAN Talon) and
     * pressing gamepad button 6 to load them.
     */
    double kPgain = 0.04;   /* percent throttle per degree of error */
    double kDgain = 0.0004; /* percent throttle per angular velocity dps */
    /* cap corrective turning throttle to 30 percent of forward throttle */
    double kMaxCorrectionRatio = 0.30;
    /** holds the current angle to servo to */
    double targetAngle = 0;
    /** count loops to print every second or so */
    int _printLoops = 0;

#endif

   private:
    Mobility();
    OI* oi;

    static Mobility* INSTANCE;
};

#endif /* SRC_MOBILITY_H_ */