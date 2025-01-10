#pragma once

#include <chrono>
#include <string>
#include <mutex>
#include <unordered_map>

namespace usb_cam
{
    class Timer
    {
        public:
            static void start(const std::string& name);
            static double stop(const std::string& name);
        
        private:
            static std::unordered_map<std::string, std::chrono::high_resolution_clock::time_point> timers;
            static std::mutex timer_mutex;
    };

}