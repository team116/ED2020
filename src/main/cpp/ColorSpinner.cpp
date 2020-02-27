/*
 *   Created on: 02/22/20
 *   By: Mike A.
 *
 */
#include <ColorSpinner.h>
#include <Ports.h>
#include <ctre/Phoenix.h>

ColorSpinnerEndEffector* ColorSpinnerEndEffector::INSTANCE = nullptr;

ColorSpinnerEndEffector* ColorSpinnerEndEffector::getInstance() {
    if (INSTANCE == nullptr) {
        INSTANCE = new ColorSpinnerEndEffector();
    }
    return INSTANCE;
}

void ColorSpinnerEndEffector::process() {}

void ColorSpinnerEndEffector::extend() {
    ColorSpinnerFolder.Set(frc::DoubleSolenoid::kForward);
}

void ColorSpinnerEndEffector::retract() {
    ColorSpinnerFolder.Set(frc::DoubleSolenoid::kReverse);
}

void ColorSpinnerEndEffector::turnOffSolenoid() {
    ColorSpinnerFolder.Set(frc::DoubleSolenoid::kOff);
}

void ColorSpinnerEndEffector::spinNormalSpeed() {
    ColorSpinner.Set(1.0);
}

void ColorSpinnerEndEffector::spinSlowSpeed() {
    ColorSpinner.Set(0.5);
}

void ColorSpinnerEndEffector::stopSpinning() {
    ColorSpinner.Set(0.0);
}