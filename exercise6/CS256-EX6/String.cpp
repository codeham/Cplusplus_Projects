#include "String.h"

// this header has some useful functions
// for working with C-strings
#include <cstring>

// Put your function implementations here
String::String(){
	//default const.
	data = new char [10];
	size = 0;
}

String::String(char single){
	data = new char [10];
	data[0] = single;
	size = 1;
}

String::String(const char* str){
	data = new char [strlen(str)];
	for ( int i = 0; i < strlen(str); i++ )
	{
		data[i] = str[i];
	}
	size = strlen(str);
}

String::String(const String& other): 
data(new char[other.size]), size(other.size)
	{
		for ( int i = 0; i < size; i++ )
		{
			data[i] = other.data[i];
		}
	}

String::~String(){
	if( data != nullptr )
	{
		delete [] data;
		data = nullptr;
	}
	size = 0;
}

String& String::operator=(const String& right)
{
	if( this == &right )
	{
		//Self reference 
		return *this;
	}

	if ( this->size < right.size )
	{
		//deallocate and reallocate
		delete [] data;
		data = new char [right.size];
		size = right.size;
	}
	
	for ( int i = 0; i < size; i++ )
	{
		data[i] = right.data[i];
	}
	return *this;
}

int String::length() const
{
	return size;
}

char String::charAt(int x) const
{
	return data[x];
}

int String::indexOf(char str) const
{
	int x = 0;
	for ( int i = 0; i < size; i++ )
	{
		if ( data[i] != str )
		{
			x = -1;
		}else{
			x = i;
			break; //stops the loop, if first instance spotted
		}
	}
	return x;
}

char& String::operator[](const int x){
	return data[x];
}

 String String::operator+(const String& right) const
{
	char* concatArray = new char [size + right.size];
	
	for ( int i = 0; i < size; i++ )
	{
		concatArray[i] = data[i];
	}
	int x = size;
	for ( int i = 0; i < right.size; i++ )
	{
		concatArray[x] = right.data[i];
		x++;
	}

	return concatArray;
}

String String::operator+(char c) const
{
	//Append char to the end of string
	char* appendArray = new char [size + 1];
	for ( int i = 0; i < size; i++ )
	{
		appendArray[i] = data[i];
	}
	appendArray[size] = '\0';
	appendArray[size] = c;
	

	return appendArray;
}

bool String::operator==(const String& right) const
{ 
	bool result = true;
	if ( size == right.size )
	{
		for ( int i = 0; i < size; i++ )
		{
			if ( this->data[i] != right.data[i] )
			{
				result = false;
			}	
		}
	}else{
		result = false;
	}
		return result;
	
}

bool String::operator!=(const String& right) const
{
	 if( operator==(right) != true )
	 	return true;
}

bool String::operator<(const String& right) const
{
	int x = 0;
	while ( this->data[x] && right.data[x] ){
		if( this->data[x] < right.data[x] )
		{
			return true;
		}
		x++;
	}
}

bool String::operator>(const String& right) const
{
	int x = 0;
	while ( this->data[x] && right.data[x] ){
		if( this->data[x] > right.data[x] )
		{
			return true;
		}
		x++;
	}
}	

bool String::operator<=(const String& right) const 
{
	if ( operator<(right) == true || operator==(right) == true )
		return true;
}

bool String::operator>=(const String& right) const 
{
	if ( operator>(right) == true || operator==(right) == true )
		return true;
}

String String::substring(int start, int end) const
{
	String x;
	if ( start < 0 || start >= end )
	{
		return x;//return empty string
	}

	//--> Note: This is weird, but if I uncomment this and comment the top
	//this bottom part gives functionallity, if I leave it uncommented, the 
	//top does not execute for some reason, ran out of time to fix...

	
	 // int difference = end - start;
	 // char* newArray = new char [difference];
	 // end = end-1; //index before end

	 //  int count = 0;
	 //  for ( int i = start; i <= end; i++ )
	 //  {
	 //  	newArray[count] = data[i]; //assigns to new array
	 // 	count++;
	 //  }

	 //  String s(newArray);
	 //  std::cout<< s;
	 //  s.size = difference;
	 //  delete [] newArray;

	  // return s;
}

std::ostream& operator<<(std::ostream& os, const String& s)
{
	os << s.data;
	return os;
}

std::istream& operator>>(std::istream& is, String& s)
{
	 std::string newStr;
	 is >> newStr;

	 int x = 0;
	 while ( x < newStr.length() ){
	 	s.data[x] = newStr[x];
	 	x++;
	 }

	 s.size = newStr.length();

	 return is;
}

