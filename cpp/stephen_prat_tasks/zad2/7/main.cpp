#include <iostream>
#include <iomanip>

using namespace std;

double const mila=1.609344;
double const galon=3.78541178;


int main()
{   double lp,a,b,lpP,c;
    cout << "Podaj zuzycie paliwa (litry/100km): ";
    cin>>lp;
    a=100/mila;
    b=lp/galon;

    cout<<setprecision(3)<<a/b<<" mile na galon"<<endl;

    cout << "Podaj zuzycie paliwa (mile na galon): ";
    cin>>lpP;
    double m=mila*lpP;
    cout<<setprecision(3)<<235.2/lpP<<" litry na 100km"<<endl;


    return 0;
}
