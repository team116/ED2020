/**
 * OI.h
 *
 *  Created on: Feb 05, 2020
 *      Author: Mike A.
 */
#ifndef SRC_OI_H_
#define SRC_OI_H_

#include <Ports.h>
#include <frc/Joystick.h>


class OI {
 public:
  static OI* getInstance();
  void processMobility();

 private:
  OI();
  static OI* INSTANCE;
};

#endif /* SRC_OI_H_ */