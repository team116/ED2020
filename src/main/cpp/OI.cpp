/*
*   Created on: Some day at some point in time
*   By: Jess Wu
*
*/

#include <OI.h>


OI *OI::INSTANCE = nullptr;



void OI::processClimber() {

}

void OI::processFeeder(){

}

void OI::processIntake() {

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