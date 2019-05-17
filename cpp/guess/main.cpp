#include <iostream>
#include "util.h"
#include "Quests.h"
#include "Player.h"

int main() {
////    std::cout << generateQuest<int>() << std::endl;
////    std::cout << generateQuest<int>() << std::endl;
////    std::cout << generateQuest<int>() << std::endl;
////    std::cout << generateQuest<int>() << std::endl;
////    std::cout << generateQuest<int>() << std::endl;
////    std::cout << generateQuest<int>() << std::endl;
////
////    std::cout << generateQuest<short>() << std::endl;
////    std::cout << generateQuest<short>() << std::endl;
////    std::cout << generateQuest<short>() << std::endl;
////    std::cout << generateQuest<short>() << std::endl;
////    std::cout << generateQuest<short>() << std::endl;
////
////    std::cout << (short)generateQuest<char>() << std::endl;
////    std::cout << (short)generateQuest<char>() << std::endl;
////    std::cout << (short)generateQuest<char>() << std::endl;
////    std::cout << (short)generateQuest<char>() << std::endl;
////    std::cout << (short)generateQuest<char>() << std::endl;
////
////    std::cout << generateQuest<float>() << std::endl;
////    std::cout << generateQuest<float>() << std::endl;
////    std::cout << generateQuest<float>() << std::endl;
////    std::cout << generateQuest<float>() << std::endl;
////    std::cout << generateQuest<float>() << std::endl;
////
////    std::cout << generateQuest<double>() << std::endl;
////    std::cout << generateQuest<double>() << std::endl;
////    std::cout << generateQuest<double>() << std::endl;
////    std::cout << generateQuest<double>() << std::endl;
////    std::cout << generateQuest<double>() << std::endl;
////    std::cout << generateQuest<double>() << std::endl;
////    std::cout << generateQuest<double>() << std::endl;
////
////    std::cout << generateQuest<long double>() << std::endl;
////    std::cout << generateQuest<long double>() << std::endl;
////    std::cout << generateQuest<long double>() << std::endl;
////    std::cout << generateQuest<long double>() << std::endl;
////    std::cout << generateQuest<long double>() << std::endl;
////    std::cout << generateQuest<long double>() << std::endl;
//
////    Quests<int> quests(3);
////    quests.newQuestion();
////    quests.newQuestion();
////    for(int i = 0; i < quests.size(); i++)
////        std::cout << quests[i] << std::endl;
////
////    std::cout << "---------------------------------" << std::endl;
////
////    Quests<int>::iterator iter = quests.begin();
////    auto iter2(iter);
////    for(;iter != quests.end(); iter++, ++iter2)
////        std::cout << *iter << std::endl << *iter2 << std::endl;

Player player;
Quests<int> questions(2);
////    player.feedback<int>(2);
////    player.feedback<char>(2);
////    player.feedback<double>(2);
////    player.feedback<float>(2);
////    player.feedback<long double>(2);
//
    short l = 0;
    for(auto it = questions.begin(); it != questions.end(); it++){
        player.feedback<int>(2);
        while (true) {
            l += 1;
            int answer = player.guess<int>();
            if (answer == *it)
                break;
            else if (answer > *it)
                player.feedback<int>(1);
            else
                player.feedback<int>(-1);
        }
    }
    std::cout << "Udało się! " << "Wykonano " << l << " kroków." << std::endl;
    std::cout << player.GetID() << std::endl;


    return 0;
}