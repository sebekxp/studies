#include <iostream>

int main() {
	using namespace std;
	cout << "Podaj tekst do analizy, @ - konczy wpisywanie tekstu" << endl;
	char ch;

	int whitespace = 0;
	int digits = 0;
	int chars=0;
	int punct=0;
	int others = 0;

	cin.get(ch);
	while (ch != '@') {
		if (isalpha(ch))
			chars++;
		else if (isspace(ch))
			whitespace++;
		else if (isdigit(ch))
			digits++;
		else if (ispunct(ch))
			punct++;
		else
			others++;
		cin.get(ch);
	}

	cout << chars << " liter, " << whitespace << " bialych znakow, " << digits << " cyfr, " << punct << " znakow przestankowych, " << others << " innych znakow" << endl;

	system("pause");
	return 0;
}