#pragma once
#include <math.h>
using namespace std;
#include <iostream>


class Figure2D {
private:
	double x;
	double y;
	double length;
	double height;
	char* name = NULL;//=NULL Needed for compiler of the testing engine
public:
	Figure2D(double l, double h, double x = 0, double y = 0);
	Figure2D(Figure2D& f);
	Figure2D();
	virtual ~Figure2D();
	const Figure2D& operator=(Figure2D& d);
	void setName(const char*);
	double getX() const;
	double getY() const;
	double getLength() const;
	double getHeight() const;
	const char* getName();
	virtual double Area() const = 0;
	virtual double Perimeter() const = 0;
	void Shift(double dx, double dy);
	void MoveTo(double newX, double newY);
	void Resize(double newL, double newH);
	void Scale(double kx, double ky);
	virtual bool isInside(Figure2D* P) = 0;//Point(P->getX(),P->getY()) lies inside the figure
	virtual void print() = 0;
	friend ostream& operator<<(ostream& o, Figure2D& d);
};
