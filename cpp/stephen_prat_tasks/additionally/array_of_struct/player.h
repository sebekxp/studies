#pragma once
#include <iostream>
#include <string>

struct Player {
	char name[128];
	double strenght;
	int intelligence;
};

int PlayerInit(const int numPlayer);
int PlayerPush(Player ptr);
void PlayerPrint();
void PlayerFree();