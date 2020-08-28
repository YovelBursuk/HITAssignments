#pragma once
#include <iostream>
#include <string>
using namespace std;

class Polynomial
{
	// friend functions
	friend ostream& operator<<(ostream&, const Polynomial&);
	friend Polynomial& operator*(const double, const Polynomial&);

private:
	// members
	const unsigned int polynomDegree;
	double* coefficientArr;
	static int maxDegree;

	// private class methods
	void setCoeffArrValues(double*, int);
	void setMaxDegree();

public:
	// constructors
	Polynomial(); // default constructor
	Polynomial(int); // create polynom with given degree
	Polynomial(double*, int); // create polynom with given coeff

	// destructor
	~Polynomial();

	// get/set methods
	static int getMaxDegree();
	int getDegree(bool) const;
	void setCoeff(const int, const double);
	double* getCoeffArr() const;

	// operator overloading
	Polynomial& operator+(const Polynomial&) const;
	Polynomial& operator-(const Polynomial&) const;
	Polynomial& operator-() const;
	Polynomial& operator*(const Polynomial&) const;
	Polynomial& operator=(const Polynomial&);
	double& operator[](int);
	double operator[](int) const;

	// general functions
	char* toString() const;
};

