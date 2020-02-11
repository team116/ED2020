/*
*   Created on: Some Day
*   By: Jess Wu
*
*/

#include <Mobility.h>
#include <OI.h>

Mobility* Mobility::INSTANCE = nullptr;

Mobility::Mobility() {

    try {
        oi = OI.getInstance();
    } catch (std::exception& e) {
        //add some kind of error message that means something
    }
}

void Mobility::TankDrive(float left, float right) {
    m_RobotDrive.TankDrive(left,right);
}

Mobility* Mobility::getInstance() {
    if (INSTANCE == nullptr) {
        INSTANCE = new Mobility();
    }
    return INSTANCE;
}