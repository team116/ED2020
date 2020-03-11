#ifndef SRC_VHS_H_
#define SRC_VHS_H_

#include <string>

#include <ColorSpinner.h>
#include <Crawler.h>
#include <Climber.h>
#include <Feeder.h>
#include <Intake.h>
#include <Shooter.h>
#include <frc/DriverStation.h>

#include <future>

class VHS {
    public:

    IntakeEndEffector *intake;
    FeederEndEffector *feeder;
    ShooterEndEffector *shooter;
    ClimberEndEffector *climber;
    CrawlerEndEffector *crawler;
    ColorSpinnerEndEffector *colorSpinner;

    void startRecording(std::string filename);
    void stopRecording();

    void startPlayback(std::string filename);
    void stopPlayback();

    static VHS *getInstance();

    private:
    bool isInRecording;
    bool isInPlayback;

    std::promise<void> *exitSignal;
    std::promise<void> *finishedSignal;

    VHS();
    static VHS *INSTANCE;
};

#endif