/**
 * Mobility.h
 *
 *  Created on: Feb 05, 2020
 *      Author: Mike A.
 */
#ifndef SRC_MOBILITY_H_
#define SRC_MOBILITY_H_

class Mobility {
 public:
  static Mobility* getInstance();


 private:
  Mobility();
  static Mobility* INSTANCE;
};

#endif /* SRC_MOBILITY_H_ */