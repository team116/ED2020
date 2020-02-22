/**
 * Feeder.h
 *
 *  Created on: Feb 05, 2020
 *      Author: Mike A.
 */
#ifndef SRC_FEEDER_H_
#define SRC_FEEDER_H_

#include <Ports.h>
#include "rev/CANSparkMax.h"

class FeederEndEffector {
 public:
  static FeederEndEffector* getInstance();

  void process();
  
  FeederEndEffector() {
    // Should be a NEO motor
    rev::CANSparkMax m_FeederMotor{RobotPorts::kFeederID,
                                   rev::CANSparkMax::MotorType::kBrushless};
                                   
    // Reset motor defaults and switch to Coast mode
    m_FeederMotor.RestoreFactoryDefaults();
    m_FeederMotor.SetIdleMode(rev::CANSparkMax::IdleMode::kCoast);

  }

 private:
  static FeederEndEffector* INSTANCE;
};

#endif /* SRC_FEEDER_H_ */