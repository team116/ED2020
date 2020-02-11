/**
 * Author: Jess Wu
 * Created on: Some date
*/

#ifndef SRC_COLORSPINNER_H_
#define SRC_COLORSPINNER_H_

#include <Ports.h>
#include <ctre/Phoenix.h>
#include <frc/DoubleSolenoid.h>

class ColorSpinnerEndEffector{
    public:
        static ColorSpinnerEndEffector* getInstance();

        WPI_VictorSPX ColorSpinner{RobotPorts::kColorSpinner};

        DoubleSolenoid ColorSpinnerFolder{PCM0Ports::kColorSpinnerFolder}

    private:
};

#endif /*SRC_COLORSPINNER_H_*/