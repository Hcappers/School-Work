#include <iostream>
using namespace std;

int main(){
    int num_stdnt, num_tests;
    int **stud_ptr;
    stud_ptr = new int *[num_stdnt];
    double *avg;
    avg = new double[num_stdnt];

    // Lets the user define how many students in the array
    cout << "How many students?";
    cin >> num_stdnt;

    // Lets the user enter the tests for each student
    for(int i = 0; i < num_stdnt; i++){
        cout << "How many tests for this student #" << i + 1 << "?";
        cin >> num_tests;
        int sum = 0;

        stud_ptr[i] = new int[num_tests];

        // For the user to enter all the tests grades for each student.
        for(int j = 0; j < num_tests; j++){
            cout << "Enter test grade #" << j+1 << ": ";
            cin >> *(stud_ptr[i]+j);
            sum += *(stud_ptr[i]+j); // Adds all the tests for each student
        }
       *(avg+i) = sum / static_cast<double>(num_tests); // Takes the sum of all tess and divides by the number os tests to get the average.
    }

    // For displaying the average of each student
    for(int i = 0; i < num_stdnt; i++){
        cout << "The average for student #" << i+1 << ": " << *(avg+i) << endl;
    }

    // Delets the allocated memory for the avg pointer
    delete[] avg;

    // For deleting the allocated memory for the dynamic 2 array 
    for(int i = 0; i < num_stdnt;i++){
        delete[] stud_ptr[i];
    }

    return 0;
}