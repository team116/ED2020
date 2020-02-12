/*
*   Created on: Some day at some point in time
*   By: Jess Wu
*
*/

#include <OI.h>


OI *OI::INSTANCE = nullptr;


void OI::processMobility() {
    
}

void OI::processClimber() {

}

OI::OI() {
    
}

OI *OI::getInstance() {
    if (INSTANCE == nullptr) {
        INSTANCE = new OI();
    }
    return INSTANCE;
}