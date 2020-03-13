/*
 *   Created on: Some Day
 *   By: Jess Wu
 *
 */
#include <Feeder.h>
#include <Ports.h>
#include <frc/drive/DifferentialDrive.h>

#ifndef TALONS_ONLY
#include "rev/CANSparkMax.h"
#endif // !TALONS_ONLY

#ifdef TALONS_ONLY
#include <ctre/Phoenix.h>
#endif

FeederEndEffector* FeederEndEffector::INSTANCE = nullptr;

FeederEndEffector* FeederEndEffector::getInstance() {
    if (INSTANCE == nullptr) {
        INSTANCE = new FeederEndEffector();
    }
    return INSTANCE;
}

#ifndef TALONS_ONLY
#ifdef USE_PID_FOR_NEOS
void FeederEndEffector::feederPID(double setpoint) {
    FeederEndEffector::SetPoint = setpoint;
    FeederEndEffector::m_pidController.SetReference(FeederEndEffector::SetPoint,
                                                    rev::ControlType::kVelocity);
}
#endif //USE_PID_FOR_NEOS

#ifndef USE_PID_FOR_NEOS
void FeederEndEffector::setSpeed(double percentPower) {
    m_FeederMotor.Set(percentPower);
}
#endif // !USE_PID_FOR_NEOS
#endif // !TALONS_ONLY

#ifdef TALONS_ONLY
void FeederEndEffector::setSpeed(double percentPower) {
    m_FeederMotor.Set(percentPower);
}
#endif // TALONS_ONLY


void FeederEndEffector::process() {}