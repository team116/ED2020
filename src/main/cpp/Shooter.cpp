/*
 *   Created on: Some Day
 *   By: Jess Wu
 *
 */
#include <Ports.h>
#include <Shooter.h>
#include <frc/drive/DifferentialDrive.h>
#include "rev/CANSparkMax.h"
#include <semaphore.h>
#include <pthread.h>

sem_t limelightSem;
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

#if defined(__linux__)
static void limelightInterfaceThread() {
    while (true) {
        sem_wait(&limelightSem);
        // Here we do the limelight interface code
    }
}
#endif

void ShooterEndEffector::launchLimelightInterfaceThread() {
#if defined(__linux__)
  std::thread limelightThread(limelightInterfaceThread);
  limelightThread.detach();
#else
  wpi::errs() << "limelight Thread only available on Linux.\n";
  wpi::errs().flush();
#endif
}