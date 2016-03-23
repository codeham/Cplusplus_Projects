// Cristian Avina-Lopez
// Homework 4
// 2/23/16
#include <sstream>
#include <cmath>
#include "Polynomial.h"
#include <stdio.h>      /* printf */
#include <math.h>       /* fabs */

// provide your function implementations here
Polynomial::Polynomial()
{
	coeff = new double[1];
	coeff[0] = 0;
	size = 1;
}

Polynomial::Polynomial(double arr[], int newSize)
{
	coeff = new double [newSize];
	for ( int i = 0; i < newSize; i++ )
	{
		coeff[i] = arr[i];
	}
	size = newSize;
}

Polynomial::Polynomial(const Polynomial& other):
coeff(new double[other.size]), size(other.size)
{
	for ( int i = 0; i < size; i++ )
	{
		coeff[i] = other.coeff[i];
	}
}

Polynomial::Polynomial(int n)
{
	coeff = new double[1];
	coeff[0] = n;
	size = 1;
}

Polynomial::Polynomial(double o)
{
	coeff = new double[1];
	coeff[0] = o;
	size = 1;
}

Polynomial::~Polynomial(){
	if ( coeff != nullptr )
	{
		delete [] coeff;
		coeff = nullptr;
	}
	size = 0;
}

Polynomial& Polynomial::operator=(const Polynomial& right)
{
	if ( this == &right )
	{
		//self reference
		return *this;
	}

	if ( this->size < right.size )
	{
		//free up memory, replace memory
		delete [] coeff;
		coeff = new double [right.size];
		size = right.size;
	}

	size = right.size;
	
	for ( int i = 0; i < size; i++ )
	{
		coeff[i] = right.coeff[i];
	}

	return *this;
}

int Polynomial::getSize() const
{
	return size;
}

int Polynomial::degree() const
{
	int poly = 0;
	for ( int i = 0; i < size; i++ )
	{
		if ( this->coeff[i] != 0 )
		{
			poly = i;
		}
	}

	return poly;
}

std::string Polynomial::str() const
{
	std::stringstream ss;

	for ( int i = size-1; i >= 0; i-- )
	{
		if ( coeff[i] == 0 )
		{
			//Don't display
		}
		else if ( coeff[i] == 1 )
		{
			if ( i == 1 )
			{
				ss << " + " << "x";
			}
			else
			ss << " + " << "x" << "^" << i;
		}
		else if ( coeff[i] == -1 )
		{
			if ( i == degree() )
			{
				ss << "-" << "x" << "^" << i;
			}

			else if ( i == 1 )
			{
				ss << " - " << "x";;
			}

			else
			{
				ss << " - " << "x" << "^" << i;
			}
		}
		else if ( i == 1 )
		{
			//Don't display exponent
			if ( coeff[1] > 0 )
			{
				ss << " + " << coeff[1] << "x";  
			}
			else
			{
				//absV = fabs (coeff[i]);
				ss << " - " << (coeff[i] * -1) << "x";
			}
		}
		else if ( i == 0 )
		{
			//Don't display exponent
			if ( degree() == 0 )
			{
				// one item in array
				// display without operator space
				ss << coeff[0];
				break;
			}
			if ( coeff[i] > 0 )
				ss << " + " << coeff[i];
			else
				ss << " - " << (coeff[i] * -1); 
		}
		else
		{
			if ( coeff[i] > 0 )
			{
				if ( i == degree() )
				{
					ss << coeff[i] << "x" << "^" << degree();
				}
				else
				{
					ss << " + " << coeff[i] << "x" << "^" << i;
				}
			}
			else if ( coeff[i] < 0 )
			{
				if( i == degree() )
				{
					//negative case
					ss << coeff[i] << "x" << "^" << degree();
				}
				else
				{
					ss << " - " << (-1 * coeff[i]) << "x" << "^" << i;
				}
			}
		}
	}
	// std::cout<< "\n" <<std::endl;
	// std::cout<< ss.str() <<std::endl;
	return ss.str();
}

double Polynomial::solve(double x) const
{
	double result = 0;

	for ( int i = 0; i < size; i++ )
	{
		if ( coeff[i] != 0 )
		{
			result += coeff[i] * pow(x,i);
		}
	}
	return result;
}

double& Polynomial::operator[](int x)
{
	
		double* temp  = new double[ x + 1 ];

		for ( int j = 0; j < size; j++ )
		{
		 	temp[j] = coeff[j];
		}

		for ( int i = size; i < x + 1; i++ )
		{
			// allocate 0
			temp[i] = 0;
		}
		
		delete coeff;
		coeff = temp;
		size = x + 1;

		return coeff[x];
}

Polynomial Polynomial::operator+(const Polynomial& p2) const
{
	if ( this->degree() >= p2.degree() )
	{
		Polynomial p3(new double[this->size], size);
		p3.size = this->size;
		for ( int i = 0; i < this->size; i++ )
		{
			p3.coeff[i] = (this->coeff[i] + p2.coeff[i]);
		}
		return p3;
	}

	 else if ( this->degree() < p2.degree() )
	 {
	 	Polynomial p3(new double[p2.size], p2.size);
	 	p3.size = p2.size;
	 	for ( int i = 0; i < p3.size; i++ )
	 	{
	 		if ( i < size )
	 		{
	 			p3.coeff[i] = (this->coeff[i] + p2.coeff[i]);
	 		}
	 		else
	 		{
	 			p3.coeff[i] = p2.coeff[i];
	 		}
	 	}
	 	return p3;
	 }
}

Polynomial Polynomial::operator-(const Polynomial& p2) const
{
	if ( this->size == p2.size )
	{
		Polynomial p3(new double[this->size], size);
		p3.size = this->size;
		for ( int i = 0; i < this->size; i++ )
			{
				p3.coeff[i] = (this->coeff[i] - p2.coeff[i]);
			}
			return p3;
	}
}

Polynomial Polynomial::operator*(const Polynomial& p2) const
{
	Polynomial p3(new double[(this->size + p2.size)-1], (this->size + p2.size)-1);
	p3.size = (this->size + p2.size)-1;

	for ( int i = 0; i < p3.size; i++ )
	{
		p3.coeff[i] = 0;
	}

	int m = this->degree();
	int n = p2.degree();

	for ( int i = 0; i <= m; i++ )
	{
		for ( int j = 0; j <= n; j++ )
			p3.coeff[ i + j ] += this->coeff[i] * p2.coeff[j];
	}

	return p3;
}

Polynomial Polynomial::operator*(double x) const
{
	Polynomial p3(new double[size], size);
	p3.size = size;

	for ( int i = 0; i < size; i++ )
		p3.coeff[i] = this->coeff[i] * x;

	return p3;
}

Polynomial Polynomial::operator+=(const Polynomial& p2)
{
	*this = *this + p2;

	return *this;
}

Polynomial Polynomial::operator-=(const Polynomial& p2)
{
	*this = *this - p2;

	return *this;
}

Polynomial Polynomial::operator*=(const Polynomial& p2)
{
	*this = *this * p2;

	return *this;
}

bool Polynomial::operator==(const Polynomial& p2) const
{
	if ( size == p2.size )
	{
		for ( int i = 0; i < size; i++ )
		{
			if ( coeff[i] != p2.coeff[i] )
			{
				return false;
			}
		}
		return true;
	}
	return false;
}

//  bool Polynomial::operator!=(const Polynomial& p2) const
// {
//  	return !(*this == p2);
//  }

std::ostream& operator<<(std::ostream& os, const Polynomial& s)
{
	os << s.str();
	return os;
}




