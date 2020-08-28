#include "Rectangle.h"
#include <iostream>

Rectangle::Rectangle(const char* name, Point p1, Point p2) : Figure2D(abs(p1.getX() - p2.getX()),
																abs(p1.getY() - p2.getY()),
																(p1.getX() < p2.getX()) ? p1.getX() : p2.getX(),
																(p1.getY() < p2.getY()) ? p1.getY() : p2.getY())
{
	this->setName(name);
}

Rectangle::Rectangle() : Figure2D() {}

Rectangle::Rectangle(const char* name, Point p1, double len) : Figure2D(len, len, p1.getX(), p1.getY()) { this->setName(name); }

Rectangle::~Rectangle() {}

double Rectangle::Area() const { return this->getHeight() * this->getLength(); }

double Rectangle::Perimeter() const { return 2 * this->getHeight() + 2 * this->getLength(); }

bool Rectangle::isInside(Figure2D* P) 
{
	return (P->getX() >= this->getX() && P->getX() <= this->getX() + this->getLength()
		&& P->getY() >= this->getY() && P->getY() <= this->getY() + this->getHeight());
}

void Rectangle::print() 
{
	cout << this->getName();
	cout << ": Point(" << this->getX() << ", " << this->getY();
	cout << ")-Point(" << this->getX() + this->getLength() <<
		", " << this->getY() + this->getHeight() << ")" << endl;

}

ostream& operator<<(ostream& o, Rectangle& d)
{
	d.print();
	return o;
}