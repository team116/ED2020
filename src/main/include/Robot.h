/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <string>

#include <frc/DriverStation.h>
#include <frc/Compressor.h>
#include <frc/TimedRobot.h>
#include <frc/smartdashboard/SendableChooser.h>
#include <OI.h>
#include <Mobility.h>
#include <Shooter.h>
#include <Feeder.h>

class Robot : public frc::TimedRobot {
   public:
    void RobotInit() override;
    void RobotPeriodic() override;
    void AutonomousInit() override;
    void AutonomousPeriodic() override;
    void TeleopInit() override;
    void TeleopPeriodic() override;
    void TestPeriodic() override;
    frc::Compressor *compress = new frc::Compressor(PCM0Ports::kPCM0CANID);
    frc::DriverStation& ds = frc::DriverStation::GetInstance();

   private:
    OI *oi;
    Mobility *mobility;
    ShooterEndEffector *shooter;
    FeederEndEffector *feeder;
    double autoDelaySeconds = 0.0;
    frc::Timer* autoDelayTimer;
    frc::Timer* drivingTimer;
    frc::Timer* shooterRampUpTimer;
    frc::Timer* feederTimer;

    double autoShooterRpms = 0.0;
    int step = 0;
    //frc::SendableChooser<std::string> m_chooser;
    //const std::string kAutoNameDefault = "Default";
    //const std::string kAutoNameCustom = "My Auto";
    //std::string m_autoSelected;
};
