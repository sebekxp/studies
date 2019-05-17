#include <iostream>
#include"fun.h"

int main()
{
	Player* playerOne = PlayerInit("Player One", 10, 0, 1);
	Player* playerTwo= PlayerInit("Player Two", 9, 1, 2);

	PlayerPrint(playerOne, "Specification Player One","John",playerOne->strenght);
	std::cout << "\n";
	PlayerPrint(playerTwo, "Specification Player Two","Lara",playerTwo->strenght);

	PlayerFree(playerOne);
	PlayerFree(playerTwo);

	std::cin.get();
	return 0;
}