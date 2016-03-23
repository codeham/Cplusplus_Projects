#ifndef CONWAY_H
#define CONWAY_H

#include <string>

using std::string;

class Conway
{
private:
    // add private members here
    bool** board;
    int rows;
    int cols;
public:
    // add public menbers here
    Conway(std::string);
	Conway(const Conway& other);
	~Conway();
	Conway& operator=(const Conway& right);
	bool alive( int row, int col) const;
	void flip( int row, int col );
	std::string str() const;
	void step();
	void play(int n);







};

#endif