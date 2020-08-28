#pragma once
#include <iostream>
#include <string>
#include "polynomial.h"
using namespace std;

class rational
{
	// friend functions
	friend ostream& operator<<(ostream&, const rational&);

private:
	// members
	Polynomial* nom;
	Polynomial* denom;

public:
	// constructors
	rational(); // default constructor
	rational(Polynomial&, Polynomial&); // create rational object by given two polynoms

	// get/set methods
	Polynomial& getNom() const;
	Polynomial& getDenom() const;
	void setNom(Polynomial&);
	void setDenom(Polynomial&);

	// operator overloading
	rational& operator+(const rational&) const;
	rational& operator*(const rational&) const;

	// general functions
	void print() const;
	char* toString() const;
};

