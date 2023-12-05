#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#define SIZE 4 //arrays max size 
#define RANDOMUPPER 20 //Max random range
#define RANDOMLOWER 1 //Min random range

void Creat_Array_Get_Total_and_Average(double[][SIZE], int);
int GetRandom();
double Tright_BLeft(double[][SIZE], int);
double TLeft_Bright(double[][SIZE], int);
double RowAverage(double[], int);

int main(void){

    srand(time(NULL));
    double randomly_filled_array[SIZE][SIZE];
    double total_right = 0;
    double total_left = 0;

    printf("My name is Haskell Cappers\n");

    Creat_Array_Get_Total_and_Average(randomly_filled_array, SIZE);
    Tright_BLeft(randomly_filled_array, SIZE);
    TLeft_Bright(randomly_filled_array, SIZE);

    //sets the values for diagonals
    total_left = TLeft_Bright(randomly_filled_array, SIZE);
    total_right = Tright_BLeft(randomly_filled_array, SIZE);

    //Prints out the total found from each diagonal line.
    printf("Total of diagonal, top left to bottom right: %.2lf\n", total_left);
    printf("Total of diagonal, top right to bottom left: %.2lf\n", total_right);

    return 0;
}

//Fill the array with random numbers 1 - 20 and find the total number in the array
void Creat_Array_Get_Total_and_Average(double random_array[][SIZE], int size){
    double total = 0;
    int i = 0; //row
    int j = 0; //col
    double single_row_array[SIZE];

    
    for (i = 0; i < SIZE; i++){ 
        double avg = 0;
        for (j = 0; j < SIZE; j++){
            random_array[i][j] = GetRandom(); //assignes each element in the array with a random number
            printf("%.0lf \t",random_array[i][j]);
            single_row_array[j] = random_array[i][j];
            total += random_array[i][j];

        }
        avg = RowAverage(single_row_array, SIZE);
        printf("Average of row %d : %.2lf\n", i + 1, avg);
        printf("\n"); //just to add space between the arrays
    }
    printf("Total of element in array: %.2lf\n", total);
}

//gets a random number between 1 - 20
int GetRandom(){
    int randomnum = 0;
    randomnum = (rand() % (RANDOMUPPER - RANDOMLOWER)) + RANDOMLOWER;
    return randomnum;
}

//Finds the total number in a diagonal line from top left to bottom right of the array.
double TLeft_Bright(double diagonal_array[][SIZE], int size){
    double total = 0;
    int i = 0;

    for(i = 0; i < SIZE; i++){
        total += diagonal_array[i][i];
    }
    return total;
}

//Finds the total number in a diagonal line from top right to bottom left of the array.
double Tright_BLeft(double diagonal_array[][SIZE], int size){
    int i = 0;
    int j = SIZE;
    double total = 0;

    for(i = 0; i < SIZE; i++){
        j--;
        total += diagonal_array[i][j];
    }
    return total;
}

//take a single row from the array to get the average of that row. 
double RowAverage(double single_row_array[], int size){
    double avg = 0;
    double total = 0;
    int i = 0;
    int j = 0;

    for (i = 0; i < SIZE; i++){
        total += single_row_array[i];
    }
    avg = total / SIZE;
    return avg;
}