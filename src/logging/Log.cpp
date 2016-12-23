////
//// Created by aday on 12/15/2016.
////
//
//#include "Log.h"
//
//void Log::Profile::addEvent(std::pair<clock_t, std::string> event) {
//    events.push_back(std::make_pair<clock_t, String>(timestamp, event));
//}
//
//std::string Log::Profile::report() {
//    for (auto event : events) {
//        // add event to report.
//    }
//    return "report";
//}
//
//void Log::handleEvents(Log& log) {
//    std::unique_lock<std::mutex> handlerMutex(waitingEventsMutex);
//    handlerMutex.lock();
//    while (!done || !waitingEvents.empty()) {
//        if (waitingEvents.empty()) {
//            cv.wait(handlerMutex);
//        }
//        else {
//            std::pair<int, std::pair<clock_t, std::string>> event = waitingEvents.pop();
//            profiles[event.first].addEvent(event.second);
//            handlerMutex.unlock();
//            handlerMutex.lock();
//        }
//    }
//    handlerMutex.unlock();
//}
//
//void Log::requestEvent(std::pair<int, std::pair<clock_t, std::string>> event, Log& log) {
//    std::unique_lock<std::mutex> requesterMutex(waitingEventsMutex);
//    requesterMutex.lock();
//    waitingEvents.push(event);
//    requesterMutex.unlock();
//    cv.notify_one();
//}
//
//void Log::start() {
//
//}
//
//Log::Log() {
//    eventHandler = std::thread(handleEvents);
//    eventHandler.detach();
//}
//
//Log::~Log() {
//    std::unique_lock<std::mutex> killerMutex(waitingEventsMutex);
//    killerMutex.lock();
//    done = true;
//    killerMutex.unlock();
//    cv.notify_one();
//
//}