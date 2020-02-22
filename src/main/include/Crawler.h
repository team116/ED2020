/**
 * Crawler.h
 *
 *  Created on: Feb 22, 2020
 *      Author: Mike A.
 */
#ifndef SRC_CRAWLER_H_
#define SRC_CRAWLER_H_

#include <Ports.h>
#include <ctre/Phoenix.h>

class CrawlerEndEffector {
 public:
  static CrawlerEndEffector* getInstance();

  CrawlerEndEffector() {
   WPI_VictorSPX Crawler{RobotPorts::kCrawlerID};   // Should be a NEO motor
  }

 private:
  static CrawlerEndEffector* INSTANCE;
};

#endif /* SRC_CRAWLER_H_ */