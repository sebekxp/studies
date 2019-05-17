#include <iostream>

using namespace std;

int const minn=60;
int const godz=3600;
int const day=86400;

int main()
{
    long long sek;
    int dni,godzz,minuty,sekundy;
    cout <<"Podaj liczbe sekund: ";
    cin>>sek;
    dni=sek/day;
    godzz=(sek-day*dni)/godz;
    minuty=(sek-(day*dni)-(godzz*godz))/minn;
    sekundy=sek-(day*dni)-(godzz*godz)-(minuty*minn);
    cout<<sek<<" = "<<dni<<" dni, "<<godzz<<" godzin, "<<minuty<<" minut, "<<sekundy<<" sekund"<<endl;
    return 0;
}
