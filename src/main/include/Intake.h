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

<<<<<<< HEAD
  // Motor is a RS775 with Talon SRX
  WPI_TalonSRX m_IntakeMotor{RobotPorts::kIntakeID};

  frc::DoubleSolenoid IntakeFolder{PCM0Ports::kPCM0CANID, PCM0Ports::kIntakeFolderExtend,
                                   PCM0Ports::kIntakeFolderRetract};
=======
  enum Direction{ INTAKE, OFF, EJECT  };

  WPI_VictorSPX m_Intake{RobotPorts::kIntake}; /* I don't think that this is a victor motor 
                                              * But I don't know what else to put for a 
                                              * 775 motor...
                                              */ 
  frc::DoubleSolenoid IntakeFolder {PCM0Ports::kPCM0CANID, 
                                    PCM0Ports::kIntakeFolderRelease,
                                    PCM0Ports::kIntakeFolderRetract};

  //Assorted states
  void intakeDeploy();
  void intakeRetract();
  void intakeOff();
  void intakeMovement(Direction direction);
>>>>>>> 4fea1071f592e4aff69676559fe04bcdb05c110d

 private:
  IntakeEndEffector();
  static IntakeEndEffector* INSTANCE;
};

#endif /* SRC_INTAKE_H_ */