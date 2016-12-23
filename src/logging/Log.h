////
//// Created by aday on 12/15/2016.
////
//
//#ifndef DARWINGALACTIC_LOG_H
//#define DARWINGALACTIC_LOG_H
//
//#include <list>
//#include <string>
//#include <ctime>
//#include <queue>
//#include <unordered_map>
//#include <thread>
//#include <mutex>
//#include <condition_variable>
//
//class Log {
//private:
//    class Profile {
//    private:
//        std::string description;
//        std::list<std::pair<clock_t, std::string>> events;
//    public:
//        void addEvent(clock_t timestamp, std::string event);
//        String report();
//    };
//
//    bool done = false;
//
//    std::unordered_map<int, Profile> profiles;
//
//    std::queue<std::pair<int, std::pair<clock_t, std::string>>> waitingEvents;
//    std::mutex waitingEventsMutex;
//    std::condition_variable cv;
//
//    std::thread eventHandler;
//
//    static void handleEvents(Log& log);
//    static void requestEvent(std::pair<int, std::pair<clock_t, std::string>> event, Log& log);
//
//    void start();
//
//public:
//    Log();
//    ~Log();
//    void event(int id, clock_t timestamp, std::string event);
//};
//
//
//#endif //DARWINGALACTIC_LOG_H
