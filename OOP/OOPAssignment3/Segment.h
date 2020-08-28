#pragma once
#include "Figure2D.h"
#include "Point.h"

class Segment : public Figure2D {
private:
	bool isMain;
public:
	Segment(const char*, Point, Point);
	virtual ~Segment();
	double Area() const;
	double Perimeter() const;
	bool isInside(Figure2D* P);//Point(P->getX(),P->getY()) lies inside the figure
	void print();
	friend ostream& operator<<(ostream& o, Segment& d);

};
