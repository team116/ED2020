/**
 * Climber.h
 *
 *  Created on: Feb 05, 2020
 *      Author: Mike A.
 */
#ifndef SRC_CLIMBER_H_
#define SRC_CLIMBER_H_

#include <Ports.h>
#include <ctre/Phoenix.h>
#include <frc/Solenoid.h>
class ClimberEndEffector {
 public:
  static ClimberEndEffector* getInstance();

  void process();

  ClimberEndEffector() {
    WPI_VictorSPX Winch{RobotPorts::kWinchID};

    frc::Solenoid ClimberExtender{PCM0Ports::kClimberRelease};
  }

 private:
  static ClimberEndEffector* INSTANCE;
};

#endif /* SRC_CLIMBER_H_ */
