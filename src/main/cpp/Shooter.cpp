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

#ifdef USE_PID_FOR_NEOS
void ShooterEndEffector::shooterPID(double setpoint) {
    #ifdef HAVE_SHOOTER_MOTORS
    ShooterEndEffector::SetPoint = setpoint;
    ShooterEndEffector::m_pidController.SetReference(ShooterEndEffector::SetPoint,
                                                     rev::ControlType::kVelocity);
    #endif // HAVE_SHOOTER_MOTORS
}
#endif // USE_PID_FOR_NEOS

#ifndef USE_PID_FOR_NEOS
void ShooterEndEffector::setSpeed(double percentPower) {
    #ifdef HAVE_SHOOTER_MOTORS
    m_Shooter1Motor.Set(percentPower);
    #endif // HAVE_SHOOTER_MOTORS
}

double ShooterEndEffector::getSpeed() {
    #ifdef HAVE_SHOOTER_MOTORS
    return m_Shooter1Motor.Get();
    #endif // HAVE_SHOOTER_MOTORS

    #ifndef HAVE_SHOOTER_MOTORS
    return 0.0;
    #endif // ! HAVE_SHOOTOR_MOTORS
}
#endif // ! USE_PID_FOR_NEOS

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