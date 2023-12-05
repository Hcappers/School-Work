//this program calculates the max height, max range and the time in flight for a ball launched out of a cannon
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define PI 3.14
#define GRAVITY 9.18
#define MIN_VELO 20
#define MAX_VELO 800
#define MIN_ANG 5
#define MAX_ANG 80
#define FullAngle 180

double PeakHeight(double, double);
double HorizontalRange(double, double);
double TimeInFlight(double, double);
int VelocityCheck(double);
int AngleCheck(double);

int main (void){
    //declared variables
    double degrees = 0;
    double velocity = 0;
    double radians = 0;    
    double peakheight = 0;
    double horizontalrange = 0;
    double timeinflight = 0;
    int option = 0;
    int velocitycorrect = 0;
    int anglecorrect = 0;


    printf("Haskell Cappers \n"); //prints my name
    do{
        printf("Enter the velocity of the cannon, must be between 20 and 800: \n"); //user imputs the inital velocity
        scanf("%lf", &velocity);
        velocitycorrect = VelocityCheck(velocity); //error checks to make sure its within the bounds of 20 and 800
        
    }while(velocitycorrect != 1); //checks to see if the velocity is between 50 and 300
    do{
        printf("Enter the angle of the cannon, must be between 0 and 80: \n"); //user inputs the angle of the cannon
        scanf("%lf", &degrees);
        anglecorrect = AngleCheck(degrees); // error checks that the angle is within the bounds of 20 and 80
    }
    while(anglecorrect != 1); //makes sure the degrees are between 20 and 80 but not including them
    
    radians = (degrees * PI) / FullAngle; // converts the angel to radians
    
    printf("Press 1 for Peak Height \n");
    printf("Press 2 for Horizontal Range \n");
    printf("Press 3 for Total time in flight \n");
    scanf("%d", &option);

    switch(option){ //lets the user choose which option they want to pick to caculate.
        case 1: 
           peakheight = PeakHeight(velocity,radians);
            printf("The total time of flight is = %.2lf\n", peakheight);
            break;
        case 2:
            horizontalrange = HorizontalRange(velocity,radians);
            printf("The maximum height reached is = %.2lf\n", horizontalrange);
            break;
        case 3:
            timeinflight = TimeInFlight(velocity,radians);
            printf("The total time in flight is = %.2lf\n", timeinflight);
            break;
        default:
            if(option < 0){
                printf("Error! That is not an option \n");
            }
            if(option > 3){
                printf("Error! That is not an option \n");
                }
        }
    return 0;
}

double PeakHeight(double velocity, double radians){
    double heighttotal = 0;
    heighttotal = (pow(velocity, 2) * pow(sin(radians), 2)) / (2 * GRAVITY);
return heighttotal;
}

double HorizontalRange(double velocity, double radians){
    double rangetotal = 0;
    rangetotal = (pow(velocity, 2) * (2 * sin(radians))) / GRAVITY;
return rangetotal;
}

double TimeInFlight(double velocity, double radians){
    double totaltime = 0;
    totaltime = (2 * velocity * sin(radians)) / GRAVITY;
return totaltime;
}

int VelocityCheck(double velocity){
    int velocitycorrect = 0;
    if(velocity < MIN_VELO || velocity > MAX_VELO){ //error checking
            printf("Error! velocity must be between the range 20 and 800 \n");
            velocitycorrect = 0;
        }
        else{
            velocitycorrect = 1;
        }
    return velocitycorrect;
}

int AngleCheck(double degrees){
    int anglecorrect = 0;
    if(degrees < MIN_ANG || degrees > MAX_ANG){ //error checking
        printf("Error! The angle of the cannon, must be between 0 and 80: \n");
            anglecorrect = 0;
        }
        else{
            anglecorrect = 1;
        }
    return anglecorrect;
}