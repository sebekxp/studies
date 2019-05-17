#include "SimpleIntervalExecutor.h"
#include <iostream>
#include <thread>


void SimpleIntervalExecutor::register_f(std::function<void(std::chrono::system_clock::time_point)> fun,
                                        std::chrono::milliseconds interval) {
    queue.emplace_back(fun,interval);
}

void SimpleIntervalExecutor::run() {
    for(auto &it :queue){
        it.first(std::chrono::system_clock::now());
        std::this_thread::sleep_for(std::chrono::milliseconds(it.second));

    }
}
