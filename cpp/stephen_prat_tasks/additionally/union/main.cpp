#include <iostream>

void printInfo();

struct Test {
	char name[56];
	int type;
	union MyUnion
	{
		double number;
		char type[56];
	} MyUnionTemp;
};

static 	Test expm;

int main() {
	
	using namespace std;


	cout << "Enter the type of Struct: ";
	cin >> expm.type;
	while (getchar() != '\n');
	cout << "Enter the name of Struct: ";
	cin.getline(expm.name, 56);

	if (expm.type) {
		expm.MyUnionTemp.number = 10;
		cout << "Enter name of Union: ";
		cin.getline(expm.MyUnionTemp.type, 56);
		printInfo();
	}
	else {
		expm.MyUnionTemp.number = 0;
		cout << "Error, bad type of union" << endl;
		exit(1);
	}

	cin.get();
	return 0;
}

void printInfo() {
	using namespace std;
	cout << "Type of Struct: " << expm.type << endl;
	cout << "Name of Struct: " << expm.name << endl;
	cout << "Type of Union: " << expm.MyUnionTemp.number << endl;
	cout << "Name of Union: " << expm.MyUnionTemp.type << endl;
}