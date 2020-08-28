#include "Circle.h"
#include <iostream>


Circle::Circle(const char* name, Point p1, double r) : Square(name, p1, 2 * r) { this->setName(name); }
Circle::~Circle() {}
double Circle::Area() const 
{
	return this->pi * (this->getLength() / 2) * (this->getLength() / 2);
}
double Circle::Perimeter() const 
{
	return this->pi * this->getLength();
}
bool Circle::isInside(Figure2D* P) 
{
	double dist = sqrt(pow(this->getX() - P->getX(), 2) + pow(this->getY() - P->getY(), 2));
	return (dist <= (this->getLength() / 2)) ? true : false;
}
void Circle::print() 
{
	Point p = this->getCenter();
	cout << "Circle " << this->getName() << " with center (";
	cout << p.getX() << ", " << p.getY() << ") and radius = " << this->getLength() / 2 << endl;
}

ostream& operator<<(ostream& o, Circle& d)
{
	d.print();
	return o;
}