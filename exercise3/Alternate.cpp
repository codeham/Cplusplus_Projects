#include <iostream>
#include <string>

using namespace std;

int main(){
int input;
char charX = 'X';
string charString = string(20, charX);

cout<< "Input a positive integer: " <<endl;
cin>> input;

while ( input < 1){
	cout<<"Input not in range, try again" <<endl;
	cin>>input;
}

int x = 0;
char space = ' ';
string spaceString;
bool hitCount = false;


for ( int i = 0; i < input; i++){
	spaceString = string(x, space);
	if ( x <= 50 && hitCount == false ){
	// this function stores x amount of blankspace chars
	cout<< spaceString << charString <<endl;
	hitCount = false;
	x++;
	}else{
		if (x != 0){
		--x;
		cout<< spaceString << charString <<endl;
		hitCount = true;
		}else{
		hitCount = false;
		}
		}
	}
	return 0;
}
