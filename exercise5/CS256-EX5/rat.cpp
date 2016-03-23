#include "rat.h"


rat::rat(){
	num = 0;
	den = 1;
}

rat::rat(int n){
	num = n;
	den = 1;
}

rat::rat(int n, int d){
	if ( d == 0 ){
		num = 0;
		den = 1;
	}else{
		num = n;
		den = d;
	} 
	reduce();
	
}

// These functions can be useful for calculations with fractions
int gcd(int x, int y)
{
    if (y == 0) 
        return x;
    return gcd(y, x % y);
}

int lcm(int x, int y)
{
    return (x * y) / gcd(x, y);
}

// Put your function implementations here

void rat::reduce()
{
	int g = gcd(num, den);
	num /= g;
	den /= g;
	if ( den < 0 )
	{
		num = -num;
		den = -den;
	}
}

rat rat::reciprocal() const
{
	rat x(this->getDen(), this->getNum());
	x.reduce();
	
	
	return x;
}

rat rat::operator+(const rat& right) const
{
	rat x;

     x.den = this->getDen() * right.getDen();
     x.num = right.getDen() * this->getNum() + this->getDen() * right.getNum();
     x.reduce();

	return x;


}

rat rat::operator-(const rat& right) const
{
	rat x;

     x.den = this->getDen() * right.getDen();
     x.num = right.getDen() * this->getNum() - this->getDen() * right.getNum();
     x.reduce();

	return x;
}

rat rat::operator*(const rat& right) const
{
	rat x; 
	x.num = this->getNum() * right.getNum();
	x.den = this->getDen() * right.getDen();
	x.reduce();

	return x;

}

rat rat::operator/(const rat& right) const
{
	rat x;
	x = right.reciprocal();

	x = operator*(x);

	return x;
	


}

bool rat::operator==(const rat& right) const
{
	if(this->getNum() == right.getNum() && this->getDen() == right.getDen())
	return true;
}

bool rat::operator!=(const rat& right) const
{
	if(operator==(right) != true)
	return true;
}

bool rat::operator>(const rat& right) const{
	if ( this->getNum() > right.getNum())
	return true;
}

bool rat::operator<(const rat& right) const{
	if (this->getNum() < right.getNum())
	return true;
}

bool rat::operator>=(const rat& right) const{
	if (operator>(right) == true || operator==(right) == true) 
	return true;
}

bool rat::operator<=(const rat& right) const{ 
	if (operator<(right) == true || operator==(right) == true) 	
	return true;
}

std::string rat::str() const{
	

	std::stringstream ss;
	ss << this->getNum() << "/" << this->getDen();
	return ss.str();
}




