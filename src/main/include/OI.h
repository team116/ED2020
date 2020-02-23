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
#include <Ports.h>
#include <Shooter.h>
#include <frc/DriverStation.h>
#include <frc/GenericHID.h>
#include <frc/Joystick.h>
#include <frc/XboxController.h>

class OI {
   public:
    static OI *getInstance();
    void process();
    void processClimber();
    void processFeeder();
    void processIntake();
    void processShooter();

   private:
    frc::DriverStation &ds = frc::DriverStation::GetInstance();
    OI();
    static OI *INSTANCE;

    //  ClimberEndEffector *climber;
    //  FeederEndEffector *feeder;
    //  IntakeEndEffector *intake;
    //  ShooterEndEffector *shooter;
};

#endif /* SRC_OI_H_ */