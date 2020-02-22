/*
*   Created on: Some day at some point in time
*   By: Jess Wu
*
*/

#include <OI.h>
//Get rid of some Control at some point and replace with the control OI uses
bool someControl = false;
OI *OI::INSTANCE = nullptr;



void OI::processClimber() {
    
}

void OI::processFeeder(){

}

void OI::processIntake() {
    //Intake Piston Controls
    if (someControl) {
//        OI::intake->intakeRetract();
    }

    if (someControl) {
//        OI::intake->intakeDeploy();
    }

    //Intake Roller Controls
    if (someControl) {
//        OI::intake->intakeOff();
    }

    if (someControl) {
 //       OI::intake->intakeMovement(IntakeEndEffector::Direction::OFF);
    } else if (someControl) {
 //       OI::intake->intakeMovement(IntakeEndEffector::Direction::INTAKE);
    } else if (someControl) {
 //       OI::intake->intakeMovement(IntakeEndEffector::Direction::EJECT);
    } else {
//        OI::intake->intakeMovement(IntakeEndEffector::Direction::OFF);
    }

    
}

void OI::processShooter() {

}

OI::OI() {
    
}

void OI::process() {
    // processes all different parts if the robot.
    OI::processFeeder();
    OI::processClimber();
    OI::processIntake();
    OI::processShooter();

}

OI *OI::getInstance() {
    if (INSTANCE == nullptr) {
        INSTANCE = new OI();
    }
    return INSTANCE;
}