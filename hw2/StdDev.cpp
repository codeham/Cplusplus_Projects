// Cristian Avina Lopez
// Homework 2
// Completed 1/22/2016
#include <iostream>
#include <cmath>

using namespace std;

double sum(double values[], int size);
double mean(double values[], int size);
double stdDev(double values[], int size);

int main(){
//Variables
double input = 0;
double inputArray[10] = {};

cout<< "Enter 10 values: " <<endl;
for(int i = 0; i < 10; i++){
  cin>>input;
  inputArray[i] = input;
}
  std::cout<< "Standard Deviation: " << stdDev(inputArray, 10) <<std::endl;

  return 0;
}

double sum(double values[], int size){
double sum = 0;
for(int i = 0; i < size; i++){
  sum += values[i];
}

  return sum;
}

double mean(double values[], int size){
  double mean = 0;
for( int i = 0; i < size; i++){
    mean += values[i];
}
    mean = mean/size;

  return mean;
}

double stdDev(double values[], int size){
double sumFunc = sum(values, size);
double meanFunc = mean(values, size);
double stand_dev = 0;
double sum_dev = 0;

//testing purp -->  std::cout << "sum is: " << sumFunc << std::endl;
//testing purp -->  std::cout << "mean is: " << meanFunc << std::endl;
for (int i = 0; i < size; i++) {
    sum_dev += (values[i]-meanFunc)*(values[i]-meanFunc);
}
  return sqrt(sum_dev/size);
}
