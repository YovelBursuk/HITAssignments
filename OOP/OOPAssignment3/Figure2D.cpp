#include "Figure2D.h"
#include <string.h>

Figure2D::Figure2D(double l, double h, double x, double y)
{
	this->length = l;
	this->height = h;
	this->x = x;
	this->y = y;
}

Figure2D::Figure2D(Figure2D& f)
{
	this->length = f.getLength();
	this->height = f.getHeight();
	this->x = f.getX();
	this->y = f.getY();
}

Figure2D::Figure2D()
{
	this->length = 0;
	this->height = 0;
	this->x = 0;
	this->y = 0;
}

Figure2D::~Figure2D() {}

const Figure2D& Figure2D::operator=(Figure2D& d)
{
	this->length = d.getLength();
	this->height = d.getHeight();
	this->x = d.getX();
	this->y = d.getY();
	if (this->name != NULL)
		delete[] this->name;
	const char* n = d.getName();
	this->name = new char[strlen(n) + 1];
	strcpy(this->name, n);
	return *this;
}

void Figure2D::setName(const char* c)
{
	if (this->name != NULL)
		delete[] this->name;
	this->name = new char[strlen(c) + 1];
	strcpy(this->name, c);
}

double Figure2D::getX() const
{
	return this->x;
}

double Figure2D::getY() const
{
	return this->y;
}

double Figure2D::getLength() const
{
	return this->length;
}

double Figure2D::getHeight() const
{
	return this->height;
}

const char* Figure2D::getName()
{
	return this->name;
}

void Figure2D::Shift(double dx, double dy)
{
	this->x += dx;
	this->y += dy;
}

void Figure2D::MoveTo(double newX, double newY)
{
	this->x = newX;
	this->y = newY;
}

void Figure2D::Resize(double newL, double newH)
{
	this->length = (this->length)?newL:0;
	this->height = (this->height)?newH:0;
}

void Figure2D::Scale(double kx, double ky)
{
	if (this->height || this->length)
	{
		this->length *= kx;
		this->height *= ky;
	}
	else
	{
		this->x *= kx;
		this->y *= ky;
	}

}

ostream& operator<<(ostream& o, Figure2D& d)
{
	cout << d.getName() <<
		": x=" << d.getX() << ", y=" << d.getY() <<
		", length=" << d.getLength() << ", height=" <<
		d.getHeight();
	return o;
}
