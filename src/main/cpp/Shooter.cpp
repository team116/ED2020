/*
 *   Created on: Some Day
 *   By: Jess Wu
 *
 */
#include <Ports.h>
#include <Shooter.h>
#include <frc/drive/DifferentialDrive.h>

#ifndef TALONS_ONLY
#include "rev/CANSparkMax.h"
#endif // !TALONS_ONLY

#ifdef TALONS_ONLY
#include <ctre/Phoenix.h>
#endif

#include <semaphore.h>
#include <pthread.h>
#include "frc/smartdashboard/Smartdashboard.h"
#include "networktables/NetworkTable.h"
#include "networktables/NetworkTableInstance.h"

sem_t limelightSem;
ShooterEndEffector* ShooterEndEffector::INSTANCE = nullptr;

ShooterEndEffector* ShooterEndEffector::getInstance() {
    if (INSTANCE == nullptr) {
        INSTANCE = new ShooterEndEffector();
    }
    return INSTANCE;
}
#ifndef TALONS_ONLY
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
#endif // !TALONS_ONLY

#ifdef TALONS_ONLY
void ShooterEndEffector::setSpeed(double percentPower) {
    m_Shooter1Motor.Set(percentPower);
}

double ShooterEndEffector::getSpeed() {
    return m_Shooter1Motor.Get();
}
#endif

void ShooterEndEffector::process() {}

#if defined(__linux__)
std::shared_ptr<NetworkTable> ShooterEndEffector::table = nt::NetworkTableInstance::GetDefault().GetTable("limelight");
static void limelightInterfaceThread() {
    while (true) {
        sem_wait(&limelightSem);
        // Here we do the limelight interface code
        double targetOffsetAngle_Horizontal = ShooterEndEffector::table->GetNumber("tx", 0);
        bool targetExists = ShooterEndEffector::table->GetNumber("tv", 0);
 
        double targetOffsetAngle_Vertical = ShooterEndEffector::table->GetNumber("ty",0.0);
        double targetArea = ShooterEndEffector::table->GetNumber("ta",0.0);
        double targetSkew = ShooterEndEffector::table->GetNumber("ts",0.0);

        //post to smart dashboard periodically
        frc::SmartDashboard::PutNumber("LimelightX", targetOffsetAngle_Horizontal);
        frc::SmartDashboard::PutNumber("LimelightY", targetOffsetAngle_Vertical);
        frc::SmartDashboard::PutNumber("LimelightArea", targetArea);
        frc::SmartDashboard::PutNumber("LimelightSkew", targetSkew);

        // Change to mapped control
        if (false) {
            ShooterEndEffector::table->PutNumber("pipeline", 3);
        }

        // Change to mapped control
        if (true) {
            ShooterEndEffector::table->PutNumber("pipeline", 1);
            if (targetExists) {
                // Send the Drive to the correct position using pigeon
            }
        }

        
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