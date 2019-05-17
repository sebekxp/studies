#ifndef TRIANGLEH
#define TRIANGLEH

#include <vector>
#include <exception>
#include <string>
#include <sstream>
#include <cstdio>
#include <cmath>

class Polygon
{
public:
  virtual double area() = 0;
  virtual void draw() = 0;
  virtual bool hasGreaterArea(Polygon *) = 0;
};
class vPoint
{
public:
  virtual double getCrd(int i) = 0;
  virtual std::string print() = 0;
  virtual double distance(vPoint&) = 0;
  virtual int getDim() = 0;

};

template <int nDim>
class Point : public vPoint
{
public:
  Point(){};
  Point(double x0, double x1) : X{x0, x1} {};
  Point(double x0, double x1, double x2) : X{x0, x1, x2} {};
  Point(double x0, double x1, double x2, double x3) : X{x0, x1, x2, x3} {};

  double getCrd(int i) { return X[i]; }
  int getDim() {return nDim;}

  double distance(vPoint& p2){
          if(nDim != p2.getDim())
          return -1;

      double sum = 0;

      for (int i = 0; i < nDim; i++) {
          sum += pow((X[i] - p2.getCrd(i)), 2);
      }
      return sqrt(sum);
  }
  std::string print(){
    std::stringstream ss;
    int n = 0;
    ss << "{ ";
    while(n<nDim){
      ss <<X[n]<<" ";
      n++;
    }
    ss << " }";
    return ss.str();
  }
private:
  double X[nDim];
};

class Circle : public Polygon
{
public:
  Circle(){};
  Circle(vPoint *p, double radius, int numVertex) : p(p), radius(radius), numVertex(numVertex) {}
  double getRadius() const { return radius; }

  void draw();
  double area();
  bool hasGreaterArea(Polygon *);


private:
  vPoint *p;
  double radius;
  int numVertex;
};
class Triangle : public Polygon {

public:
  Triangle(vPoint *p1, vPoint *p2, vPoint *p3) : p1(p1), p2(p2), p3(p3) {}
  
  void draw();
  double area();
  bool hasGreaterArea(Polygon *);


private:
  vPoint *p1;
  vPoint *p2;
  vPoint *p3;

};
class Rectangle : virtual public Polygon {

public:
  Rectangle(vPoint *p4, vPoint *p5, vPoint *p6, vPoint *p7) : p4(p4), p5(p5), p6(p6), p7(p7) {}

  void draw();
  double area();
  bool hasGreaterArea(Polygon *);


protected:
  vPoint *p4;
  vPoint *p5;
  vPoint *p6;
  vPoint *p7;
};

class Rhombus : virtual public Polygon 
{

  public:
  void draw() {};
  double area() {};

  bool hasGreaterArea(Polygon *) {};

};
class Square : public Rectangle, public Rhombus {

public:
  Square(vPoint *p8, vPoint *p9, vPoint *p10, vPoint *p11) 
  : Rectangle(p8,p9,p10,p11) {}  

  void draw();
  double area();

  bool hasGreaterArea(Polygon *);

};


#endif