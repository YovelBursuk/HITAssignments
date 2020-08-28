#pragma once
#include "Figure2D.h"
#include "Point.h"
using namespace std;

class Rectangle : public Figure2D {
public:
	Rectangle(const char*, Point, Point);
	Rectangle(const char*, Point, double);
	Rectangle();
	virtual ~Rectangle();
	double Area() const;
	double Perimeter() const;
	bool isInside(Figure2D* P);//Point(P->getX(),P->getY()) lies inside the figure
	void print();
	friend ostream& operator<<(ostream& o, Rectangle& d);

};