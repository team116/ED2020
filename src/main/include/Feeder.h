/**
 * Feeder.h
 *
 *  Created on: Feb 05, 2020
 *      Author: Mike A.
 */
#ifndef SRC_FEEDER_H_
#define SRC_FEEDER_H_

class FeederEndEffector {
 public:
  static FeederEndEffector* getInstance();


 private:
  FeederEndEffector();
  static FeederEndEffector* INSTANCE;
};

#endif /* SRC_FEEDER_H_ */