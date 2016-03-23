
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(){
string filenameA;
string filenameB;
string content;


cout<<"Enter from file: ";
cin>> filenameA;

//c.str passes C-Style strings into functions
ifstream fin(filenameA.c_str());

if (fin){
//Copy contents from file a --> file b
//	cout<< "Check" <<endl; <-- testing purposes 

	cout<<"Enter to file: ";
	cin>>filenameB;

	ofstream fout(filenameB.c_str());
	int c = 0;
	  while (getline(fin, content)){
	  		fout<<content<<endl;
	  		c += content.length();
	  }

	  cout<< "Copied " << c << " characters." <<endl;

}else{
	cout << "Error opening file.\n";
}


return 0;
}
