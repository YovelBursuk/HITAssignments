#define _CRT_SECURE_NO_WARNINGS
#include "rational.h"
#include <string>
#include <iostream>
using std::ostream;

rational::rational()
{
	this->nom = new Polynomial();
	this->denom = new Polynomial();
	this->denom->setCoeff(0, 1);
}

rational::rational(Polynomial& p1, Polynomial& p2)
{
	this->setNom(p1);
	this->setDenom(p2);
}

Polynomial& rational::getNom() const
{
	return *(this->nom);
}

Polynomial& rational::getDenom() const
{
	return *(this->denom);
}

void rational::setNom(Polynomial& polynom)
{
	this->nom = &polynom;
}

void rational::setDenom(Polynomial& polynom)
{
	this->denom = &polynom;
}

rational& rational::operator+(const rational& r) const
{
	rational* temp;
	Polynomial* newDenom, *firstNom, *secondNom, *newNom;
	newDenom = new Polynomial(this->getDenom() * r.getDenom());
	firstNom = new Polynomial(this->getNom() * r.getDenom());
	secondNom = new Polynomial(this->getDenom() * r.getNom());
	newNom = new Polynomial(*firstNom + *secondNom);

	temp = new rational(*newNom, *newDenom);
	return *temp;
}

rational& rational::operator*(const rational& r) const
{
	rational* temp;
	Polynomial* newNom, * newDenom;
	newNom = new Polynomial(this->getNom() * r.getNom());
	newDenom = new Polynomial(this->getDenom() * r.getDenom());

	temp = new rational(*newNom, *newDenom);
	return *temp;
}

void rational::print() const
{
	printf("%s", this->toString());
}

char* rational::toString() const
{
	char* out = new char[400];

	sprintf(out, "%s--------------------------\n%s",
		this->getNom().toString(), this->getDenom().toString());
	return out;
}

ostream& operator<<(ostream& output, const rational& r)
{
	output << r.toString();
	return output;
}