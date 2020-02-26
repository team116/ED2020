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
}

void OI::processClimber() {}

void OI::processFeeder() {}

void OI::processIntake() {
    // Intake Piston Controls
    if (xbox0->GetBumper(frc::GenericHID::JoystickHand::kLeftHand)) {
        intake->intakeDeploy();
    } else if (xbox0->GetBumper(frc::GenericHID::JoystickHand::kRightHand)) {
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

}

void OI::process() {
    // processes all different parts if the robot.
    OI::processMobility();
    OI::processFeeder();
    OI::processClimber();
    OI::processIntake();
    OI::processShooter();
}

OI *OI::getInstance() {
    if (INSTANCE == nullptr) {
        INSTANCE = new OI();
    }
    return INSTANCE;
}