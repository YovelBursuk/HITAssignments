#pragma once
#include "Rectangle.h"
#include "Point.h"

class Square : public Rectangle {
public:
	Square(const char*, Point, Point);
	Square(const char*, Point, double);
	Square();
	Square(Square&);
	virtual ~Square();
	void print();
	virtual Point& getCenter() const;
	friend ostream& operator<<(ostream& o, Square& d);
	const Square& operator=(Square& d);
	double Area() const;
	double Perimeter() const;
	bool isInside(Figure2D* P);//Point(P->getX(),P->getY()) lies inside the figure
};
