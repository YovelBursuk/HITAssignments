#pragma once
#include "Square.h"
#include "Point.h"

class Circle : public Square {
private:
	const double pi = 3.1415926535897931;
public:
	Circle(const char*,Point, double);
	virtual ~Circle();
	double Area() const;
	double Perimeter() const;
	bool isInside(Figure2D* P);//Point(P->getX(),P->getY()) lies inside the figure
	void print();
	friend ostream& operator<<(ostream& o, Circle& d);
};
