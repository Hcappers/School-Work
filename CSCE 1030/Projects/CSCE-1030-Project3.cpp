#include<iostream>
using namespace std;

const int SIZE = 25; // The size of the grid

int ar1[8] = {-1,-1,-1,0,0,1,1,1}; // Gives the values to look at the surrounds spaces for x
int ar2[8] = {-1,0,1,-1,1,-1,0,1}; // Gives the values to look at the surrounds spaces for y

void fillArray(char array[][SIZE], int size); // This array fills the array with S
void printArray(char array[][SIZE], int size); // Array to print out the grid
void pickInfected(char array[][SIZE], int size, int x, int y); // Array to choose where the infection starts
void spreadInfection(char array[][SIZE], int size_1, char nextDay[][SIZE], int size_2); // Array to spread the infection after the user has chosen which location to start the infection
void gridUpdate(char grid[][SIZE], char nextDay[][SIZE], int size);  // Updates the grid to coninue the spread
void recoverInfection(char array[][SIZE], char nextDay[][SIZE], int size); // This is used to switch from I to R.
void intro(); //This function if for the intro dedicated by instructions.
int infectedCount(char grid[][SIZE], int size); //Array to count how many people are infected on the grid.
bool check(char array[][SIZE], int size); // Used for the while statment to run till infection is done.

int main (){
    
    char grid[SIZE][SIZE]; // Begining day and the day afternext day grid
    char nextDay[SIZE][SIZE]; // The next day grid
    int day = 0; // To compile the days at the top of the grid and this starts the day at 0 
    int x, y; // for the user to choice what cordinates they want to use to infect

    intro();

    fillArray(grid, SIZE);
    fillArray(nextDay, SIZE);

    // This group of code allows the user to choose where they would like to infect on the grid.
    cout << "Select a X coordinate (0 - " << SIZE - 1 << "): ";
    cin >> x;
    cout << "Select a Y corrdinate (0 -  " << SIZE - 1 << "): "; 
    cin >> y;

    // Checks to see if withen the grids bounds
    while((x < 0) || (x > SIZE - 1) || (y < 0 ) || (y > SIZE - 1)){ 
        cout << "Error not in the bounds of the grid" << endl;
        cout << "Select a X coordinate (0 - " << SIZE - 1 << "): ";
        cin >> x;
        cout << "Select a Y corrdinate (0 - " << SIZE - 1 << "): ";
        cin >> y; 
    }

    pickInfected(grid, SIZE, x, y);
    pickInfected(nextDay, SIZE, x, y);

    // This group of code is for printing the grid and displaying the infected count at the bottom
    cout << endl;
    cout << "Day 0:" << endl;
    printArray(grid, SIZE);
    cout << "The number of infected people is: " << infectedCount(grid, SIZE) << endl;
    cout << endl;

    // This is to run it until the entire board is R
    while(!check(grid,SIZE)){
        spreadInfection(grid, SIZE, nextDay, SIZE);
        recoverInfection(grid, nextDay, SIZE);
        gridUpdate(grid, nextDay, SIZE);
        day++;
        cout << "Day "<< day << ": " << endl;
        printArray(grid,SIZE);
        cout << "The number of infected people is: " << infectedCount(grid, SIZE) << endl;
        cout << endl;
    }

        cout << "It took " << day << " days for the outbreak to end. " << endl;

    return 0;
}

void fillArray(char array[][SIZE], int size){
    for(int row = 0; row < SIZE; row++){
        for(int colms = 0; colms < SIZE; colms++){
            array[row][colms] = 'S';
        }
    }
}

void printArray(char array[][SIZE], int size){
    for(int row = 0; row < SIZE; row++){
        for(int colms = 0; colms < SIZE; colms++){
            cout << array[row][colms] << " ";
        }
        cout << endl;
    }
}

void pickInfected(char grid[][SIZE], int size, int x, int y){
    grid[x][y] = 'I';
}

void spreadInfection(char array[][SIZE], int size_1, char nextDay[][SIZE], int size_2){
    for(int row = 0; row < SIZE; row++){
        for(int colms = 0; colms < SIZE; colms++){
            if(array[row][colms] == 'I'){
                for(int i = 0; i < 8; i++){
                    int r = row + ar1[i];
                    int c = colms + ar2[i];
                    if(r >= 0 && r < SIZE && c >= 0 && c < SIZE && array[r][c]=='S'){
                        nextDay[r][c] = 'I';
                    }
                }
            }
        }
    }
}

void gridUpdate(char grid[][SIZE], char nextDay[][SIZE], int size){
    for(int row = 0; row < SIZE; row++){
        for(int colms = 0; colms < SIZE; colms++){
            grid[row][colms] = nextDay[row][colms];
        }
    }
}

void recoverInfection(char array[][SIZE],char nextDay[][SIZE], int size){
    for(int row = 0; row < SIZE; row++){
        for(int colms = 0; colms < SIZE; colms++){
           if(array[row][colms]=='I'){
               nextDay[row][colms]='R';
           } 
        }
    }
}

void intro(){
    cout << "****************************************************************" << endl;
    cout << "             Computer Science and Engineering                   " << endl;
    cout << "              CSCE 1030 - Computer Science 1                    " << endl;
    cout << "Haskell Cappers   --   hac0078    --  haskellcappers@my.unt.edu " << endl;
    cout << "****************************************************************" << endl;
    cout << endl;
}

int infectedCount(char array[][SIZE], int size){
    int count = 0;
    for(int row = 0; row < SIZE; row++){
        for(int colms = 0; colms < SIZE; colms++){
            count = (array[row][colms] == 'I') ? count += 1 : count; 
        }
    }
    return count;
}

bool check(char array[][SIZE], int size){
    for(int row=0; row <SIZE; row++){
        for(int colms=0;colms<SIZE;colms++){
            if(array[row][colms]=='S' || array[row][colms]=='I') {
                return false;
            }
        }
    }
    return true;
}