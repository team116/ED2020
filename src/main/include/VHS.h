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

    void recordingThread(std::string filename, std::future<void> exitFuture, std::promise<void> finishedPromise);

    void startRecording(std::string filename);
    void stopRecording();

    void startPlayback(std::string filename);
    void stopPlayback();

    void process();

    static VHS *getInstance();

    private:
    bool isStopping;
    bool isInRecording;
    bool isInPlayback;

    std::promise<void> *exitPromise;
    std::promise<void> *finishedPromise;

    VHS();
    static VHS *INSTANCE;
};

#endif