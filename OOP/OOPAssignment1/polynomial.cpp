#define _CRT_SECURE_NO_WARNINGS
#include "polynomial.h"
#include <string>
#include <iostream>
using std::ostream;

int Polynomial::maxDegree = 0;

Polynomial::Polynomial() :polynomDegree(0)
{
	this->coefficientArr = new double[1];

	this->setCoeffArrValues(NULL, 0);
	this->setMaxDegree();
}

Polynomial::Polynomial(int degree) :polynomDegree(degree)
{
	this->coefficientArr = new double[degree + 1];

	this->setCoeffArrValues(NULL, degree);
	this->setMaxDegree();
}

Polynomial::Polynomial(double * coeffArr, int degree) :polynomDegree(degree)
{
	this->coefficientArr = new double[degree + 1];

	this->setCoeffArrValues(coeffArr, degree);
	this->setMaxDegree();
}

Polynomial::~Polynomial()
{
	delete[] this->coefficientArr;
}

void Polynomial::setCoeffArrValues(double * coefArr, int degree)
{
	// assumaing that degree param is valid
	// and is not out of array bounds
	int i;

	for (i = 0; i <= degree; i++)
	{
		this->coefficientArr[i] = coefArr == NULL ? 0 : coefArr[i];
	}
}

void Polynomial::setMaxDegree()
{
	int degree = this->getDegree(true);
	if (degree > maxDegree)
	{
		maxDegree = degree;
	}
}

int Polynomial::getMaxDegree()
{
	return maxDegree;
}

int Polynomial::getDegree(bool polyMaxDegreeFlag) const
{
	int i;

	if (!polyMaxDegreeFlag) 
	{
		return this->polynomDegree;
	}

	for (i = this->polynomDegree; i >= 0; i--)
	{
		if (this->coefficientArr[i] != 0)
		{
			return i;
		}
	}

	return 0;
}

void Polynomial::setCoeff(const int degree, const double coeff)
{
	this->coefficientArr[degree] = coeff;
}

double * Polynomial::getCoeffArr() const
{
	return this->coefficientArr;
}

char * Polynomial::toString() const
{
	char* out = new char[100];
	int i;

	sprintf(out, "polynomial = %g", this->coefficientArr[0]);

	for (i = 1; i <= this->getDegree(true); i++)
	{
		sprintf(out, "%s+%gX^%d", out, this->coefficientArr[i], i);
	}

	sprintf(out, "%s\n", out);
	return out;
}

ostream & operator<<(ostream &output, const Polynomial &p)
{
	output << p.toString();
	return output;
}