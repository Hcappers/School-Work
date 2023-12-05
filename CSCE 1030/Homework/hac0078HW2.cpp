#include <iostream>
#include <string>
#include <unistd.h>
using namespace std;

void intro(); //This function is for the intro dedicated by instructions.
void triangle_output(int height, string triangle); // This is display the triangle after the user has defined the height
void triangle_vertical(int DISTNACE, int height); //This function is to move the triangles down.
void triangle_horizontal(int DISTNACE, int height, string triangle); // This function is to move the triangles to horizontally.

int main(){
    enum Directions {HORIZONTAL = 'H', VERTICAL = 'V'}; // This is for the switch statements
    const int DISTANCE = 10; // This is for how many times the triangle will move
    int height; // The height of the triangle
    char repeat; // This is for if the user wants to repart the program
    char move; // Which way the user wants to move the triangle
    bool do_again; // This is to keep the program running untill the user wants to quit
    string triangle; // This is using string appendex in the function triangel_output.

    intro();
    
    do{ //This is so the program will continue untill the user dose not want to continue.
        cout << "Please enter the height of you want to use: ";
        cin >> height;

        triangle_output(height, triangle);

        cout << "Which direction? H for horizontal, V for vertical:";
        cin >> move;
        move = toupper(move);

        switch(move){
            case HORIZONTAL:
            triangle_horizontal(DISTANCE, height, triangle);
                do_again = false;
            break;

            case VERTICAL:
                triangle_vertical(DISTANCE, height);
                do_again = false;
            break;

            default: 
                do_again = true; 
                cout << "That is an invalid key" << endl;
            break;
        }

        cout << "Do you want to replay? y/n: ";
        cin >> repeat;

        do_again = toupper(repeat) == 'N' ?  true : false;

    }while(!do_again);
    
    return 0;
}

void intro(){
    cout << "*******************************************************************" << endl;
    cout << "*            Computer Science and Engineering                     *" << endl;
    cout << "*             CSCE 1030 - Computer Science 1                      *" << endl;
    cout << "* Haskell Cappers   --   hac0078    --  haskellcappers@my.unt.edu *" << endl;
    cout << "*******************************************************************" << endl;
    cout << endl;
}

void triangle_output(int height, string triangle){
    for(int i = 1; i <= height; ++i){
        for(int j = 1; j <= height - i; ++j){
            triangle += " ";
        }
        for(int k = 1; k <= 2 * i - 1; ++k){
            triangle += "*";
        }
        triangle += '\n';
    }
        cout << triangle << endl;
}

void triangle_vertical(int DISTANCE, int height){ 
    for(int l = 1; l <= DISTANCE; ++l){
        sleep(1);
        cout << "\033[2J\033[1;1H";
        for(int i = 1; i <= height; ++i){
            for(int j = 1; j <= height - i; ++j){
                cout << " ";
            }
            for(int k = 1; k <= 2 * i - 1; ++k){
                cout << "*";
            }
            cout << endl;
        }
    }
}

void triangle_horizontal(int DISTNACE, int height, string triangle){
    cout << "This part was not completed. Please try again! Yikes. " << endl;
    triangle_output(height, triangle);
}