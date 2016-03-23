#include <iostream>
#include <cstdio>
#include <string>
//Global variable
int num;
using namespace std;

int getNum(string msg){
int i = 0;

	do{
	// This iterator increments everytime it has to loop to reprompt
	// if the iterator is used more than once, it prompts an error msg.
	i++;
	if (i > 1){
		printf("Number Out of Bounds, Try Again\n");
		cout << msg << endl;
		cin >> num;
	}else{
		cout << msg << endl;
		cin >> num;
		}
	}while (num < 0 || num > 99);

	

	return num;
}

int main(){
getNum("Enter a number in the range [0,99]: ");
int quarters = num /25; 
int dimes = (num - (quarters*25))/10;
int nickels = (num - ((quarters*25)+(dimes*10)))/5;
int pennies = num - ((quarters*25) + (dimes*10) + (nickels*5));

printf("%s\n","The proper change is:" );

switch (quarters){
case 0:
	break;
case 1:	
	 printf("Quarter: %d\n", quarters);
	 break;
default:
	printf("Quarters: %d\n", quarters);
	break;
}

switch (dimes){
case 0:
	break;
case 1:	
	 printf("Dime: %d\n", dimes);
	 break;
default:
	printf("Dimes: %d\n", dimes);
	break;
}

switch (nickels){
case 0:
	break;
case 1:	
	 printf("Nickel: %d\n", nickels);
	 break;
default:
	printf("Nickels: %d\n", nickels);
	break;
}

switch (pennies){
case 0:
	break;
case 1:	
	 printf("Penny: %d\n", pennies);
	 break;
default:
	printf("Pennies: %d\n", pennies);
	break;
}
}







