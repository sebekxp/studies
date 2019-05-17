#include "Player.h"
int Player::staticID = 1;
Player::Player() {
    numID = staticID++;
}