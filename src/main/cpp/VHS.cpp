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

        isStopping = false;
        isInPlayback = false;
        isInRecording = false;
        exitPromise = nullptr;
        finishedPromise = nullptr;
    } catch (std::exception& e) {
        frc::DriverStation::ReportError("Error initializing object for OI");
        frc::DriverStation::ReportError(e.what());
    }
}

void VHS::recordingThread(std::string filename, std::future<void> exitFuture, std::promise<void> finishedPromise) {
    frc::DriverStation::ReportError("Thread has started");

    while (exitFuture.wait_for(std::chrono::milliseconds(1)) == std::future_status::timeout)
	{
        // Do nothing, as we'll be doing it a lot
    }

    frc::DriverStation::ReportError("Sweet, we finished");

    // FIXME: Just for testing
    std::this_thread::sleep_for(std::chrono::milliseconds(2000));

    frc::DriverStation::ReportError("Let stop process know");

    finishedPromise.set_value();
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

    exitPromise = new std::promise<void>();
    std::future<void> exitFuture = exitPromise->get_future();

    finishedPromise = new std::promise<void>();
    // Hopefully can get the future, because we cannot check the state otherwise...
    // For stopping, must not have any loops, need to ensure that we only set isInRecording = false when
    // we actually get notice that writing out the file is truly finished... might want to try a shared
    // mutex?

    std::thread th(&VHS::recordingThread, VHS::getInstance(), filename, std::move(exitFuture), std::move(*finishedPromise));
    th.detach();
    
    isInRecording = true;
}

void VHS::stopRecording() {
    if (isInRecording) {
        if (!isStopping) {
            frc::DriverStation::ReportError("Stopping Recording");
            isStopping = true;
        }
    } else {
        frc::DriverStation::ReportError("Not recording, so ignoring stop request");
    }
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

    exitPromise = new std::promise<void>();
    std::future<void> futureObj = exitPromise->get_future();

    isInPlayback = true;
}

void VHS::stopPlayback() {
    if (isInPlayback) {
        frc::DriverStation::ReportError("Stopping Playback");
    
        exitPromise = nullptr; // technically this is a tiny memory leak
        isInPlayback = false;
    } else {
        frc::DriverStation::ReportError("Not in playback, so ignoring stop reequest");
    }
}

void VHS::process() {
    if (isStopping) {
        std::future<void> finishedFuture = finishedPromise->get_future();
        if (finishedFuture.wait_for(std::chrono::milliseconds(1)) != std::future_status::timeout)
        {
            frc::DriverStation::ReportError("Awesome we are stopped!");
            isStopping = false;
            isInPlayback = false;
            isInRecording = false;
            exitPromise = nullptr;
            finishedPromise = nullptr;
        }
    }
}

VHS *VHS::getInstance() {
    if (INSTANCE == nullptr) {
        INSTANCE = new VHS();
    }
    return INSTANCE;
}