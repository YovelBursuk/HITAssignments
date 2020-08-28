#include "Square.h"
#include <iostream>

Square::Square(const char* name, Point p1, Point p2) : Rectangle(name, p1, p2) {}
Square::Square(const char* name, Point p1, double len) : Rectangle(name,p1,len) {}
Square::Square() : Rectangle() {}
Square::~Square() {}
Square::Square(Square& sq) :Rectangle(sq.getName(),*(new Point(sq.getName(),sq.getX(),sq.getY())),sq.getLength()) {}
Point& Square::getCenter() const
{
	Point* p = new Point("center", this->getX() + 0.5 * this->getLength(), this->getY() + 0.5 * this->getHeight());
	return *p;
}
void Square::print() 
{
	Point p = this->getCenter();
	cout << "Square " << this->getName() << " with center (";
	cout << p.getX() << ", " << p.getY() << ") and side = " << this->getLength() << endl;
}

ostream& operator<<(ostream& o, Square& d)
{
	d.print();
	return o;
}

const Square& Square::operator=(Square& d)
{
	Figure2D::operator=(d);
	return *this;
}

double Square::Area() const
{
	return (this->getHeight() > this->getLength()) ? pow(this->getLength(), 2) : pow(this->getHeight(), 2);
}

double Square::Perimeter() const
{
	return (this->getHeight() > this->getLength()) ? 4*this->getLength() : 4*this->getHeight();
}

bool Square::isInside(Figure2D* P)
{
	double squareLen = (this->getHeight() > this->getLength()) ? this->getLength() : this->getHeight();
	squareLen *= 0.5;
	Point pCen = this->getCenter();
	return (P->getX() <= pCen.getX() + squareLen && P->getX() >= pCen.getX() - squareLen
		&& P->getY() <= pCen.getY() + squareLen && P->getY() >= pCen.getY() - squareLen);
		
}
