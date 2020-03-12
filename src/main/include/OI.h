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

// Uncomment to allow recording functions to be compiled in and used
#define SUPPORT_RECORDING

#ifdef SUPPORT_RECORDING
#include <VHS.h>
#endif

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

    enum Delay { ZERO,
                 ONE,
                 TWO,
                 THREE,
                 FOUR,
                 FIVE,
                 SIX,
                 SEVEN,
                 EIGHT,
                 NINE,
                 TEN};

    enum Play {
        DONOTHING,
        LEFTSHOOT,
        RIGHTSHOOT,
        MIDDLESHOOT,
        GETOFFTHELINE,
        SHOOTANDGETBALLS,
        PLAYBACK1,
        PLAYBACK2,
        PLAYBACK3
    };

    frc::SendableChooser<Delay> m_delay;
    frc::SendableChooser<Play> m_play;

    IntakeEndEffector *intake;
    FeederEndEffector *feeder;
    ShooterEndEffector *shooter;
    ClimberEndEffector *climber;
    CrawlerEndEffector *crawler;
    ColorSpinnerEndEffector *colorSpinner;

#ifdef SUPPORT_RECORDING
    VHS *vhs;
#endif // SUPPORT_RECORDING

    Delay startDelay;
    Play selectedPlay;
 
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
    void processRecording();

   private:
    frc::DriverStation &ds = frc::DriverStation::GetInstance();
    OI();
    static OI *INSTANCE;

};

#endif /* SRC_OI_H_ */