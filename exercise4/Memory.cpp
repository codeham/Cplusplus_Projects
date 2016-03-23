#include <iostream>
using namespace std;

//Declared functions
int*** alloc3D(int x , int y, int z);
void dealloc3D(int*** a, int x, int y);


int main(){
	while(true){
		int*** a = alloc3D(100,100,100 );
		dealloc3D(a, 100, 100);
	}

	return 0;

}

int*** alloc3D(int x , int y, int z){
	//allocate a pointer of pointers
	int*** result = new int**[x];

	for ( int i = 0; i < x; i++ ){
		result[i] = new int*[y];
		for ( int j = 0; j < y; j++){
			result[i][j] = new int[z];
		}
	}

	return result;
}
	//deallocating 
void dealloc3D(int*** a, int x, int y){
	for( int i = 0; i < x; i++ ){
		for ( int j = 0; j < y; j++){
			delete[] a[i][j];
		}
		delete[] a[i];
	}
	//Delete array itself
	delete[] a;
}


