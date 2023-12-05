#include <iostream>
#include <ctime>
#include <cstdio>
#include <cstdlib>
using namespace std;

const int SIZE = 4;

void intro(); //This function if for the intro dedicated by instructions.
void fillarray(char array[][SIZE],char visablearray[][SIZE], int SIZE);
void printarray(char array[][SIZE],char visablearray[][SIZE], int SIZE);
bool guesses(char array[][SIZE], char visablearray[][SIZE], int SIZE);
bool match(char array[][SIZE], char visablearray[][SIZE], int SIZE);

int main(){
    char visable[SIZE][SIZE];
    char hidden[SIZE][SIZE];
    int attempt = 0;

    intro();


    fillarray(visable, hidden, SIZE);
    printarray(visable, hidden, SIZE);

   /* while(attempt < 10){
        guesses(visable, hidden, SIZE);
        attempt++;
    }*/

    return 0;
}

void intro(){
    cout << "****************************************************************" << endl;
    cout << "             Computer Science and Engineering                   " << endl;
    cout << "              CSCE 1030 - Computer Science 1                    " << endl;
    cout << "Haskell Cappers   --   hac0078    --  haskellcappers@my.unt.edu " << endl;
    cout << "****************************************************************" << endl;
    cout << endl;
}

void fillarray(char array[][SIZE],char visablearray[][SIZE], int size){
    int row;
    int col;
    int count = 0;
    char letter;
    srand(time(NULL));

    for(int i = 0; i < SIZE; i++){
        for(int j = 0; j < SIZE; j++){
            array[i][j] = 'X';
            visablearray[i][j] = 'X';
        }
    }
    for(int i = 0; i < SIZE;  i++){
        while(count < 2){
            row  = rand() % 4;
            col = rand() % 4;
            array[row][col] = 'A';
            count++;
        }
    }
}


void printarray(char array[][SIZE], char visablearray[][SIZE], int size){
    for(int i = 0; i < SIZE; i++){
        for(int j = 0; j < SIZE; j++){
            cout << visablearray[i][j] << " ";
        }
        cout << endl;
    }
}


bool guesses(char array[][SIZE], char visablearray[][SIZE], int SIZE){
    int x1, x2, y1, y2;

    //asks the users to pick coordiantes to see if match
    cout << "Select a X coordinate (0 - " << SIZE - 1 << "): ";
    cin >> x1;
    cout << "Select a Y corrdinate (0 -  " << SIZE - 1 << "): "; 
    cin >> y1;

    cout << "Select a X coordinate (0 - " << SIZE - 1 << "): ";
    cin >> x2;
    cout << "Select a Y corrdinate (0 -  " << SIZE - 1 << "): "; 
    cin >> y2;

    // Checks to see if withen the grids bounds
    if((x1 < 0) || (x1 > SIZE - 1) ||(x2 < 0) || (x2 > SIZE - 1) || (y1 < 0 ) || (y1 > SIZE - 1) ||(y1 < 0 ) || (y1 > SIZE - 1)){ 
        cout << "Error not in the bounds of the grid" << endl;
        cout << "You have lost the game!" << endl;
        return false;
    }
    //checks to see if user finds an X
    if(visablearray[x1][y1] == 'X' ||visablearray[x2][y2] == 'X'){
        cout << "You have found an X" << endl;
        return false;
    }
}

bool match(char array[][SIZE], char visablearray[][SIZE], int SIZE){
    for(int i = 0; i < SIZE; i++){
        for(int j = 0; i < SIZE; i++){
            if(array[i][j] != visablearray[i][j]){
                return false;
            }
            return true;
        }
    }
}
