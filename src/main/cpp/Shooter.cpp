/*
 *   Created on: Some Day
 *   By: Jess Wu
 *
 */
#include <Ports.h>
#include <Shooter.h>
#include <frc/drive/DifferentialDrive.h>
#include "rev/CANSparkMax.h"

ShooterEndEffector* ShooterEndEffector::INSTANCE = nullptr;

ShooterEndEffector* ShooterEndEffector::getInstance() {
    if (INSTANCE == nullptr) {
        INSTANCE = new ShooterEndEffector();
    }
    return INSTANCE;
}

void ShooterEndEffector::shooterPID(double setpoint) {
    ShooterEndEffector::SetPoint = setpoint;
    ShooterEndEffector::m_pidController.SetReference(ShooterEndEffector::SetPoint,
                                                     rev::ControlType::kVelocity);
}

void ShooterEndEffector::process() {}