/*
 *   Created on: 02/22/20
 *   By: Mike A
 *
 */
#include <Climber.h>
#include <Ports.h>
#include <frc/drive/DifferentialDrive.h>

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

void ClimberEndEffector::releaseClimber() {
    if (!ClimberExtender.Get()) {
        ClimberExtender.Set(true);
    }
}

void ClimberEndEffector::turnSolenoidOff() {
    if (ClimberExtender.Get()) {
        ClimberExtender.Set(false);
    }
}

void ClimberEndEffector::runWinch(double velocity) {
    Winch.Set(velocity);
}

void ClimberEndEffector::stopWinch() {
    runWinch(0.0);
}
