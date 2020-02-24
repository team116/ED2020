/**
 * Author: Jess Wu
 * Created on: Some date
 */

#ifndef SRC_COLORSPINNER_H_
#define SRC_COLORSPINNER_H_

#include <Ports.h>
#include <ctre/Phoenix.h>
#include <frc/DoubleSolenoid.h>

class ColorSpinnerEndEffector {
   public:
    static ColorSpinnerEndEffector* getInstance();

    void process();
    void launchPixyInterfaceThread();

    WPI_VictorSPX ColorSpinner{RobotPorts::kSpinnerID};
    frc::DoubleSolenoid ColorSpinnerFolder{PCM0Ports::kPCM0,
                                           PCM0Ports::kColorSpinnerExtend,
                                           PCM0Ports::kColorSpinnerRetract};

    ColorSpinnerEndEffector() {}

   private:
    static ColorSpinnerEndEffector* INSTANCE;
};

#endif /*SRC_COLORSPINNER_H_*/