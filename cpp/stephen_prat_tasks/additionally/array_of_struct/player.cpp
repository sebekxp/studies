#pragma once
#include "player.h"

static Player* player=NULL;
static size_t lastPosition = 0;

int PlayerInit(const int numPlayer) {
	player = new Player[numPlayer];
	if (!player)
		return NULL;
	memset(player, 0, numPlayer * sizeof(Player));
	return 1;
}

void PlayerFree() {
	if (player) {
		delete[] player;
		player = NULL;
	}
}

int PlayerPush(Player ptr) {
	strcpy(player[lastPosition].name, ptr.name);
	player[lastPosition].strenght = ptr.strenght;
	player[lastPosition].intelligence = ptr.intelligence;

	lastPosition++;

	return 0;
}

void PlayerPrint() {
	for (int i = 0; i < lastPosition; i++) {
		std::cout << "Name: " << player[i].name << std::endl;
		std::cout << "Strenght: " << player[i].strenght << std::endl;
		std::cout << "Intelligence: " << player[i].intelligence << std::endl;
	}
}
