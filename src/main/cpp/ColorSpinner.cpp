/*
 *   Created on: 02/22/20
 *   By: Mike A.
 *
 */
#include <ColorSpinner.h>
#include <Ports.h>
#include <ctre/Phoenix.h>

ColorSpinnerEndEffector* ColorSpinnerEndEffector::INSTANCE = nullptr;

ColorSpinnerEndEffector* ColorSpinnerEndEffector::getInstance() {
  if (INSTANCE == nullptr) {
    INSTANCE = new ColorSpinnerEndEffector();
  }
  return INSTANCE;
}

void ColorSpinnerEndEffector::process() {

}