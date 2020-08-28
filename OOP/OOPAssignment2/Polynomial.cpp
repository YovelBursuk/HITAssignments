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

Polynomial::Polynomial(double* coeffArr, int degree) :polynomDegree(degree)
{
	this->coefficientArr = new double[degree + 1];

	this->setCoeffArrValues(coeffArr, degree);
	this->setMaxDegree();
}

Polynomial::~Polynomial()
{
	delete[] this->coefficientArr;
}

void Polynomial::setCoeffArrValues(double* coefArr, int degree)
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

double* Polynomial::getCoeffArr() const
{
	return this->coefficientArr;
}

char* Polynomial::toString() const
{
	char* out = new char[200];
	int i;

	sprintf(out, "polynomial = %g", this->coefficientArr[0]);

	for (i = 1; i <= this->getDegree(true); i++)
	{
		sprintf(out, "%s+(%g)*X^%d", out, this->coefficientArr[i], i);
	}

	sprintf(out, "%s\n", out);
	return out;
}

ostream& operator<<(ostream& output, const Polynomial& p)
{
	output << p.toString();
	return output;
}

Polynomial& operator*(const double multiplayer, const Polynomial& p)
{
	int degree = p.getDegree(false);
	int i;
	double* newCoeffs = new double[degree + 1];
	double* polynomCoeffs = p.getCoeffArr();
	Polynomial* temp;

	for (i = 0; i <= degree; i++)
	{
		newCoeffs[i] = polynomCoeffs[i] * multiplayer;
	}

	temp = new Polynomial(newCoeffs, degree);
	
	delete[] newCoeffs;
	return *temp;
}

Polynomial& Polynomial::operator+(const Polynomial& p1) const
{
	int i, firstDegree = p1.getDegree(false), secondDegree = this->getDegree(false);
	int maxPolynomsDegree = firstDegree > secondDegree ? firstDegree : secondDegree;
	double* sum = new double[maxPolynomsDegree + 1];
	double* firstCoeffs = p1.getCoeffArr(), * secondCoeffs = this->getCoeffArr();
	Polynomial* temp;

	for (i = 0; i <= maxPolynomsDegree; i++)
	{
		sum[i] = 0;
	}

	for (i = 0; i <= firstDegree; i++)
	{
		sum[i] = firstCoeffs[i];
	}

	for (i = 0; i <= secondDegree; i++)
	{
		sum[i] += secondCoeffs[i];
	}

	temp = new Polynomial(sum, maxPolynomsDegree);

	delete[] sum;
	return *temp;
}

Polynomial& Polynomial::operator-(const Polynomial& p1) const
{
	return *this + (-p1);
}

Polynomial& Polynomial::operator-() const
{
	int i, degree = this->getDegree(false);
	double* newCoeffs = new double[degree + 1];
	double* polynomCoeffs = this->getCoeffArr();
	Polynomial* temp;

	for (i = 0; i <= degree; i++)
	{
		newCoeffs[i] = 0 - polynomCoeffs[i];
	}

	temp = new Polynomial(newCoeffs, degree);
	delete[] newCoeffs;

	return *temp;
}

Polynomial& Polynomial::operator*(const Polynomial& p1) const
{
	int i, j, firstDegree = p1.getDegree(false), secondDegree = this->getDegree(false);
	double* prod = new double[firstDegree + secondDegree + 1];
	double* firstCoeffs = p1.getCoeffArr();
	double* secondCoeffs = this->getCoeffArr();
	Polynomial* temp;

	for (i = 0; i <= firstDegree + secondDegree; i++)
	{
		prod[i] = 0;
	}

	for (i = 0; i <= firstDegree; i++)
	{
		for (j = 0; j <= secondDegree; j++)
		{
			prod[i + j] += firstCoeffs[i] * secondCoeffs[j];
		}
	}

	temp = new Polynomial(prod, firstDegree + secondDegree);
	delete[] prod;

	return *temp;
}

Polynomial& Polynomial::operator=(const Polynomial& p)
{
	int thisDegree = this->getDegree(false);
	int pDegree = p.getDegree(false);
	double* ca = p.getCoeffArr();

	if (thisDegree < pDegree) 
	{
		this->setCoeffArrValues(NULL, pDegree);
		this->setCoeffArrValues(ca, thisDegree);
	}
	else 
	{
		this->setCoeffArrValues(NULL, thisDegree);
		this->setCoeffArrValues(ca, pDegree);
	}
	
	return *this;
}

double& Polynomial::operator[](int index)
{
	return this->coefficientArr[index];   
}

double Polynomial::operator[](int index) const
{
	return this->coefficientArr[index];
}
