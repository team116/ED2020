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

  // Constructor
  Mobility() {
#ifdef ED2020
    WPI_TalonSRX m_LeftFrontMotor{RobotPorts::kLeftFrontID};
    WPI_TalonSRX m_LeftRearMotor{RobotPorts::kLeftRearID};
    WPI_TalonSRX m_RightFrontMotor{RobotPorts::kRightFrontID};
    WPI_TalonSRX m_RightRearMotor{RobotPorts::kRightRearID};
    WPI_TalonSRX m_SpinnerMotor{RobotPorts::kSpinnerID};
    WPI_TalonSRX m_WinchMotor{RobotPorts::kWinchID};
    WPI_TalonSRX m_CrawlerMotor{RobotPorts::kCrawlerID};

    frc::DifferentialDrive m_RobotDrive{m_LeftFrontMotor, m_RightFrontMotor};
#else
    // Test bot
#endif
  }

  void TankDrive(float left, float right);

 private:
  OI* oi;

  static Mobility* INSTANCE;
};

#endif /* SRC_MOBILITY_H_ */