#include <iostream>

using namespace std;

void go(int,int);
int main()
{
    int godz,minuty;
    cout << "Podaj liczbe godzin: ";
    cin>>godz;
    cout << "Podaj liczbe minut: ";
    cin>>minuty;
    go(godz,minuty);

    return 0;
}
void go(int godz,int minuty)
{
    cout<<"Czas: "<<godz<<":"<<minuty;
}
