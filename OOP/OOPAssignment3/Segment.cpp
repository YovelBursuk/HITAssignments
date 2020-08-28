#include "Segment.h"
#include <iostream>

Segment::Segment(const char* name, Point p1, Point p2) : Figure2D(abs(p1.getX() - p2.getX()),
															abs(p1.getY() - p2.getY()),
															(p1.getX() < p2.getX())?p1.getX():p2.getX(),
															(p1.getY() < p2.getY())?p1.getY():p2.getY())
{
	this->setName(name);
	double m = (p1.getY() - p2.getY()) / (p1.getX() - p2.getX());
	this->isMain = (m >= 0) ? true : false;
}

Segment::~Segment() {}

double Segment::Area() const { return 0; };

double Segment::Perimeter() const 
{
	return sqrt(pow(this->getLength(), 2) + pow(this->getHeight(), 2));
}

bool Segment::isInside(Figure2D* P) 
{
	return (P->getX() >= this->getX() && P->getX() <= this->getX() + this->getLength()
		&& P->getY() >= this->getY() && P->getY() <= this->getY() + this->getHeight());
}
void Segment::print() 
{
	cout << this->getName();

	if (this->isMain)
	{
		cout << ": Point(" << this->getX() << ", " << this->getY();
		cout << ")-Point(" << this->getX() + this->getLength() <<
			", " << this->getY() + this->getHeight() << ")" << endl;
	}
	else
	{
		cout << ": Point(" << this->getX() << ", " << this->getY() + this->getHeight();
		cout << ")-Point(" << this->getX() + this->getLength() <<
			", " << this->getY() << ")" << endl;
	}


}

ostream& operator<<(ostream& o, Segment& d)
{
	d.print();
	return o;
}