#include "usb_cam/timing.hpp"
#include <chrono>

namespace usb_cam
{
    std::unordered_map<std::string, std::chrono::high_resolution_clock::time_point> Timer::timers;
    std::mutex Timer::timer_mutex;

    void Timer::start(const std::string& label){
        std::lock_guard<std::mutex> lock(timer_mutex);
        timers[label] = std::chrono::high_resolution_clock::now();
    }

    double Timer::stop(const std::string& label){
        std::lock_guard<std::mutex> lock(timer_mutex);
        auto end = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::duration<double>>(end - timers[label]);
        timers.erase(label);
        return duration.count();
    }

}