#include <iostream>
using namespace std;

int main(){
    int *numlist; // Declaring the pointer
    int size; // Declaring the size of the array

    // to give the user the option to define the size of the array
    cout << "What size array do u want?" << endl;
    cin >> size;

    numlist = new int[size];

    // To let the user enter number into the array
    for(int i = 0; i < size; i++){
        cout << "Enter the value #" << i + 1 << ":";
        cin >> *(numlist + i);
    }

    // To print the array backwards
    for(int i = size; i > 0; i--){
        cout << "Value #" << i << ":";
        cout << *(numlist + (i - 1)) << endl;
    }

    // Deleting the memory allocated to the pointer
    delete numlist;

    return 0;
}
