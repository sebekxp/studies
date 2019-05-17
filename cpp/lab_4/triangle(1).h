#ifndef TRIANGLEH
#define TRIANGLEH

#include <vector>
#include <exception>
#include <string>
#include <cstdio>


class Polygon {

public:

virtual void draw() = 0;
virtual double area() = 0;
virtual bool hasGreaterArea(Polygon *) = 0;

};


class Point {

public:
  Point(double x, double y) : x(x), y(y) {}
  double getX() const { return x; }
  double getY() const { return y; }

private:
  const double x;
  const double y;

};


class Circle : public Polygon {

public:
  Circle(Point p, double radius, int numVertex) : p(p), radius(radius), numVertex(numVertex) {}

  Point getP() const { return p; }
  double getRadius() const { return radius; }

  void draw();
  double area();

  bool hasGreaterArea(Polygon *);

private:
  const Point p;
  const double radius;
  const int numVertex;

};



class Rectangle : virtual public Polygon {

public:
  Rectangle(Point p4, Point p5, Point p6, Point p7) : p4(p4), p5(p5), p6(p6), p7(p7) {}
  Point getA() const { return p4; }
  Point getB() const { return p5; }
  Point getC() const { return p6; }
  Point getD() const { return p7; }

  void draw();
  double area();

  bool hasGreaterArea(Polygon *);

private:
  const Point p4;
  const Point p5;
  const Point p6;
  const Point p7;

};




class Triangle : public Polygon {

public:
  Triangle(Point p1, Point p2, Point p3) : p1(p1), p2(p2), p3(p3) {}
  Point getA() const { return p1; }
  Point getB() const { return p2; }
  Point getC() const { return p3; }

  void draw();
  double area();

  bool hasGreaterArea(Polygon *);

private:
  const Point p1;
  const Point p2;
  const Point p3;

};




class Rhombus : virtual public Polygon {

  public:
  void draw() {};
  double area() {};

  bool hasGreaterArea(Polygon *) {};

};




class Square : public Rectangle, public Rhombus {

public:
  Square(Point p9, Point p10, Point p11, Point p12) 
  : Rectangle(p9,p10,p11,p12) {}  

  void draw();
  double area();

  bool hasGreaterArea(Polygon *);

};


class Factory {

  public:
  ~Factory();
  void createFigure(int);
  void printArr();
  double getSum();
  Polygon* createCircle();
  Polygon* createSquare();
  Polygon* createSquare(int, int);
  

  private:
  double sum = 0;

  std::vector<Polygon*> arr;

};


class WrongInputException : public std::exception {

  public:
  WrongInputException() : message("No message") {};
  WrongInputException(std::string msg) : message(msg) {};
  const char* what() const throw();


  private:
  std::string message;

};


class CFile {

  public:
  CFile(const char*);
  ~CFile();
  void write(std::string);

  private:
  FILE* file;

};


#endif