#include <iostream>
#include "validData.h"
#include <windows.h>

int readIntFromTo(int from, int to) {
	using namespace std;

	bool valid = false;
	int number;
	do {
		if (cin >> number && number >= from && number <= to)
			valid = true;
		else {
			cout << "Invalid input data :(\n";
			cout << "Try again :)\n" << endl;
		}
		cin.clear();
		cin.sync();
		while (getchar() != '\n');

	} while (!valid);

	return number;
}
int *readIntFromToBox(int from, int to) {
	using namespace std;

	bool valid = false;
	int nr[2];
	do {
		if (cin >> nr[0] && cin>>nr[1] && nr[0]>= from && nr[0] <= to && nr[1] >= from && nr[1] <= to)
			valid = true;
		else {
				cout << "\t\t\tInvalid input data :(\n";
				cout << "\t\t\tTry again :)\n" << endl;
		}
		cin.clear();
		cin.sync();
		while (getchar() != '\n');

	} while (!valid);

	return nr;
}