#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#define ROWMAX 6 //arrays max row
#define COLMAX 3 //arrays max columns 
#define RANDOMUPPER 99 //Max random range
#define RANDOMLOWER 1 //Min random range

double TriFill(); //function to use a 2d array to fill the sides of a triangle
double AreaCalc(double,double,double); //takes the valuse from the filled trianle to calculate the area of the triangle
double GetRandom(); // function to get random numbers from 1-99 to use for the sides of the triangle
int ValidTri(double,double,double); //function to see if side a + side b of the triangle is greater then side c of the triangle

//This program will take 18 random numbers to make 6 triangles, if the triangles are valid it will calcualte the area of the said triangle.
int main(void){
    srand(time(NULL)); //seedds the random numbers
    
    printf("Haskell Cappers \n");

    Trifill();

    return 0;
}

double TriFill(){
    int row = 0;
    int col = 0;
    int validtri = 0;
    double tri_area = 0;
    double filledtri[ROWMAX][COLMAX];

    printf("A \t B \t C \n"); //displays A B C to make the grid for the tirangles

    for(row = 0; row < ROWMAX; row++){
        printf("Tirangle %d \n", row + 1); //prints out what triangle its on to the uesr
        for(col = 0; col < COLMAX; col++){
            filledtri[row][col] = GetRandom();
            printf("%d\t", filledtri[row][col]);
        }
        validtri = ValidTri(filledtri[row][0], filledtri[row][1], filledtri[row][2]); //after fillin all the columns if checks to see if the triangle is a valid triangle
        if(validtri == 1){
            printf("Valid\n");
            tri_area = AreaCalc(filledtri[row][0], filledtri[row][1], filledtri[row][2]); //if the triangle is valid it finds the area of said triangle
            printf("The area of Triangle %d is: %.2lf\n", row + 1, tri_area); 
        }
        else{
            printf("Not Valid\n");
        }
    }
}

double AreaCalc(double sidea, double sideb, double sidec){
    double perimeter = 0;
    double a = sidea; //side a of the triangle filledtri[row][0]
    double b = sideb; //side a of the triangle filledtri[row][1]
    double c = sidec; //side a of the triangle filledtri[row][2]
    double area = 0;

    area = sqrt(perimeter * (perimeter - a) * (perimeter - b) * (perimeter - c)); //formula to find the area of any triangle

    return area;
}

double GetRandom(){
    double randomnum = 0;
    randomnum = (rand() % RANDOMUPPER - RANDOMLOWER) + RANDOMLOWER;
    return randomnum;
}

int ValidTri(double sidea, double sideb, double sidec){
    int validtri = 0;

    if(sidea + sideb > sidec){ //error checking to see if side a + side b of the triangle is greater then side c
        validtri = 1; //true
    }
    else{
        validtri = 0; //false
    }
    return validtri; //returns true or false depending on the value from the if statment
}