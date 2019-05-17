#ifndef FUNKTORY_SIMPLEINTERVALEXECUTOR_H
#define FUNKTORY_SIMPLEINTERVALEXECUTOR_H

#include <chrono>
#include <functional>
#include <vector>
#include <iostream>

class SimpleIntervalExecutor {
public:
    void register_f(std::function<void(std::chrono::system_clock::time_point)>,
                    std::chrono::milliseconds interval);

    void run();

private:
    std::vector<std::pair<std::function<void(std::chrono::system_clock::time_point)>, std::chrono::milliseconds>> queue;
};

class Useless {
public:
    void operator()(const std::string &nameFunction){
        static int i = 0;
        std::cout << nameFunction << ": " << i++ << std::endl;

    }
};

#endif //FUNKTORY_SIMPLEINTERVALEXECUTOR_H
