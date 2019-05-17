#include <iostream>

int main() {
	using namespace std;
	//int liczba;
	//cout << "Podaj liczbe: ";
	//cin >> liczba;
	//if ((liczba < 10) and (liczba >= 1))
	//	cout << "liga" << endl;

	char ch;
	cout << "Pisz a ja bede powtarzac.\n";
	cin.get(ch);
	while (ch != '.') {
		if (ch == '\n')
			cout << ch;
		else
			cout << ch + 1;
		cin.get(ch);
	}
	
	system("pause");
	return 0;
}