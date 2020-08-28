#pragma once
#include <iostream>
#include <string>
#include "polynomial.h"
using std::ostream;

class Rational
{
	// friend functions
	friend ostream& operator<<(ostream &, const Rational &);

private:
	// members
	Polynomial* nom;
	Polynomial* denom;

public:
	// constructors
	Rational(); // default constructor
	Rational(Polynomial&, Polynomial&); // create rational object by given two polynoms

	// get/set methods
	Polynomial& getNom() const;
	Polynomial& getDenom() const;
	void setNom(Polynomial &);
	void setDenom(Polynomial &);


	// general functions
	void print() const;
	char* toString() const;
};

