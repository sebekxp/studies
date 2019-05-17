#pragma once
#include <iostream>
#include <string>
struct Position
{
	double crd[2];
};
struct Player {
	std::string name;
	double strenght;
	Position* position;
};

Player* PlayerInit(std::string name, double strenght, double x, double y);
void PlayerPrint(Player* ptr, const std::string& title, const std::string& name, double strenght);
void PlayerFree(Player* ptr);