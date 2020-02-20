/*
*   Created on: Some Day
*   By: Jess Wu
*
*/
#include <frc/drive/DifferentialDrive.h>
#include <Ports.h>
#include <Mobility.h>
#include <OI.h>
#include <ctre/Phoenix.h>

Mobility* Mobility::INSTANCE = nullptr;
Mobility::Mobility() {
    try {
      oi = OI::getInstance();
    } catch (std::exception& e) {
      // add some kind of error message that means something
    }
  }

Mobility* Mobility::getInstance() {
    if (INSTANCE == nullptr) {
        INSTANCE = new Mobility();
    }
    return INSTANCE;
}