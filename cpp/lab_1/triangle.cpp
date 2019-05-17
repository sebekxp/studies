#include <cmath>
#include <iostream>
#include <vector>
#include <cstdio>
#include <sstream>
#include <string>
#include "triangle.h"

double Circle::area()
{
    return 3.14 * pow(getRadius(), 2);
};
void Circle::draw()
{
    std::cout << "Circle" << std::endl;
    std::cout << "Radius: " << this->getRadius() << std::endl;
    std::cout << "Area Circle: " << this->area() << std::endl;
    std::cout << "Size of the class Circle: " << sizeof(Circle) << std::endl;
    std::cout << "Middle of the wheel: " << p->print() << std::endl;
}
double Triangle::area()
{
    return (fabs(p1->getCrd(0) * p2->getCrd(1) + p2->getCrd(0) * p3->getCrd(1) - p1->getCrd(0) * p3->getCrd(1) - p3->getCrd(0) * p2->getCrd(1) - p2->getCrd(0) * p1->getCrd(1))) / 2;
};
void Triangle::draw()
{
    std::cout << "Triangle" << std::endl;
    std::cout << "Area Triangle: " << this->area() << std::endl;
    std::cout << "Size of the class Triangle: " << sizeof(Triangle) << std::endl;
    std::cout << "Vertex 1: " << p1->print() << std::endl;
    std::cout << "Vertex 2: " << p2->print() << std::endl;
    std::cout << "Vertex 3: " << p3->print() << std::endl;
}
double Rectangle::area()
{
    return (fabs(p5->getCrd(0) - p4->getCrd(0))) * (fabs((p7->getCrd(1) - p4->getCrd(1))));
};
void Rectangle::draw()
{
    std::cout << "Rectangle" << std::endl;
    std::cout << "Area Rectangle: " << this->area() << std::endl;
    std::cout << "Size of the class Rectangle: " << sizeof(Triangle) << std::endl;
    std::cout << "Vertex 1: " << p4->print() << std::endl;
    std::cout << "Vertex 2: " << p5->print() << std::endl;
    std::cout << "Vertex 3: " << p6->print() << std::endl;
    std::cout << "Vertex 4: " << p7->print() << std::endl;
};

double Square::area()
{
    Rectangle::area();
};

void Square::draw()
{

    std::cout << "Square" << std::endl;
    std::cout << "Area Square: " << this->area() << std::endl;
    std::cout << "Size of the class Square: " << sizeof(Triangle) << std::endl;
    std::cout << "Vertex 1: " << p4->print() << std::endl;
    std::cout << "Vertex 2: " << p5->print() << std::endl;
    std::cout << "Vertex 3: " << p6->print() << std::endl;
    std::cout << "Vertex 4: " << p7->print() << std::endl;
};

bool Square::hasGreaterArea(Polygon *e)
{
    Rectangle::hasGreaterArea(e);
};

bool Rectangle::hasGreaterArea(Polygon *e1)
{
    return this->area() > e1->area();
};

bool Circle::hasGreaterArea(Polygon *e2)
{
    return this->area() > e2->area();
};

bool Triangle::hasGreaterArea(Polygon *e3)
{
    return this->area() > e3->area();
};
