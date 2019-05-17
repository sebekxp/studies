#include <iostream>
using namespace std;
int zmiana(double);
int main()
{   double lat;
    cout << "Podaj liczbe lat swietlnych: ";
    cin>>lat;
    cout<<lat<<" lat swietlnych = "<<zmiana(lat)<<" jednostek astronomicznych"<<endl;
    return 0;
}
int zmiana(double rok)
{
    return rok*63240;
}
