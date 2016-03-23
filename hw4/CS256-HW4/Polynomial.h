// Cristian Avina-Lopez
// Homework 4
// 2/23/16
#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

#include <iostream>
#include <string>

class PolyTester;

class Polynomial
{
    friend class PolyTester;
	

private:
    //add your instance variables here
    int size;
    double *coeff;
public:
    //add yourfunction declarations here
    Polynomial();//default
	Polynomial(double[], int);
	Polynomial(const Polynomial& other);
	Polynomial(int n);
	Polynomial(double o);
	//operator =
	Polynomial& operator=(const Polynomial& right);
	//destructor
	~Polynomial();
	//helper functions
	int getSize() const;
	int degree() const;
	//
	std::string str() const;
	double solve(double) const;
	//[]
	double& operator[](int);
	//arithmetic operators
	Polynomial operator+(const Polynomial& p2) const;
	Polynomial operator-(const Polynomial& p2) const;
	Polynomial operator*(const Polynomial& p2) const;
	//overloaded * 
	Polynomial operator*(double x) const;
	Polynomial operator+=(const Polynomial& p2);
	Polynomial operator-=(const Polynomial& p2);
	Polynomial operator*=(const Polynomial& p2);



	//truth statements
	bool operator==(const Polynomial& p2) const;
	bool operator!=(const Polynomial& p2) const;



};

std::ostream& operator<<(std::ostream& os, const Polynomial& s);



#endif
