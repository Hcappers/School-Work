#include <iostream>
#include <string>
using namespace std;


struct Student{
    string name;
    int test[3];
    double avg;
};

int main(){
    // Number of students
    Student students[5]; 

    // For loop to ask the user the name and the tests scores for each student. Then take all the tests and adds the togeather in sum and the divides by the number of tests for the average.
    for(int i = 0; i < 5; i++){
        int sum = 0;
        cout << "Enter the students name: ";
        cin >> students[i].name; 
        for(int j = 0; j < 3; j++){
            cout << "Enter the students test scores: ";
            cin >> students[i].test[j];

            sum += students[i].test[j];
            students[i].avg = sum / 3.0;
        }
    }

    // For displaying each students name and with their average.
    for(int i = 0; i < 5; i++){
        cout << students[i].name << " ";
        cout << students[i].avg;
    }
    cout << endl;

    return 0;
}