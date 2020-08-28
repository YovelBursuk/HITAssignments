#pragma once
#include "Figure2D.h"

class Point : public Figure2D {
public:
	Point(const char*, double, double);
	virtual ~Point();
	double Area() const;
	double Perimeter() const;
	bool isInside(Figure2D* P);//Point(P->getX(),P->getY()) lies inside the figure
	void print();
	friend ostream& operator<<(ostream& o, Point& d);

};