#include <iostream>
#include "SimpleIntervalExecutor.h"

typedef std::chrono::milliseconds mls;

void fun(std::chrono::system_clock::time_point time){

    std::cout<<"Elo"<<std::endl;
}

int main() {
    SimpleIntervalExecutor obj;
    Useless usl;
    usl("asd");

    auto a_fun = fun;
    auto b_fun = [](std::chrono::system_clock::time_point) { std::cout<<"Lambda 1"<<std::endl; };
    auto c_fun = [](std::chrono::system_clock::time_point) { std::cout<<"Lambda 2"<<std::endl; };
    auto d_fun = [](std::chrono::system_clock::time_point) { std::cout<<"Lambda 3"<<std::endl; };
    auto e_fun = [](std::chrono::system_clock::time_point) { std::cout<<"Lambda 4"<<std::endl; };
    auto f_fun = [](std::chrono::system_clock::time_point) { std::cout<<"Lambda 5"<<std::endl; };
    auto g_fun = [](std::chrono::system_clock::time_point) { std::cout<<"Lambda 6"<<std::endl; };
    auto h_fun = [](std::chrono::system_clock::time_point) { std::cout<<"Lambda 7"<<std::endl; };
    auto i_fun = [](std::chrono::system_clock::time_point) { std::cout<<"Lambda 8"<<std::endl; };

    obj.register_f(a_fun,mls(2000));
    obj.register_f(b_fun,mls(2000));
    obj.register_f(c_fun,mls(2000));
    obj.register_f(d_fun,mls(2000));
    obj.register_f(e_fun,mls(2000));
    obj.register_f(f_fun,mls(2000));
    obj.register_f(g_fun,mls(2000));
    obj.register_f(h_fun,mls(2000));
    obj.register_f(i_fun,mls(2000));


    obj.run();

    return 0;
}