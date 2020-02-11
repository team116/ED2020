/**
 * Mobility.h
 *
 *  Created on: Feb 05, 2020
 *      Author: Mike A.
 */
#ifndef SRC_MOBILITY_H_
#define SRC_MOBILITY_H_

#include <Ports.h>
#include <ctre/Phoenix.h>
#include <OI.h>
#include <frc/SpeedControllerGroup.h>

#include <frc/drive/DifferentialDrive.h>

class Mobility {
 public:
  void process();
  static Mobility* getInstance();


  WPI_VictorSPX m_LeftSideMotor1{RobotPorts::kLeftSide1};
  WPI_VictorSPX m_LeftSideMotor2{RobotPorts::kLeftSide2};
  WPI_VictorSPX m_RightSideMotor1{RobotPorts::kRightSide1};
  WPI_VictorSPX m_RightSideMotor2{RobotPorts::kRightSide2};

  frc::SpeedControllerGroup m_LeftSide{m_LeftSideMotor1, m_LeftSideMotor2};
  frc::SpeedControllerGroup m_RightSide{m_RightSideMotor1, m_RightSideMotor2};


  frc::DifferentialDrive m_RobotDrive{m_LeftSide, m_RightSide};

  void TankDrive(float left, float right);

 private:
  Mobility();


  static Mobility* INSTANCE;
};


#endif /* SRC_MOBILITY_H_ */