#include <iostream>

using namespace std;
int change(int);
int main()
{
    int wiek;
    cout << "Podaj swoj wiek: ";
    cin>>wiek;
    cout<<"Twoj wiek w miesiacach wynosi: "<<change(wiek)<<endl;
    return 0;
}
int change(int wiek)
{
    return wiek*12;
}
