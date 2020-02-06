/**
 * OI.h
 *
 *  Created on: Feb 05, 2020
 *      Author: Mike A.
 */
#ifndef SRC_OI_H_
#define SRC_OI_H_

class OI {
 public:
  static OI* getInstance();


 private:
  OI();
  static OI* INSTANCE;
};

#endif /* SRC_OI_H_ */