/**
 * OI.h
 *
 *  Created on: Feb 05, 2020
 *      Author: Mike A.
 */
#ifndef SRC_OI_H_
#define SRC_OI_H_

#include <ColorSpinner.h>
#include <Crawler.h>
#include <Climber.h>
#include <Feeder.h>
#include <Intake.h>
#include <Ports.h>
#include <Shooter.h>
#include <frc/DriverStation.h>
#include <frc/GenericHID.h>
#include <frc/Joystick.h>
#include <frc/buttons/JoystickButton.h>
#include <frc/buttons/POVButton.h>
#include <frc/XboxController.h>
#include <frc/shuffleboard/Shuffleboard.h>
#include <frc/shuffleboard/ShuffleboardTab.h>
#include <frc/smartdashboard/SendableChooser.h>
#include <frc/smartdashboard/SmartDashboard.h>

class OI {
   public:
    double x, y;
    volatile bool halfPower = false;

    frc::XboxController *xbox0;
    frc::Joystick *logitech0;

    // NOTE: Intake control buttons on Logitech joystick
    frc::JoystickButton *intakeRollerInButton;
    frc::JoystickButton *intakeRollerOutButton;
    frc::JoystickButton *intakeRollerOffButton1;
    frc::JoystickButton *intakeRollerOffButton2;

    // NOTE: Feeder control buttons on Logitech joystick are special POV/dpad
    frc::POVButton *feederUpPOVButton1;
    frc::POVButton *feederUpPOVButton2;
    frc::POVButton *feederUpPOVButton3;
    frc::POVButton *feederDownPOVButton1;
    frc::POVButton *feederDownPOVButton2;
    frc::POVButton *feederDownPOVButton3;

    // Shooter
    frc::JoystickButton *shooterWheelButton;

    // Climber
    frc::JoystickButton *climberControlsActiveButton;
    frc::JoystickButton *climberReleaseButton;

    // Solenoid control button
    frc::JoystickButton *turnOffAllSolenoidsButton;

    // ColorSpinner
    frc::JoystickButton *controlWheelExtendButton;
    frc::JoystickButton *controlWheelRetractButton;
    frc::JoystickButton *controlWheelNormalSpeedButton;
    frc::JoystickButton *controlWheelSlowSpeedButton;

    enum Pos { LEFT, CENTER, RIGHT };
    enum Dest {
        DONOTHING,
        LEFTSHOOT,
        RIGHTSHOOT,
        MIDDLESHOOT,
        GETOFFTHELINE,
        SHOOTANDGETBALLS
    };

    frc::SendableChooser<Pos> m_chooser;
    frc::SendableChooser<Dest> m_destination;

    IntakeEndEffector *intake;
    FeederEndEffector *feeder;
    ShooterEndEffector *shooter;
    ClimberEndEffector *climber;
    CrawlerEndEffector *crawler;
    ColorSpinnerEndEffector *colorSpinner;

    Pos startPosition;
    Dest destination;
 
#ifdef HASPIGEONIMU  // Do we have the pigeon IMU?
                     // Gyro Related
    bool userWantsToGoStraight;
    bool updateGains;
#endif

    static OI *getInstance();
    void process();
    void processClimber();
    void processFeeder();
    void processIntake();
    void processShooter();
    void processCrawler();
    void processMobility();
    void processColorSpinner();

   private:
    frc::DriverStation &ds = frc::DriverStation::GetInstance();
    OI();
    static OI *INSTANCE;

};

#endif /* SRC_OI_H_ */