#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;

enum TILETYPE {LOCKED = 'X', HORIZONTAL = '-', CROSS = '+', VERTICAL = '|', EMPTY = ' '}; // These are the different type of momvemts that can be used
enum COLOR {RED, BLUE, STANDARD}; // This is to have a color difference between the computer and user movements

struct Tile{
    TILETYPE type;
    COLOR color;
    int lane; // for the 7 lanes for the board on the x and y axis
};


void intro(); // This function is only to display the defualt header
void rules(); // This function is only to display the rules of the game at the beginning.
void initalboard(Tile **board, int size); // This function is to have the user input the file the want for the board
void printboard(Tile **board, int size); // This funciton is to print the board everytime after either the computer or the user makes a turn
void AiTurn(Tile **board, int size); // This function is for the computer's movements
void UserTurn(Tile **board, int size); // This is for the users moves
void placeTile(Tile **board, int size, TILETYPE tiletype, int lane, int user); //This function is to place the tiles on the board and to move the appropriate tiles
bool gameOver(Tile **board, int size);//returns true if game over
TILETYPE getTileType(char type); // This function refers to the enum to get the correct movement type

int main(){
    // This size of the board
    const int SIZE = 7;

    // This group of lines of code are for allocating the memory and setting the pointer for the 2D dynamic array
    Tile **tiles; 
    tiles = new Tile*[SIZE];
    for(int i = 0; i < SIZE; i++){
        tiles[i] = new Tile[SIZE];
    }

    // These 3 line of code are for displaying the default class header, asking for the user to enter the text file of the game board and displaying the rules
    intro();
    initalboard(tiles, SIZE);
    rules();

    // This is loop untill either the user or computer has won the game
    while(!gameOver(tiles, SIZE)){
        UserTurn(tiles, SIZE);
        if(!gameOver(tiles, SIZE)){
            AiTurn(tiles, SIZE);
        }
    }
    
    // To print the board one last time after either the computer or user has won
    printboard(tiles, SIZE);

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

void rules(){
    cout << "********************The aMAZEing Labyrinth********************\n" << endl;
    cout << "                           Rules\n                              " << endl;
    cout << "The aMAZEing Labyrinth is a two player game in which players\n  ";
    cout << "take turns sliding tiles, marked with |, -, or +, into lanes\n  ";
    cout << "from their side of the board. The goal is to have at least one\n";
    cout << "lane that has a straight, connected path from one player's\n    ";
    cout << "side of the board to the opposite side. This game is as much\n  ";
    cout << "about offense as it is defense, as you will have to try to\n    ";
    cout << "extend your path while blocking your opponent's progress.\n     " << endl;
    cout << "                           Good luck!                           " << endl;
    cout << "**************************************************************  " << endl;
}

void initalboard(Tile **board, int size){
    ifstream in_s; // To let the user choose what file they want for the game board
    char infile[50]; // This is a 1D array for the input file.
    char c; // This is so the fucntion car grag the the grid
    string line, temp;

    cout << "Please enter the filename of the designated board: ";
    cin >> infile;
    in_s.open(infile);

    // This is an error checking prosses for the input file.
    while(in_s.fail()){
        cout << "The file you tired to open failed. Please try again: ";
        cin >> infile;
        in_s.open(infile);
    }

    //This is to grap the X and ' ' but leaving the , in the input file
    int row = 0;
    while(getline(in_s, line)){
        int col = 0;
        stringstream ss(line);
        while(getline(ss, temp, ',')){
            board[row][col].lane = 0;
            board[row][col].type = getTileType(temp[0]);
            board[row][col].color = STANDARD;
            col++;
        }
        row++;
    }
}

void printboard(Tile **board, int size){
    cout << "   ";
    for(int i = 0; i < 7; i++){
        cout << i + 1 << " ";
    }
    cout << endl << "  ****************";

    for(int i = 0; i < size; i++){
        cout << endl << i + 1 << " *";
        for(int j = 0; j < size; j++){
            cout << (char)board[i][j].type << " ";
        }
        cout << '*';
    }
    cout << endl << "  ****************" << endl;

}

void AiTurn(Tile **board, int size){
    int lane;
    char TileType;
    TILETYPE type;

    srand(time(NULL)); // To have a different seeding for each time the AI makes a move
    lane = rand() % 7 + 1; // To randamly choose which lane the AI is going to make their move in
    cout << "Computer has chosen lane " << lane << ": " << endl;

    TileType = rand() % 3; // To randamly choose what type of piece the AI is going to use for their turn

    switch (TileType){
        case 0:
            cout << "The computer has chosen - tile type"<< endl;
            type = getTileType('-');
            break;

        case 1:
            cout << "The computer has chosen | tile type"<< endl;
            type = getTileType('|');
            break;

        case 2:
            cout << "The computer has chosen + tile type"<< endl;
            type = getTileType('+');
            break;
    }
    placeTile(board, size, type, lane, 2);
}

void UserTurn(Tile **board, int size){
    printboard(board, size);
    int lane;
    char TileType;

    cout << "Please choose a lane: 1 - 7 or type -1 to quit: ";
    cin >> lane;

    cout << "Please choose a tile to add (examples: '-' or '|' or '+')";
    cin >> TileType;

    placeTile(board, size, getTileType(TileType), lane, 1);
}

void placeTile(Tile **board, int size, TILETYPE tiletype, int lane, int user){
    if(user == 1){
        if(board[size - 1][lane - 1].type == LOCKED){
            cout << "A locked tile is preventing your tile from being added. I wouldn't do that agin." << endl;
        }
        else{
            if(board[size - 1][lane - 1].type == EMPTY){
                board[size - 1][lane - 1].type = tiletype;
            }
            else{
                for(int row = 0; row < size - 1; row++){
                    if(board[row][lane - 1].type == LOCKED){
                        continue;
                    }
                    else{
                        board[row][lane - 1].type = board[row + 1][lane - 1].type;
                    }
                }
            }
            board[size - 1][lane - 1].type = tiletype;
            board[size - 1][lane - 1].color = RED;
        }
    }
    else{
        if(board[lane-1][0].type == LOCKED){
            cout << "A locked tile is preventing the computer's tile from being added. Stupid computer." << endl;
        }
        else{
            if(board[lane-1][0].type == EMPTY){
                board[lane-1][0].type = tiletype;
            }
            else{
                for(int col = size-1; col>=0; col--){
                    if(board[lane-1][col].type == LOCKED){
                        continue;
                    }
                    else{
                        board[lane-1][col].type = board[lane-1][col - 1].type;
                    }
                }
            }
            board[lane-1][0].type = tiletype;
            board[lane-1][0].color = BLUE;
        }
    }
}

TILETYPE getTileType(char type){
    switch(type){
        case 'X':
            return LOCKED;
            break;

        case '-':
            return HORIZONTAL;
            break;

        case'+':
            return CROSS;
            break;

        case '|':
            return VERTICAL;
            break;

        case ' ':
            return EMPTY;
            break;
    }
    return EMPTY;
}

bool gameOver(Tile **board, int size){
    bool wins = false;

    //checking horizontally
    for (int i = 0; i < size; i++){
        for (int j = 0; j < size; j++){
            if (board[i][j].type == HORIZONTAL || board[i][j].type == CROSS){
                if (j == size - 1){
                    cout << "COMPUTER WINS. TRY BETTER NEXT TIME!!" << endl;
                    return true;
                }
                else{
                    continue;
                }
            }
            else{
                break;
            }
        }
    }

    //checking vertically
    for(int col = 0; col < size; col++){
        for(int row = 0; row < size; row++){
            if(board[row][col].type == VERTICAL || board[row][col].type == CROSS){
                if (row == size - 1){
                    cout << "YOU WIN!!" << endl;
                    return true;
                }
                else{
                    continue;
                }
            }
            else{
                break;
            }
        }
    }

    return false;
}