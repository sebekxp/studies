#include <iostream>

using namespace std;

int main()
{
    //moze byc = ale nie musi
   int tab[] {1,4,5,6,7};
   int liczbaElementow=sizeof tab/sizeof tab[1];
   cout<<liczbaElementow<<endl;
   //Drugi sposob
   char ziom[]="Ziooooom";
   int licz=sizeof ziom/sizeof ziom[1];//lub sizeof(char)
   cout<<licz<<endl;
    return 0;
}
