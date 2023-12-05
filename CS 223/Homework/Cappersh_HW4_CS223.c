//Computes and displays the horizontal and vertical disctance of a watermalon shot from a cannon.
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define PI 3.14
#define GRAVITY 9.18
#define MIN_VELO 50
#define MAX_VELO 300
#define MIN_ANG 0
#define MAX_ANG 90

int main (void){
    //declared variables
    double degrees = 0;
    double time = 0;
    double hor_dist = 0;
    double vert_dist = 0;
    double velocity = 0;
    double radians = 0;

    printf("Haskell Cappers \n"); //prints my name
    do{
        printf("Enter the velocity of the cannon, must be between 50 and 300: \n");
        scanf("%lf", &velocity);
       if(velocity < MIN_VELO || velocity > MAX_VELO){ //error checking
            printf("Error! velocity must be between the range 50 and 300 \n");
        }
        
    }while(velocity < MIN_VELO || velocity > MAX_VELO); //checks to see if the velocity is between 50 and 300
    do{
        printf("Enter the angle of the cannon, must be between 0 and 90: \n");
        scanf("%lf", &degrees);
        if(degrees <= MIN_ANG || degrees <= MAX_ANG){ //error checking
            printf("Error! The angle of the cannon, must be between 0 and 90: \n");
        }    
    }
    while(degrees <= MIN_ANG || degrees >= MAX_ANG); //makes sure the degrees are between 0 and 90 but not including them
            radians = ((degrees * PI) / 180); // converts the angel to ragian
            printf("Time \t Horizontal Distance \t Vertical distance \n");
    
    for(time = 0; time <= 10; time = time + 0.5){
        hor_dist = (velocity * cos(radians) * time); //calculates the horizontal distance x time interval.
        vert_dist = (velocity * sin(radians) * time - ((GRAVITY * pow(time, 2)) / 2)); //calculates the vertical distance
        printf("%.2lf \t %.2lf \t %.2lf \n", time, hor_dist, vert_dist); //prints the table ou5
    }
    printf("\n"); // just adding an extra break between both graphs
    printf("Time \t Horizontal Distance \t Vertical distance \n"); //displays graph 2

    time = 0; //rests the value of time to 0
    vert_dist = 0; //rests the vertical distance to 0
    
    while(vert_dist >= 0){ //This lets the program run until the vert distance is equaled to 0.
        vert_dist = (velocity * sin(radians) * time - ((GRAVITY * pow(time, 2)) / 2)); //calculates the vertical distance
        printf("%.2lf \t %.2lf \t %.2lf \n", time, hor_dist, vert_dist);
        time = time + 0.5;
    }
    return 0;
}