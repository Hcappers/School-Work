#include <iostream>
using namespace std;

int main(){
    int my_int = 10;
    int *my_iptr, *my_iptr2;
    

    my_iptr = &my_int;
    cout << "The value of my_int using the variable name: " << my_int << endl;
    cout << "The memory address of my_int using the variable name: " << &my_int << endl;
    cout << "The address of the variable my_int using the pointer: " << my_iptr << endl;
    cout << "The valueof the variable my_int using the pointer: " << *my_iptr << endl;

    //Assigning the dereferenced pointer to 15
    *my_iptr = 15;
    cout << "Value of my_int using the variable name: " << my_int << endl;

    my_iptr = new int;
    *my_iptr = 20; // assining the new int to 20

    cout << "The value of my_int using the variable: " << my_int << endl;

    my_iptr2 = new int;
    my_iptr2 = my_iptr; // Assinging the new pointer to the first pointer

    // Displaying the value ot the pointer
    cout << "The value of my_iptr2 using dereference: " << *my_iptr2 << endl;

    // Deleteing the allocated space in memory of the pointers
    delete my_iptr;

    cout << "Both pointers deleted " << endl;


    return 0;
}