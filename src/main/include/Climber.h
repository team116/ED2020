/**
 * Climber.h
 *
 *  Created on: Feb 05, 2020
 *      Author: Mike A.
 */
#ifndef SRC_CLIMBER_H_
#define SRC_CLIMBER_H_

class ClimberEndEffector {
 public:
  static ClimberEndEffector* getInstance();


 private:
  ClimberEndEffector();
  static ClimberEndEffector* INSTANCE;
};

#endif /* SRC_CLIMBER_H_ */
