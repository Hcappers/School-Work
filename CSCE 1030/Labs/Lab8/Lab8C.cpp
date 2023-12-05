#include <iostream>
using namespace std;

const int COLS = 6;

void computeAverage(float grades[][COLS], int ROWS);

int main (){
    const int ROWS = 3;
    float grades[ROWS][COLS];
    
    for(int row = 0; row < ROWS; row++){
        for(int col = 0; col < COLS - 1; col++){
            cout << "Enter Quiz # " << col + 1 << " for Student # " << row + 1 << ":";
            cin >> grades[row][col];
        }
    }
     computeAverage(grades, ROWS);

    for(int row = 0; row < ROWS; row++){
        cout << "Student #" << row + 1 << " average is: ";
        for(int col = 0; col < COLS; col++){
            cout << grades[row][col] << "  ";
        }
        cout << endl;
    }

    return 0;
}

void computeAverage(float grades[][COLS], int ROWS){
    for(int row = 0; row < ROWS; row++){
        float sum = 0;
        for(int col = 0; col < COLS - 1; col++){
            sum += grades[row][col];
        }
        grades[row][COLS -1] = sum / (COLS -1);
    }

}