#include "Point.h"
#include <iostream>

Point::Point(const char* name, double x, double y) : Figure2D(0, 0, x, y) { this->setName(name); }

Point::~Point() { }

double Point::Area() const { return 0; }

double Point::Perimeter() const { return 0; }

bool Point::isInside(Figure2D* P)
{
	return (this->getX() == P->getX() && this->getY() == P->getY());
}

void Point::print()
{
	cout << this->getName();
	cout << ": (" << this->getX() << ", " << this->getY() << ")" << endl;
}

ostream& operator<<(ostream& o, Point& d)
{
	d.print();
	return o;
}