#ifndef STRING_H
#define STRING_H

#include <iostream>
#include <string>


class StringTester;

class String
{
    friend class StringTester;
    friend std::ostream& operator<<(std::ostream& os, const String& s);
	friend std::istream& operator>>(std::istream& is, String& s);

private:
    // declare private members here
     char *data;
     int size; 
public:
    // declare public members here
    String();
    String(char);
	String(const char*);
	String(const String&);
	~String(); //Destructor
	String& operator=(const String& right);
	//Helper functions
	int length() const;
	char charAt(int) const;
	int indexOf(const char) const;
	char& operator[](const int);
	//Concatination Functions
	String operator+(const String& right) const;
	String operator+(char) const;
	bool operator==(const String& right) const;
	bool operator!=(const String& right) const;
	bool operator<(const String& right) const;
	bool operator>(const String& right) const;
	bool operator<=(const String& right) const;
	bool operator>=(const String& right) const;
	//Substring Section
	String substring(int start, int end) const;
	

};

std::ostream& operator<<(std::ostream& os, const String& s);
std::istream& operator>>(std::istream& is, String& s);
#endif