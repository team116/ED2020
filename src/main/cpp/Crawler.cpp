/*
*   Created on: 02/22/20
*   By: Mike A
*
*/
#include <frc/drive/DifferentialDrive.h>
#include <Ports.h>
#include <Crawler.h>

CrawlerEndEffector* CrawlerEndEffector::INSTANCE = nullptr;

CrawlerEndEffector* CrawlerEndEffector::getInstance() {
    if (INSTANCE == nullptr) {
        INSTANCE = new CrawlerEndEffector();
    }
    return INSTANCE;
}