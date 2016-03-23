#include "Conway.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

// add functions here
Conway::Conway(std::string str)
{
	std::ifstream fin(str);
	//First two ints taken in
	 fin >> rows;
	 fin >> cols;
	 //Allocates rows
	 board = new bool*[rows];

	 for (int i = 0; i < rows; i++)
	 {
	 	//Allocates columns
	 	board[i]  = new bool[cols];
	 }
	 //fills the array with content
	 for (int i = 0; i < rows; i++)
	 {
	 	for ( int k = 0; k < cols; k++)
	 	{
	 		fin >> board[i][k];
	 	}
	 }
	 fin.close();
}

int main(int argc, char *argv[])
{
	if (argc != 3)
	{
		std::cout<< "Input Error"<<std::endl;
	}
	if ( argv[1] != NULL && argv[2] != NULL )
	{
		std::ifstream fin(argv[1]);

		if ( fin )
		{
			Conway x(argv[1]);
			x.play(std::stoi(argv[2])); //string->int
		}
		else
		{
			std::cout<< "File Error"<<std::endl;
		}
	}

	return 0;
}

Conway::Conway(const Conway& other)://Copy Constructor
board(new bool*[other.rows]), rows(other.rows), cols(other.cols)
{
	for ( int i = 0; i < rows; i++ )
	 {
	 	board[i] = new bool[cols];
	 	for ( int j = 0; j < cols; j++ )
	 	{
	 		board[i][j] = other.board[i][j];
	 	}
	 }
}

Conway::~Conway()//Destructor
{
	for ( int j = 0; j < cols; j++ )
	{
		delete[] board[j];
	}
	delete[] board;
	rows = 0;
	cols = 0;
}

Conway& Conway::operator=(const Conway& right)
{
	if ( this == &right )
	{
		//Self Reference
		return *this;
	}

	for ( int j = 0; j < cols; j++ )
	{
		delete[] board[j]; //delete subarray
	}

	delete [] board;//delete whole array

	rows = right.rows;
	cols = right.cols;
	board = new bool*[right.rows];

	for (int i = 0; i < rows; i++)
	 {
	 	//Allocates columns
	 	board[i]  = new bool[cols];
	 }

	 for ( int i = 0; i < rows; i++ )
	 {
	 	for ( int j = 0; j < cols; j++ )
	 	{
	 		board[i][j] = right.board[i][j];
	 	}
	 }
		
	return *this;
}

bool Conway::alive( int row, int col ) const
{
	return board[row][col];
}

void Conway::flip( int row, int col )
{
	board[row][col] = !board[row][col];
}

std::string Conway::str() const
{
	std::stringstream printOut;
	for ( int i = 0; i < rows; i++ )
	{
		for ( int j = 0; j < cols; j++ )
		{
			if ( board[i][j] == 0 )
			{
				printOut << " . " << "  ";
			}
			else
			{
				printOut << " X " << "  ";
			}
		}
		printOut << "\n";
	}
	return printOut.str();
}

void Conway::step()
{
	//count is living neighbors
	int neighbors;
	Conway gameBoard(*this);

	for ( int i = 0; i < rows; i++ )
	{
		for ( int j = 0; j < cols; j++)
		{
			neighbors = 0;
				//Count neighbors around
				//Bounds checks included
				if ( i > -1 ){
					if ( board[i][j+1] )
					{
					neighbors++;
					}
				}

				if (i > -1 && i < rows){
					if ( board[i][j-1] )
					{
					neighbors++;
					}
				}

				if (i - 1 > -1){
					if ( board[i-1][j] )
					{
					neighbors++;
					}
				}

				if ( i + 1 < rows){
					if ( board[i+1][j] )
					{
					neighbors++;
					}
				}

				if ( i - 1 > -1 ){
					if ( board[i-1][j+1])
					{
					neighbors++;
					}
				}

				if (i + 1 < rows){
					if (board[i+1][j+1])
					{
					neighbors++;
					}
				}

				if (i - 1 > -1){
					if (board[i-1][j-1])
					{
					neighbors++;
					}
				}

				if ( i + 1 < rows ){
					if (board[i+1][j-1])
					{
					neighbors++;
					}
				}

			if (alive(i,j) && neighbors < 2)
			{
				//kill
				gameBoard.board[i][j] = false;
			}

			if (alive(i,j) && neighbors > 3)
			{
				//kill
				gameBoard.board[i][j] = false;
			}

			if ( alive(i,j) && (neighbors == 2 || neighbors == 3))
			{
				//lives on
				gameBoard.board[i][j] = board[i][j];
			}

			if ( !alive(i,j) && neighbors == 3 )
			{
				//Comes to life
				gameBoard.board[i][j] = true;
			}


		}
	}
	//New positions
	*this = gameBoard;  
}

void Conway::play(int n)
{
	for ( int i = 0; i < n; i++ )
	{
		step();
		std::cout<< str()<<"\n";
	}
}
