#include <fstream>
#include <string>
#include <iostream>

using namespace std;

int main(int argc, char *argv[]){
	//Start @ 1, not 0
	int i = 1;
	string x;

	while(argv[i] != NULL){
		ifstream fin(argv[i]);
	
	if (fin){
		while (getline(fin, x)){
			cout<< x <<"\n";
			}
		}else{
			cout<< "Error: File Not Valid" << argv[i] << "\n";
		}
		i++;
	}
	return 0;
}

 
