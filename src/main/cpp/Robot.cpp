/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "Robot.h"

#include <iostream>

#include <frc/smartdashboard/SmartDashboard.h>

void Robot::RobotInit() {
    double currentComp;
    bool enabled;
    bool pressureSW;

    autoDelayTimer = new frc::Timer();
    drivingTimer = new frc::Timer();
    shooterRampUpTimer = new frc::Timer();
    feederTimer = new frc::Timer();

    //m_chooser.SetDefaultOption(kAutoNameDefault, kAutoNameDefault);
    //m_chooser.AddOption(kAutoNameCustom, kAutoNameCustom);
    //frc::SmartDashboard::PutData("Auto Modes", &m_chooser);
    // This is a comment
    // test 2

    // Get the OI instance
    try {
        oi = OI::getInstance();

        oi->m_delay.SetDefaultOption("NO Delay", OI::Delay::ZERO);
        oi->m_delay.AddOption("(1) One Second", OI::Delay::ONE);
        oi->m_delay.AddOption("(2) Two Seconds", OI::Delay::TWO);
        oi->m_delay.AddOption("(3) Three Seconds", OI::Delay::THREE);
        oi->m_delay.AddOption("(5) Five Seconds", OI::Delay::FIVE);
        oi->m_delay.AddOption("(10) Ten Seconds", OI::Delay::TEN);
        frc::SmartDashboard::PutData("Start Delay", &(oi->m_delay));

        oi->m_play.SetDefaultOption("Do Nothing", OI::Play::DONOTHING);
        oi->m_play.AddOption("Move Off The Line", OI::Play::GETOFFTHELINE);
        oi->m_play.AddOption("Shoot From Left", OI::Play::LEFTSHOOT);
        oi->m_play.AddOption("Shoot From Middle", OI::Play::MIDDLESHOOT);
        oi->m_play.AddOption("Shoot From Right", OI::Play::RIGHTSHOOT);
        oi->m_play.AddOption("Utimate Shoot", OI::Play::SHOOTANDGETBALLS);
        frc::SmartDashboard::PutData("Auto Play", &(oi->m_play));
    } catch (std::exception &e) {
        frc::DriverStation::ReportError("Error initializing OI object");
        frc::DriverStation::ReportError(e.what());
    }

      // Mobility
    try {
        mobility = Mobility::getInstance();
    } catch (std::exception &e) {
        frc::DriverStation::ReportError("Error initializing Mobility object");
        frc::DriverStation::ReportError(e.what());
    }

    // Shooter
    try {
        shooter = ShooterEndEffector::getInstance();
    } catch (std::exception &e) {
        frc::DriverStation::ReportError("Error initializing Shooter object");
        frc::DriverStation::ReportError(e.what());
    }

    // Feeder
    try {
        feeder = FeederEndEffector::getInstance();
    } catch (std::exception &e) {
        frc::DriverStation::ReportError("Error initializing Feeder object");
        frc::DriverStation::ReportError(e.what());
    }

    // Enable the closed loop compressor
    Robot::compress->SetClosedLoopControl(true);
    enabled = compress->Enabled();
    pressureSW = compress->GetPressureSwitchValue();
    currentComp = compress->GetCompressorCurrent();
    printf(" %d  %d  %f", enabled, pressureSW, currentComp);
}

/**
 * This function is called every robot packet, no matter the mode. Use
 * this for items like diagnostics that you want ran during disabled,
 * autonomous, teleoperated and test.
 *
 * <p> This runs after the mode specific periodic functions, but before
 * LiveWindow and SmartDashboard integrated updating.
 */
void Robot::RobotPeriodic() {}

/**
 * This autonomous (along with the chooser code above) shows how to select
 * between different autonomous modes using the dashboard. The sendable chooser
 * code works with the Java SmartDashboard. If you prefer the LabVIEW Dashboard,
 * remove all of the chooser code and uncomment the GetString line to get the
 * auto name from the text box below the Gyro.
 *
 * You can add additional auto modes by adding additional comparisons to the
 * if-else structure below with additional strings. If using the SendableChooser
 * make sure to add them to the chooser code above as well.
 */
void Robot::AutonomousInit() {
    autoDelayTimer->Start();
    autoDelayTimer->Reset();
    step = 0;
    autoShooterRpms = shooter->MaxRPM; // FIXME: Figure out this value

    //m_autoSelected = m_chooser.GetSelected();
    // m_autoSelected = SmartDashboard::GetString("Auto Selector",
    //     kAutoNameDefault);
    //std::cout << "Auto selected: " << m_autoSelected << std::endl;

    //if (m_autoSelected == kAutoNameCustom) {
        // Custom Auto goes here
    //} else {
        // Default Auto goes here
    //}
    oi->startDelay = oi->m_delay.GetSelected();
    switch (oi->startDelay) {
        case OI::Delay::ZERO:
            autoDelaySeconds = 0.0;
            std::cout << "No delay" << std::endl;
            break;
        case OI::Delay::ONE:
            autoDelaySeconds = 1.0;
            std::cout << "One second delay" << std::endl;
            break;
        case OI::Delay::TWO:
            autoDelaySeconds = 2.0;
            std::cout << "Two seconds delay" << std::endl;
            break;
        case OI::Delay::THREE:
            autoDelaySeconds = 3.0;
            std::cout << "Three seconds delay" << std::endl;
            break;
        case OI::Delay::FOUR:
            autoDelaySeconds = 4.0;
            std::cout << "Four seconds delay" << std::endl;
            break;
        case OI::Delay::FIVE:
            autoDelaySeconds = 5.0;
            std::cout << "Five seconds delay" << std::endl;
            break;
        case OI::Delay::SIX:
            autoDelaySeconds = 6.0;
            std::cout << "Six seconds delay" << std::endl;
            break;
        case OI::Delay::SEVEN:
            autoDelaySeconds = 7.0;
            std::cout << "Seven seconds delay" << std::endl;
            break;
        case OI::Delay::EIGHT:
            autoDelaySeconds = 8.0;
            std::cout << "Eight seconds delay" << std::endl;
            break;
        case OI::Delay::NINE:
            autoDelaySeconds = 9.0;
            std::cout << "Nine seconds delay" << std::endl;
            break;
        case OI::Delay::TEN:
            autoDelaySeconds = 10.0;
            std::cout << "Ten seconds delay" << std::endl;
            break;
        default:
            autoDelaySeconds = 0.0;
            std::cout << "WTF??? Unknown delay value entered" << std::endl;
            break;
    }

    oi->selectedPlay = oi->m_play.GetSelected();
    switch (oi->selectedPlay) {
        case OI::Play::DONOTHING:
            std::cout << "Twiddle thumbs play" << std::endl;
            break;
        case OI::Play::GETOFFTHELINE:
            std::cout << "Drive off the line play" << std::endl;
            break;
        case OI::Play::LEFTSHOOT:
            std::cout << "Shoot from the left side" << std::endl;
            break;
        case OI::Play::MIDDLESHOOT:
            std::cout << "Shoot from the middle" << std::endl;
            break;
        case OI::Play::RIGHTSHOOT:
            std::cout << "Shoot from the right side" << std::endl;
            break;
        case OI::Play::SHOOTANDGETBALLS:
            std::cout << "Shoot, get balls, solve world hunger" << std::endl;
            break;
        default:
            std::cout << "We are not tracking this play!!!!!" << std::endl;
            break;
    }
}

void Robot::AutonomousPeriodic() {
    //if (m_autoSelected == kAutoNameCustom) {
        // Custom Auto goes here
    //} else {
        // Default Auto goes here
    //}

    if (!autoDelayTimer->HasPeriodPassed(autoDelaySeconds)) {
        return;
    }

    switch (oi->selectedPlay) {
        case OI::Play::DONOTHING:
            switch (step) {
                case 0:
                    std::cout << "Doing nothing" << std::endl;
                    ++step;
                    break;
                default:
                    // DONE, nothing to do
                    break;
            }
            break;
        case OI::Play::GETOFFTHELINE:
            switch (step) {
                case 0:
                    std::cout << "Driving off the line" << std::endl;
                    drivingTimer->Start();
                    ++step;
                    break;
                case 1:
                    mobility->m_RobotDrive.TankDrive(0.5, 0.5, false);
                    drivingTimer->Reset();
                    ++step;
                    break;
                case 2:
                    if (drivingTimer->HasPeriodPassed(2.0)) {
                        mobility->m_RobotDrive.TankDrive(0.0, 0.0, false);
                        ++step;
                    }
                    break;
                case 3:
                    std::cout << "Driven off the line" << std::endl;
                    ++step;
                    break;
                default:
                    break;
            }
            break;
        case OI::Play::LEFTSHOOT:
            autoShooterRpms = shooter->MaxRPM;  // FIXME: Set to real desired value
            oi->selectedPlay = OI::Play::MIDDLESHOOT;
            break;
        case OI::Play::MIDDLESHOOT:
            switch (step) {
                case 0:
                    // FIXME: Do the stuff...
                    break;
                default:
                    break;
            }
            break;
        case OI::Play::RIGHTSHOOT:
            autoShooterRpms = shooter->MaxRPM;  // FIXME: Set to real desired value
            oi->selectedPlay = OI::Play::MIDDLESHOOT;
            break;
        default:
            switch (step) {
                case 0:
                    std::cout << "Need to implement play: " << oi->selectedPlay << std::endl;
                    ++step;
                    break;
                default:
                    break;
            }
            break;
    }
}

void Robot::TeleopInit() {}

void Robot::TeleopPeriodic() {
    Robot::compress->SetClosedLoopControl(true);
  
    while ((Robot::ds.IsOperatorControl()) && (Robot::ds.IsEnabled())) {
        try {
            oi->process();
        } catch (std::exception &e) {
            printf("Error in OI -- TeleopPeriodic\n%s", e.what());
        }

        try {
            mobility->process();
        } catch (std::exception &e) {
            printf("Error in Mobility -- TeleopPeriodic\n%s", e.what());
        }
    }
  
    if (!Robot::ds.IsEnabled()) {
        // Disable the closed loop compressor
        Robot::compress->SetClosedLoopControl(false);
    }
}

void Robot::TestPeriodic() {}

#ifndef RUNNING_FRC_TESTS
int main() { return frc::StartRobot<Robot>(); }
#endif
