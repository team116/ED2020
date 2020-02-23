/*
 *   Created on: 02/22/20
 *   By: Mike A
 *
 */
#include <Crawler.h>
#include <Ports.h>
#include <frc/drive/DifferentialDrive.h>

CrawlerEndEffector* CrawlerEndEffector::INSTANCE = nullptr;

CrawlerEndEffector* CrawlerEndEffector::getInstance() {
    if (INSTANCE == nullptr) {
        INSTANCE = new CrawlerEndEffector();
    }
    return INSTANCE;
}

void CrawlerEndEffector::process() {}