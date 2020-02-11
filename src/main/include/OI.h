/**
 * OI.h
 *
 *  Created on: Feb 05, 2020
 *      Author: Mike A.
 */
#ifndef SRC_OI_H_
#define SRC_OI_H_

#include <Climber.h>
#include <Feeder.h>
#include <Intake.h>
#include <Mobility.h>
#include <Shooter.h>
#include <Ports.h>
#include <frc/Joystick.h>
#include <frc/GenericHID.h>
#include <frc/XboxController.h>

class OI {
 public:
  static OI* getInstance();
  void processMobility();
  void processClimber();
  void processFeeder();
  void processIntake();
  void processShooter();

 private:
  OI();
  static OI* INSTANCE;
  ClimberEndEffector* climber;
  FeederEndEffector* feeder;
  IntakeEndEffector* intake;
  ShooterEndEffector* shooter;
};

#endif /* SRC_OI_H_ */