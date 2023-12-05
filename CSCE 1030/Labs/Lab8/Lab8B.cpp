#include <iostream>
using namespace std;

void get_grade(int grades[], int SIZE);

int main (){
    const int SIZE = 5;
    int grades[SIZE];
    
    get_grade(grades, SIZE);
    
    for(int i = 0; i < SIZE; i++){
        cout << "Grades[" << i << "] = " << grades[i] << endl;
    }

    return 0;
}

void get_grade(int grades[], int SIZE){
    for(int i=0; i<SIZE; i++){
        cout << "Enter a grade between 0 and 100: ";
        cin >> grades[i];
    }
    return;
}