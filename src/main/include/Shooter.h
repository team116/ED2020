/**
 * Shooter.h
 *
 *  Created on: Feb 05, 2020
 *      Author: Mike A.
 */
#ifndef SRC_SHOOTER_H_
#define SRC_SHOOTER_H_

#include "rev/CANSparkMax.h"
#include <Ports.h>
#include <frc/DoubleSolenoid.h>

class ShooterEndEffector {
 public:
  static ShooterEndEffector* getInstance();

  //rename these when design is more final

  rev::CANSparkMax m_Shooter1{RobotPorts::kShooter1ID,
   rev::CANSparkMax::MotorType::kBrushless};
  
  rev::CANSparkMax m_Shooter2{RobotPorts::kShooter2ID,
   rev::CANSparkMax::MotorType::kBrushless};

  frc::DoubleSolenoid ShooterHood{PCM0Ports::kPCM0CANID,
   PCM0Ports::kShooterHoodExtend,
   PCM0Ports::kShooterHoodRetract};


 private:
  ShooterEndEffector();
  static ShooterEndEffector* INSTANCE;
};

#endif /* SRC_SHOOTER_H_ */