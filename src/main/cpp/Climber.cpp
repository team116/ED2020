/*
*   Created on: 02/22/20
*   By: Mike A
*
*/
#include <frc/drive/DifferentialDrive.h>
#include <Ports.h>
#include <Climber.h>

ClimberEndEffector* ClimberEndEffector::INSTANCE = nullptr;

ClimberEndEffector* ClimberEndEffector::getInstance() {
    if (INSTANCE == nullptr) {
        INSTANCE = new ClimberEndEffector();
    }
    return INSTANCE;
}

void ClimberEndEffector::process() {
    // Do the work
}