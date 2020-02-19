/**
 * Intake.h
 *
 *  Created on: Feb 05, 2020
 *      Author: Mike A.
 */
#ifndef SRC_INTAKE_H_
#define SRC_INTAKE_H_

#include <Ports.h>
#include <ctre/Phoenix.h>
#include <frc/DoubleSolenoid.h>

class IntakeEndEffector {
 public:
  static IntakeEndEffector* getInstance();

  // Motor is a RS775 with Talon SRX
  WPI_TalonSRX m_IntakeMotor{RobotPorts::kIntakeID};

  frc::DoubleSolenoid IntakeFolder{PCM0Ports::kPCM0CANID, PCM0Ports::kIntakeFolderExtend,
                                   PCM0Ports::kIntakeFolderRetract};

 private:
  IntakeEndEffector();
  static IntakeEndEffector* INSTANCE;
};

#endif /* SRC_INTAKE_H_ */