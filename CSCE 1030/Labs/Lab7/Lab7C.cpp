#include <iostream>
using namespace std;

const int SIZE = 5;
void get_min(double my_array[SIZE], double& max);

int main (){
	double max;
	double my_array[SIZE] = {1.1, -3.6, 2.5, 2.9, -3.4};
	
	max = my_array[0];

	get_min(my_array, max);
	cout << "Largest value: " << max << endl;
	return 0;
}

/* Function: get_min
   Parameters: double my_array and double minimum
   Return: the lowest value in the array
   Description: This function finds the lowest value in the my_array
*/
void get_min(double my_array[SIZE], double& max){
    for(int i = 0; i < SIZE; ++i){
        if(max < my_array[i]){
            max = my_array[i];
        }
    }
}