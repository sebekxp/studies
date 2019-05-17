#ifndef UNTITLED_UTIL_H
#define UNTITLED_UTIL_H

#include <random>
#include <limits>

template<typename T>
T generateQuest() {
    std::random_device rd;
    std::mt19937 rng(rd());
    std::uniform_int_distribution<T> uid(std::numeric_limits<T>::lowest(), std::numeric_limits<T>::max());
    return uid(rng);
};

template<>
float generateQuest<float>() {
    std::random_device rd;
    std::mt19937 rng(rd());
    std::uniform_real_distribution<float> uid(std::numeric_limits<float>::min(), std::numeric_limits<float>::max());

    std::uniform_int_distribution<int> temp(0, 1);
    int sign = temp(rng) ? 1 : -1;

    return sign * uid(rng);

};
template<>
double generateQuest<double>() {
    std::random_device rd;
    std::mt19937 rng(rd());
    std::uniform_real_distribution<double> uid(std::numeric_limits<double>::min(), std::numeric_limits<double>::max());

    std::uniform_int_distribution<int> temp(0,1);
    int sign = temp(rng) ? 1 : -1;

    return sign * uid(rng);

};
template<>
long double generateQuest<long double>() {
    std::random_device rd;
    std::mt19937 rng(rd());
    std::uniform_real_distribution<long double> uid(std::numeric_limits<long double>::min(), std::numeric_limits<long double>::max());

    std::uniform_int_distribution<int> temp(0,1);
    int sign = temp(rng) ? 1 : -1;

    return sign * uid(rng);

};
#endif //UNTITLED_UTIL_H
