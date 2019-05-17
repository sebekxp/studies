#include <iostream>
#include "fun.h"
int main()
{
    Board objA , objB;
    
    int x, y, dx, dy, e, d;
    int tempD = 0;
    while (std::cin >> x >> y >> dx >> dy >> e >> d)
    {
        if(!checkData(x, y, dx, dy, e, d))
            continue;

        tempD = d;

        Effects *ptr;
        switch (e)
        {
        case 0: ptr = new ChangeToBlack;                break;
        case 1: ptr = new ChangeToWhite;                break;
        case 2: ptr = new ReverseState;                 break;
        case 3: ptr = new IfWhiteNotHave_2_3_Neighbors; break;
        case 4: ptr = new IfBlackHave_3_Neighbors;      break;
        case 5: ptr = new Effects_5;                    break;
        case 6: ptr = new Effects_6;                    break;
        }
        d ? ptr->apply(objB, x, y, dx, dy) : ptr->apply(objA, x, y, dx, dy);
    }
    tempD ? objB.showBoard() : objA.showBoard();
    return 0;
}