#include <iostream>

using namespace std;

const double a=60.0;
const double b=3600.0;




int main()
{
    int minuty,sekundy,stopnie;
    cout << "Podaj dlugosc w stopniach, minutach i sekundach:"<<endl;
    cout<<"Najpierw podaj stopnie: ";
    cin>>stopnie;
    cout<<"Nastepnie podaj minuty stopnia luku: ";
    cin>>minuty;
    cout<<"Na koniec podaj sekundy luku: ";
    cin>>sekundy;
    cout<<stopnie<<" stopni, "<<minuty<<" minut, "<<sekundy<<" sekund ="<<(double)(stopnie+minuty/a+sekundy/b)<<endl;

    return 0;
}
