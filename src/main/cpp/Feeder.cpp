/*
 *   Created on: Some Day
 *   By: Jess Wu
 *
 */
#include <Feeder.h>
#include <Ports.h>
#include <frc/drive/DifferentialDrive.h>
#include "rev/CANSparkMax.h"

FeederEndEffector* FeederEndEffector::INSTANCE = nullptr;

FeederEndEffector* FeederEndEffector::getInstance() {
    if (INSTANCE == nullptr) {
        INSTANCE = new FeederEndEffector();
    }
    return INSTANCE;
}

void FeederEndEffector::feederPID(double setpoint) {
    FeederEndEffector::SetPoint = setpoint;
    FeederEndEffector::m_pidController.SetReference(FeederEndEffector::SetPoint,
                                                    rev::ControlType::kVelocity);
}

void FeederEndEffector::process() {}