#define _CRT_SECURE_NO_WARNINGS
#include "rational.h"
#include <string>
#include <iostream>
using std::ostream;

Rational::Rational()
{
	this->nom = new Polynomial();
	this->denom = new Polynomial();
	this->denom->setCoeff(0, 1);
}

Rational::Rational(Polynomial& p1, Polynomial& p2)
{
	this->setNom(p1);
	this->setDenom(p2);
}

Polynomial& Rational::getNom() const
{
	return *(this->nom);
}

Polynomial& Rational::getDenom() const
{
	return *(this->denom);
}

void Rational::setNom(Polynomial& polynom)
{
	this->nom = &polynom;
}

void Rational::setDenom(Polynomial& polynom)
{
	this->denom = &polynom;
}

void Rational::print() const
{
	printf("%s", this->toString());
}

char * Rational::toString() const
{
	char* out = new char[100];

	sprintf(out, "%s--------------------------\n%s", 
		this->getNom().toString(), this->getDenom().toString());
	return out;
}

ostream & operator<<(ostream &output, const Rational &r)
{
	output << r.toString();
	return output;
}