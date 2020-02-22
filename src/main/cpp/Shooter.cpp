/*
*   Created on: Some Day
*   By: Jess Wu
*
*/
#include <frc/drive/DifferentialDrive.h>
#include <Ports.h>
#include <Shooter.h>
#include "rev/CANSparkMax.h"

ShooterEndEffector* ShooterEndEffector::INSTANCE = nullptr;

ShooterEndEffector* ShooterEndEffector::getInstance() {
    if (INSTANCE == nullptr) {
        INSTANCE = new ShooterEndEffector();
    }
    return INSTANCE;
}