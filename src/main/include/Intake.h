/**
 * Intake.h
 *
 *  Created on: Feb 05, 2020
 *      Author: Mike A.
 */
#ifndef SRC_INTAKE_H_
#define SRC_INTAKE_H_

#include <OI.h>
#include <Ports.h>
#include <ctre/Phoenix.h>
#include <frc/DoubleSolenoid.h>

class IntakeEndEffector {
 public:
  void process();
  enum Direction { INTAKE, OFF, EJECT };

  // Assorted states
  void intakeDeploy();
  void intakeRetract();
  void intakeOff();
  void intakeMovement(Direction direction);

  static IntakeEndEffector* getInstance();

#ifdef ED2020
  WPI_TalonSRX m_IntakeMotor{RobotPorts::kIntakeID};
  frc::DoubleSolenoid m_IntakePiston{PCM0Ports::kPCM0, PCM0Ports::kIntakePistonExtend,
                                     PCM0Ports::kIntakePistonRetract};
#else
  // Test bot
#endif
  // Constructor for class

 private:
  IntakeEndEffector();
  static IntakeEndEffector* INSTANCE;
};

#endif /* SRC_INTAKE_H_ */