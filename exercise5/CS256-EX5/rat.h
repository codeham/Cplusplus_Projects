#ifndef RAT_H
#define RAT_H

#include <iostream>
#include <string>
#include <sstream>

class RatTester;

class rat
{
    friend class RatTester;

private:
    // declare private members here
    int num;
    int den;
	void reduce();
    
    
public:
    // declare public members here
    rat();
    rat(int);
    rat(int, int);
    //Getters
    int getNum() const{
	return num;
	}
	int getDen() const{
	return den;
	}
	rat reciprocal() const;
	//Arithmetic
	rat operator+(const rat& right) const;
	rat operator-(const rat& right) const;
	rat operator*(const rat& right) const;
    rat operator/(const rat& right) const;
    //rational operators
	bool operator==(const rat& right) const;
	bool operator!=(const rat& right) const;
	bool operator>(const rat& right) const;
	bool operator<(const rat& right) const;
	bool operator>=(const rat& right) const;
	bool operator<=(const rat& right) const;
	//String 
	std::string str() const;







};



#endif