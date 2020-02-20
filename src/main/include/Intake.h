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

  IntakeEndEffector() {
   // Motor is a RS775 with Talon SRX
  WPI_TalonSRX m_IntakeMotor{RobotPorts::kIntakeID};

  frc::DoubleSolenoid IntakeFolder{PCM0Ports::kPCM0CANID, PCM0Ports::kIntakeFolderExtend,
                                   PCM0Ports::kIntakeFolderRetract};
   
  }

  enum Direction { INTAKE, OFF, EJECT };

  // Assorted states
  void intakeDeploy();
  void intakeRetract();
  void intakeOff();
  void intakeMovement(Direction direction);

 private:

  static IntakeEndEffector* INSTANCE;
};

#endif /* SRC_INTAKE_H_ */