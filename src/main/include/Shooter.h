/**
 * Shooter.h
 *
 *  Created on: Feb 05, 2020
 *      Author: Mike A.
 */
#ifndef SRC_SHOOTER_H_
#define SRC_SHOOTER_H_

class ShooterEndEffector {
 public:
  static ShooterEndEffector* getInstance();


 private:
  ShooterEndEffector();
  static ShooterEndEffector* INSTANCE;
};

#endif /* SRC_SHOOTER_H_ */