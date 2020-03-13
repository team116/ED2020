/*
 * Ports.h
 *
 *  Created on: Feb 05, 2020
 *      Author: Mike A.
 */
#ifndef SRC_PORTS_H_
#define SRC_PORTS_H_

// We're running on the real robot
#define ED2020 1

// Do we have the Pigeon IMU?
//#define HASPIGEONIMU 1

//#define USE_PID_FOR_NEOS

#define HAVE_SHOOTER_MOTORS

#define TALONS_ONLY

namespace RobotPorts {

// Motor Controller Ports
// CAN IDs
constexpr int kPDPID = 0;
constexpr int kLeftFrontID = 1;
constexpr int kLeftRearID = 2;
constexpr int kRightFrontID = 3;
constexpr int kRightRearID = 4;
constexpr int kFeederID = 5;
#ifdef HAVE_SHOOTER_MOTORS
constexpr int kShooter1ID = 6;
constexpr int kShooter2ID = 7;
#endif // HAVE_SHOOTER_MOTORS
constexpr int kIntakeID = 8;
constexpr int kSpinnerID = 11;
constexpr int kWinchID = 10;
constexpr int kCrawlerID = 9;
constexpr int kPigeonID = 12;

// Digital I/O from RoboRIO  --  Be sure the rename these to something more
// meaningful
constexpr int kDIOChannel0 = 0;
constexpr int kDIOChannel1 = 1;
constexpr int kDIOChannel2 = 2;
constexpr int kDIOChannel3 = 3;
constexpr int kDIOChannel4 = 4;
constexpr int kDIOChannel5 = 5;
constexpr int kDIOChannel6 = 6;
constexpr int kDIOChannel7 = 7;
constexpr int kDIOChannel8 = 8;
constexpr int kDIOChannel9 = 9;

// Analog Inputs
constexpr int kAIChannel0 = 0;
constexpr int kAIChannel1 = 1;
constexpr int kAIChannel2 = 2;
constexpr int kAIChannel3 = 3;

}  // namespace RobotPorts

namespace PCM0Ports {
constexpr int kPCM0 = 0;
// Pneumatics Control Module 0
constexpr int kPCM0CANID = 15;
constexpr int kIntakePistonExtend = 0;
constexpr int kIntakePistonRetract = 7;
constexpr int kShooterHoodExtend = 3; // was 1
constexpr int kShooterHoodRetract = 4; // was 6
constexpr int kColorSpinnerExtend = 1;  // was 2
constexpr int kColorSpinnerRetract = 6;  // was 5
constexpr int kClimberRelease = 5;  // was 3
constexpr int kExtra = 2; // was 4
}  // namespace PCM0Ports

namespace OIPorts {
constexpr int kXboxPort = 0;
constexpr int kLogitechPort = 1;

// Logitech button mappings
constexpr int kShooterWheelButtonNum = 1;
constexpr int kClimberControlsActiveButtonNum = 2;
constexpr int kIntakeRollerInButtonNum = 3;
constexpr int kIntakeRollerOutButtonNum = 4;
constexpr int kIntakeRollerOffButtonNum1 = 5;
constexpr int kIntakeRollerOffButtonNum2 = 6;
constexpr int kClimberReleaseButtonNum = 7;
constexpr int kTurnOffAllSolenoidsButtonNum = 8;
constexpr int kControlWheelExtendButtonNum = 9;
constexpr int kControlWheelRetractButtonNum = 10;
constexpr int kControlWheelNormalSpeedButtonNum = 11;
constexpr int kControlWheelSlowSpeedButtonNum = 12;
} // namespace OIPorts

#endif /* SRC_PORTS_H_ */