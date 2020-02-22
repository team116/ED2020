/**
 * Shooter.h
 *
 *  Created on: Feb 05, 2020
 *      Author: Mike A.
 */
#ifndef SRC_SHOOTER_H_
#define SRC_SHOOTER_H_

#include <Ports.h>
#include <frc/DoubleSolenoid.h>
#include "rev/CANSparkMax.h"

class ShooterEndEffector {
 public:
  static ShooterEndEffector* getInstance();

  ShooterEndEffector() {
    // rename these when design is more final
    rev::CANSparkMax m_Shooter1Motor{RobotPorts::kShooter1ID,
                                     rev::CANSparkMax::MotorType::kBrushless};

    rev::CANSparkMax m_Shooter2Motor{RobotPorts::kShooter2ID,
                                     rev::CANSparkMax::MotorType::kBrushless};

    frc::DoubleSolenoid m_ShooterHood{PCM0Ports::kPCM0CANID,
                                      PCM0Ports::kShooterHoodExtend,
                                      PCM0Ports::kShooterHoodRetract};

    // Initialize motors to factory defaults and set IdleMode
    m_Shooter1Motor.RestoreFactoryDefaults();
    m_Shooter2Motor.RestoreFactoryDefaults();
    m_Shooter1Motor.SetIdleMode(rev::CANSparkMax::IdleMode::kCoast);
    m_Shooter2Motor.SetIdleMode(rev::CANSparkMax::IdleMode::kCoast);

    // Have Shooter2 follow Shooter1 -- we only need to send commands to Shooter1
    m_Shooter2Motor.Follow(m_Shooter1Motor, true);

    try {
      //      oi = OI::getInstance();
    } catch (std::exception& e) {
      // add some kind of error message that means something
    }
  }

 private:
  static ShooterEndEffector* INSTANCE;
};

#endif /* SRC_SHOOTER_H_ */