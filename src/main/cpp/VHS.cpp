#include <VHS.h>
#include <pthread.h>

VHS *VHS::INSTANCE = nullptr;

VHS::VHS() {
    try {
        intake = IntakeEndEffector::getInstance();
        feeder = FeederEndEffector::getInstance();
        shooter = ShooterEndEffector::getInstance();
        climber = ClimberEndEffector::getInstance();
        crawler = CrawlerEndEffector::getInstance();
        colorSpinner = ColorSpinnerEndEffector::getInstance();

        isInPlayback = false;
        isInRecording = false;
        exitSignal = nullptr;
        finishedSignal = nullptr;
    } catch (std::exception& e) {
        frc::DriverStation::ReportError("Error initializing object for OI");
        frc::DriverStation::ReportError(e.what());
    }
}

void VHS::startRecording(std::string filename) {
    if (isInRecording) {
        frc::DriverStation::ReportError("Already in recording, so not starting another");
        return;
    }

    if (isInPlayback) {
        frc::DriverStation::ReportError("In playback, refusing to start recording");
        return;
    }

    exitSignal = new std::promise<void>();
    std::future<void> futureObj = exitSignal->get_future();

    finishedSignal = new std::promise<void>();
    // Hopefully can get the future, because we cannot check the state otherwise...
    // For stopping, must not have any loops, need to ensure that we only set isInRecording = false when
    // we actually get notice that writing out the file is truly finished... might want to try a shared
    // mutex?
    
    isInRecording = true;
}

void VHS::stopRecording() {
    if (isInRecording) {
        frc::DriverStation::ReportError("Stopping Recording");
    }

    exitSignal = nullptr; // technically this is a tiny memory leak
    isInRecording = false;
}

void VHS::startPlayback(std::string filename) {
    if (isInPlayback) {
        frc::DriverStation::ReportError("In playback already, so stop before starting a new one");
        return;
    }

    if (isInRecording) {
        frc::DriverStation::ReportError("In a recording, refusing to start playback");
        return;
    }

    exitSignal = new std::promise<void>();
    std::future<void> futureObj = exitSignal->get_future();
    isInPlayback = true;
}

void VHS::stopPlayback() {
    if (isInPlayback) {
        frc::DriverStation::ReportError("Stopping Playback");
    }

    exitSignal = nullptr; // technically this is a tiny memory leak
    isInPlayback = false;
}

VHS *VHS::getInstance() {
    if (INSTANCE == nullptr) {
        INSTANCE = new VHS();
    }
    return INSTANCE;
}