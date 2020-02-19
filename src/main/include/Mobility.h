/**
 * Mobility.h
 *
 *  Created on: Feb 05, 2020
 *      Author: Mike A.
 */
#ifndef SRC_MOBILITY_H_
#define SRC_MOBILITY_H_

#include <frc/drive/DifferentialDrive.h>
#include <Ports.h>
#include <ctre/Phoenix.h>
#include <OI.h>

class Mobility {
 public:
  void process();
  static Mobility* getInstance();

#ifdef ED2020
  WPI_VictorSPX m_LeftFrontMotor{RobotPorts::kLeftSide1};
  WPI_VictorSPX m_LeftRearMotor{RobotPorts::kLeftSide2};
  WPI_VictorSPX m_RightFrontMotor{RobotPorts::kRightSide1};
  WPI_VictorSPX m_RightRearMotor{RobotPorts::kRightSide2};
#else
  // Test bot
#endif

  frc::SpeedControllerGroup m_LeftSide{m_LeftSideMotor1, m_LeftSideMotor2};
  frc::SpeedControllerGroup m_RightSide{m_RightSideMotor1, m_RightSideMotor2};


  frc::DifferentialDrive m_RobotDrive{m_LeftSide, m_RightSide};

  void TankDrive(float left, float right);

 private:
  Mobility();
  OI *oi;

  static Mobility* INSTANCE;
};


#endif /* SRC_MOBILITY_H_ */