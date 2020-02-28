/*
 *   Created on: Some day at some point in time
 *   By: Jess Wu
 *
 */

#include <OI.h>
// Get rid of some Control at some point and replace with the control OI uses
bool someControl = false;
OI *OI::INSTANCE = nullptr;

OI::OI() {
    try {
        xbox0 = new frc::XboxController(OIPorts::kXboxPort);
        logitech0 = new frc::Joystick(OIPorts::kLogitechPort);

        intake = IntakeEndEffector::getInstance();
        feeder = FeederEndEffector::getInstance();
        shooter = ShooterEndEffector::getInstance();
        climber = ClimberEndEffector::getInstance();
        crawler = CrawlerEndEffector::getInstance();
        colorSpinner = ColorSpinnerEndEffector::getInstance();

        intakeRollerInButton = new frc::JoystickButton(logitech0, OIPorts::kIntakeRollerInButtonNum);
        intakeRollerOutButton = new frc::JoystickButton(logitech0, OIPorts::kIntakeRollerOutButtonNum);
        intakeRollerOffButton1 = new frc::JoystickButton(logitech0, OIPorts::kIntakeRollerOffButtonNum1);
        intakeRollerOffButton2 = new frc::JoystickButton(logitech0, OIPorts::kIntakeRollerOffButtonNum2);

        feederUpPOVButton1 = new frc::POVButton(*logitech0, 0);
        feederUpPOVButton2 = new frc::POVButton(*logitech0, 45);
        feederUpPOVButton3 = new frc::POVButton(*logitech0, 315);

        feederDownPOVButton1 = new frc::POVButton(*logitech0, 180);
        feederDownPOVButton2 = new frc::POVButton(*logitech0, 135);
        feederDownPOVButton3 = new frc::POVButton(*logitech0, 225);

        shooterWheelButton = new frc::JoystickButton(logitech0, OIPorts::kShooterWheelButtonNum);

        climberControlsActiveButton = new frc::JoystickButton(logitech0, OIPorts::kClimberControlsActiveButtonNum);
        climberReleaseButton = new frc::JoystickButton(logitech0, OIPorts::kClimberReleaseButtonNum);

        turnOffAllSolenoidsButton = new frc::JoystickButton(logitech0, OIPorts::kTurnOffAllSolenoidsButtonNum);

        controlWheelExtendButton = new frc::JoystickButton(logitech0, OIPorts::kControlWheelExtendButtonNum);
        controlWheelRetractButton = new frc::JoystickButton(logitech0, OIPorts::kControlWheelRetractButtonNum);
        controlWheelNormalSpeedButton = new frc::JoystickButton(logitech0, OIPorts::kControlWheelNormalSpeedButtonNum);
        controlWheelSlowSpeedButton = new frc::JoystickButton(logitech0, OIPorts::kControlWheelSlowSpeedButtonNum);

    } catch (std::exception& e) {
        frc::DriverStation::ReportError("Error initializing object for OI");
        frc::DriverStation::ReportError(e.what());
    }
}

void OI::processMobility() {
    double leftSpeed = -xbox0->GetY(frc::GenericHID::JoystickHand::kLeftHand);
    double rightSpeed = -xbox0->GetY(frc::GenericHID::JoystickHand::kRightHand);

    x = leftSpeed * leftSpeed * leftSpeed;
    y = rightSpeed * rightSpeed * rightSpeed;

    if (xbox0->GetBumper(frc::GenericHID::JoystickHand::kLeftHand)) {
        x = x / 2.0;
        y = y / 2.0;
    }
}

void OI::processClimber() {
    if (climberControlsActiveButton->Get()) {
        double winchVelocity = logitech0->GetY();
        if ((winchVelocity > 0.1) || (winchVelocity < -0.1)) {
            climber->runWinch(winchVelocity);
        } else {
            climber->stopWinch();
        }

        double crawlerVelocity = logitech0->GetZ();
        if (crawlerVelocity > 0.9) {
            crawler->moveRight();
        } else if (crawlerVelocity < -0.9) {
            crawler->moveLeft();
        } else {
            crawler->stop();
        }

        if (climberReleaseButton->Get()) {
            climber->releaseClimber();
        }
    } else {
        climber->stopWinch();
        climber->turnSolenoidOff();
        crawler->stop();
    }

    if (turnOffAllSolenoidsButton->Get()) {
        climber->turnSolenoidOff();
    }
}

void OI::processFeeder() {
    if (feederUpPOVButton1->Get() || feederUpPOVButton2->Get() || feederUpPOVButton3->Get()) {
        feeder->feederPID(-100.0);  // Supply desired RPM with sign and negative is "UP"
    } else if (feederDownPOVButton1->Get() || feederDownPOVButton2->Get() || feederDownPOVButton3->Get()) {
        feeder->feederPID(100.0);
    } else {
        feeder->feederPID(0.0);  // Zero RPMs
    }
}

void OI::processIntake() {
    // Intake Piston Controls
    // P2 defaults to Y and P4 defaults to X buttons on xbox 
    if (xbox0->GetYButton()) {
        intake->intakeDeploy();
    } else if (xbox0->GetXButton()) {
        intake->intakeRetract();
    }

    // NOTE: Use back button as convention to turn off piston
    if (xbox0->GetBackButton()) {
        intake->intakeOff();
    }

    if (intakeRollerInButton->Get()) {
        intake->intakeMovement(IntakeEndEffector::Direction::INTAKE);
    } else if (intakeRollerOutButton->Get()) {
        intake->intakeMovement(IntakeEndEffector::Direction::EJECT);
    } else if (intakeRollerOffButton1->Get() || intakeRollerOffButton2->Get()) {
        intake->intakeMovement(IntakeEndEffector::Direction::OFF);
    }
}

void OI::processShooter() {
    if (shooterWheelButton->Get()) {
        // throttle is like y axis, so down 1.0 to up -1.0 and then we transform to 0.0 - 1.0
        double throttlePercentage = (-(logitech0->GetRawAxis(3)) + 1.0) / 2.0;
        shooter->shooterPID(throttlePercentage * shooter->MaxRPM);
    } else {
        shooter->shooterPID(0.0); // Turn it off
    }
}

void OI::processColorSpinner() {
    if (controlWheelExtendButton->Get()) {
        colorSpinner->extend();
    } else if (controlWheelRetractButton->Get()) {
        colorSpinner->retract();
    }

    if (controlWheelNormalSpeedButton->Get()) {
        colorSpinner->spinNormalSpeed();
    } else if (controlWheelSlowSpeedButton->Get()) {
        colorSpinner->spinSlowSpeed();
    } else {
        colorSpinner->stopSpinning();
    }

    if (turnOffAllSolenoidsButton->Get()) {
        colorSpinner->turnOffSolenoid();
    }
}

void OI::process() {
    // processes all different parts if the robot.
    processMobility();
    processFeeder();
    processClimber();
    processIntake();
    processShooter();
    processColorSpinner();
}

OI *OI::getInstance() {
    if (INSTANCE == nullptr) {
        INSTANCE = new OI();
    }
    return INSTANCE;
}