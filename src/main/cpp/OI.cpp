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
    xbox0 = new frc::XboxController(OIPorts::kXboxChannel);
    logitech0 = new frc::Joystick(OIPorts::kLogitechChannel);

    try {
        intake = IntakeEndEffector::getInstance();
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
        if (xbox0->GetBackButton()) {
            intake->intakeOff();
        } else {
            intake->intakeDeploy();
        }
    } else if (xbox0->GetBumper(frc::GenericHID::JoystickHand::kRightHand)) {
        if (xbox0->GetBackButton()) {
            intake->intakeOff();
        } else {
            intake->intakeRetract();
        }
    }

    if (someControl) {
        //       OI::intake->intakeMovement(IntakeEndEffector::Direction::OFF);
    } else if (someControl) {
        //       OI::intake->intakeMovement(IntakeEndEffector::Direction::INTAKE);
    } else if (someControl) {
        //       OI::intake->intakeMovement(IntakeEndEffector::Direction::EJECT);
    } else {
        //        OI::intake->intakeMovement(IntakeEndEffector::Direction::OFF);
    }
}

void OI::processShooter() {}

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