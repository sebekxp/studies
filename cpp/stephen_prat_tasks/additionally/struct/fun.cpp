#pragma once
#include "fun.h"



Player* PlayerInit(std::string name, double strenght, double x, double y) {
	Player* player = new Player;
	if (!player)
		return NULL;
	player->position = new Position[2];
	if (!player->position)
		return NULL;

	//Position Initialization
	player->position[0].crd[0] = x;
	player->position[0].crd[1] = y;

	player->position[1].crd[0] = x+1;
	player->position[1].crd[1] = y+2;

	//Strenght Initialization
	player->strenght = strenght;

	//Name Initialization
	player->name = name;

	return player;
}
void PlayerPrint(Player* ptr, const std::string& title,const std::string& name,double strenght) {

	std::cout << title << std::endl;
	std::cout << "Name: "<<name << std::endl;
	std::cout << "Strenght: " << strenght << std::endl;
	for (int i = 0; i < 2; i++) {
		std::cout << "Position "<<i<<": ";
		for (int j = 0; j < 2; j++) {
			std::cout <<"[" << ptr->position[i].crd[j] << "]";
		}
		std::cout << "\n";
	}
 }
void PlayerFree(Player* ptr) {
	if (ptr) {
		delete[] ptr->position;
		ptr->position = NULL;
		delete ptr;
		ptr = NULL;
	}
}
