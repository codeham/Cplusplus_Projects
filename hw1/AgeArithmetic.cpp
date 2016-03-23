// Cristian Avina-Lopez
// Homework 1
// Completed 1/17/2016
#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main(){
//Declared Variables
int age;
int ageSquared;
int ageHalved;
float mean;


cout<< "Enter your age: " <<endl;
cin>> age;

while ( age < 0){
	cout<< "Age entered invalid, try again: " <<endl;
	cin>> age;
}

ageSquared = pow(age, 2.0);
ageHalved = age/2;
//Cast to float
mean = (float)(age+ageSquared+ageHalved)/3;

cout<< "age: " << age <<endl;
cout<< "ageSquared: " << ageSquared <<endl;
cout<< "ageHalved: " << ageHalved <<endl;
cout<<"\n";

//Print Calculations
cout<<"1. " << age*ageHalved <<endl;
cout<<"2. " << ageSquared/ageHalved <<endl;
cout<<"3. " << fmod(ageSquared,ageHalved) <<endl;
cout<<"4. " << age-ageHalved <<endl;
cout<<"5. " << ageSquared/age <<endl;
cout<<"6. " << ageSquared+age <<endl;
cout<<"7. " << mean <<endl;
return 0;
}