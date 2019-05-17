#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    double km,lp;
    cout << "Liczba przejechanych km: ";
    cin>>km;
    cout << "Ilosc paliwa w litrach: ";
    cin>>lp;
    double utility=(lp/km)*100;
    cout<<"Spalanie: "<<setprecision(2)<<utility<<" litra na 100km"<<endl;

    return 0;
}
