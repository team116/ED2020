
/*
*   Created on: Some Day
*   By: Jess Wu
*
*/
#include <Intake.h>
#include <Ports.h>

IntakeEndEffector* IntakeEndEffector::INSTANCE = nullptr;
IntakeEndEffector::IntakeEndEffector() {
    try {
//      oi = OI::getInstance();
    } catch (std::exception& e) {
      // add some kind of error message that means something
    }
  }

  void IntakeEndEffector::intakeDeploy() {
    printf("Intake Deploying/n");
    m_IntakePiston.Set(frc::DoubleSolenoid::kForward);
}

void IntakeEndEffector::intakeRetract() {
    printf("Intake Rectracting/n");
    m_IntakePiston.Set(frc::DoubleSolenoid::kReverse);
}

void IntakeEndEffector::intakeOff() {
    m_IntakePiston.Set(frc::DoubleSolenoid::kOff);
}

void IntakeEndEffector::intakeMovement(Direction direction) {
    switch(direction) {
        // All speed values should be tweaked in testing (if time allows)
        case OFF:
            m_IntakeMotor.Set(0.0);
        break;

        case INTAKE:
            m_IntakeMotor.Set(0.5);
        break;

        case EJECT:
            m_IntakeMotor.Set(-0.5);
        break;

        default:
            frc::DriverStation::ReportError("In the Intake Default case");
        
    }
}


IntakeEndEffector* IntakeEndEffector::getInstance() {
    if (INSTANCE == nullptr) {
        INSTANCE = new IntakeEndEffector();
    }
    return INSTANCE;
}

