#include <iostream>
#include "triangle.h"

int main()
{   
    //Circle
    vPoint *ptr = new Point<3>(280, 280, 200);
    Polygon *e1 = new Circle(ptr, 50, 75);
    e1->draw();
    std::cout << std::endl;

    //Triangle
    vPoint *ptr1 = new Point<3>(100, 100, 100);
    vPoint *ptr2 = new Point<3>(200, 200, 200);
    vPoint *ptr3 = new Point<3>(300, 300, 300);
    Polygon *e2 = new Triangle(ptr1, ptr2, ptr3);
    e2->draw();
    std::cout << std::endl;

    //Rectangle
    vPoint *ptr4 = new Point<3>(111, 180, 110);
    vPoint *ptr5 = new Point<3>(200, 100, 150);
    vPoint *ptr6 = new Point<3>(500, 500, 500);
    vPoint *ptr7 = new Point<3>(400, 400, 400);
    Polygon *e3 = new Rectangle(ptr4, ptr5, ptr6, ptr7);
    e3->draw();
    std::cout << std::endl;

    //Square
    vPoint *ptr8 = new Point<3>(100, 200, 110);
    vPoint *ptr9 = new Point<3>(300, 600, 160);
    vPoint *ptr10 = new Point<3>(300, 200, 500);
    vPoint *ptr11 = new Point<3>(444, 110, 422);
    Polygon *e4 = new Square(ptr8, ptr9, ptr10, ptr11);
    e4->draw();
    std::cout << std::endl;

    //Check the area of ​​the triangle and rectangle
    if (e3->hasGreaterArea(e2))
        std::cout << "Rectangle has greater area than Triangle" << std::endl;
    else
        std::cout << "Triangle has greater area than Rectangle " << std::endl;

    //Check the area of ​​the triangle and circle
    if (e1->hasGreaterArea(e2))
        std::cout << "Circle has greater area than Triangle" << std::endl;
    else
        std::cout << "Triangle has greater area than Circle" << std::endl;

    Point<4> pkt12(10, 0, 3, 5);
    Point<4> pkt13(0, 3, 0, 5);

    std::cout<<std::endl;
    std::cout << "Distance between pkt12 and pkt13 " << pkt12.distance(pkt13) << std::endl;

    return 0;
}