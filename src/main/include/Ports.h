/*
 * Ports.h
 *
 *  Created on: Feb 05, 2020
 *      Author: Mike A.
 */
#ifndef SRC_PORTS_H_
#define SRC_PORTS_H_
namespace RobotPorts {

    // Motor Controller Ports
    constexpr int kRightSide1 = 1; //Change all port values when decided on
    constexpr int kRightSide2 = 1;
    constexpr int kLeftSide1 = 1;
    constexpr int kLeftSide2 = 1;
    constexpr int kIntake = 1;
    constexpr int kWinch = 1;
    constexpr int kCrawler = 1;
    constexpr int kColorSpinner = 1;

    // CAN IDs *I think
    constexpr int kFeederID = 1;
    constexpr int kShooter1ID = 1;
    constexpr int kShooter2ID = 2;

}

namespace PCM0Ports {

    constexpr int kPCM0CANID = 1;
    constexpr int kIntakeFolderRelease = 1;
    constexpr int kIntakeFolderRetract = 1;
    constexpr int kShooterHoodExtend = 1;
    constexpr int kShooterHoodRetract = 1;
    constexpr int kClimberRelease = 1;
    constexpr int kColorSpinnerFolder = 1;
}
#endif /* SRC_PORTS_H_ */
