#include <iostream>
#include"player.h"
#include <string>

void playerFunc();

static int numPlayer;

int main()
{
	std::cout << "The number of player: ";
	std::cin >> numPlayer;
	if (!PlayerInit(numPlayer)) {
		PlayerFree();
		std::cout << "Error allocation\n";
		exit(1);
	}
	playerFunc();
	PlayerPrint();

	std::cin.get();
	std::cin.get();

	return 0;
}
void playerFunc() {
	Player newPlayer;
	memset(&newPlayer, 0, sizeof(Player));

	for (int i = 0; i < numPlayer; i++) {

		std::cout << i + 1 << " Player " << std::endl;
		while (getchar() != '\n');//czysci buffor

		std::cout << "Enter name: ";
		std::cin.getline(newPlayer.name,128);

		std::cout << "Enter strenght: ";
		std::cin >> newPlayer.strenght;

		std::cout << "Enter intelligence: ";
		std::cin >> newPlayer.intelligence;

		PlayerPush(newPlayer);
	}
}