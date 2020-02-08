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

  WPI_Vic775 motor...torSPX m_intake{RobotPorts::kIntake} /* I don't think that this is a victor motor 
                                              * But I don't know what else to put for a 
                                              * 775 motor...
                                              */ 
  frc::DoubleSolenoid IntakeFolder {PCM0Ports::kPCM0CANID, 
                                    PCM0Ports::kIntakeFolderRelease,
                                    PCM0Ports::kIntakeFolderRetract}
 private:
  IntakeEndEffector();
  static IntakeEndEffector* INSTANCE;
};

#endif /* SRC_INTAKE_H_ */