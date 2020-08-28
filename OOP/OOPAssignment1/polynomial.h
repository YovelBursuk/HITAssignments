#pragma once
#include <iostream>
#include <string>
using std::ostream;

class Polynomial
{
	// friend functions
	friend ostream& operator<<(ostream &, const Polynomial &);

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
	double * getCoeffArr() const;


	// general functions
	char* toString() const;
};

