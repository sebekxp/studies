#include <iostream>

int main() {
	using namespace std;
	const int Arsize = 80;
	char line[Arsize];

	int spaces = 0;
	cin.getline(line, Arsize);
	for (int i = 0; line[i] != '\0'; i++) {
		cout << line[i];
		if (line[i] == '.')
			break;
		if (line[i] != ' ')
			continue;
		spaces++;
	}

	cout << spaces << endl;

	system("pause");
	return 0;
}