/**
 * Feeder.h
 *
 *  Created on: Feb 05, 2020
 *      Author: Mike A.
 */
#ifndef SRC_FEEDER_H_
#define SRC_FEEDER_H_

#include "rev/CANSparkMax.h"
#include <Ports.h>

class FeederEndEffector {
 public:
  static FeederEndEffector* getInstance();

// Should be a NEO motor. I think this works but not sure.
rev::CANSparkMax m_Feeder{RobotPorts::kFeederID, rev::CANSparkMax::MotorType::kBrushless} 

 private:
  FeederEndEffector();
  static FeederEndEffector* INSTANCE;
};

#endif /* SRC_FEEDER_H_ */