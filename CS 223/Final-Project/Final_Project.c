#include<stdio.h>
#include<stdlib.h>
#include <math.h>
#include <string.h>
#define SIZE 10
#define SPEED 25

struct Astronaunts{ //struct to check user name and pins
   char name[SIZE];
   int pin;
};

struct Asteroids{
    char ID[SIZE];
    double x;
    double y;
    double z;
    double distance;
};


double DistanceCalc(double,double,double); //function to caculate the distance from the spaceship to the asteroids
int UserCheck(struct Astronaunts *astronaut);
double WritAsteroids(struct Asteroids *asteroids);

int main(void){
    struct Astronaunts astronaut;
    char name[SIZE];
    double distance = 0;
    double cord_x = 0;
    double cord_y = 0;
    double cord_z = 0;
    int flag = 0;

    flag= UserCheck(&astronaut);

   if(flag == 1){
       FILE *Fasteroids = fopen("asteroids.txt","r"); ///This opens the asteroids text file
    FILE *Fdistance = fopen("distance.txt","w");///This opens the distance text file

    if(Fasteroids == NULL){
        printf ("File does not exist.\n");
        printf("please check the existence of the input file\n");
    }else{
        while(!feof(Fasteroids)){
            fscanf(Fasteroids,"%s %lf %lf %lf ",name, &cord_x, &cord_y, &cord_z); ///Scanning in Name and x y z
            distance = DistanceCalc(cord_x, cord_y, cord_z);  ///Calling your function to calculate Distance
            printf("%s %.2lf %.2lf %.2lf %.2lf \n", name, cord_x, cord_y, cord_z ,distance); //Print name x y z and distance to your output screen
            fprintf (Fdistance, "%s %.2lf %.2lf %.2lf %.2lf \n", name, cord_x, cord_y, cord_z ,distance); ///Print the name and disrtance to file
        }
     }
    fclose(Fasteroids);
    fclose(Fdistance);
 
    }else{
        printf("You have entered your username and pin incorrectly to many times");
    }
    return 0;
}

double DistanceCalc(double cord_x,double cord_y,double cord_z){
    double distance = 0;
    distance = sqrt(pow(cord_x,2)+pow(cord_y,2)+pow(cord_z,2));
    return distance;
}

int UserCheck(struct Astronaunts *astronaut){
    int i;
    int attemps = 0;
    int correct_name = 0;
    int correct_pin = 0;
    int pin = 0;
    char name[10];
    FILE *Fusers = fopen("ident.txt","r" );
    for(i = 0; i < 6; i++){
        fscanf(Fusers, "%s\t %d\n", (astronaut+i)->name, &(astronaut+i)->pin); }
        fclose(Fusers);

        //while(correct_name != 1 && correct_pin != 1){
    do{
        printf("Please enter your username:\n");
        scanf("%s", name);
        printf("Please enter your pin:\n");
        scanf("%d", &pin);

        for(i = 0; i < 6; i++){
            if(strcmp((astronaut+i)-> name, name) == 0 && (astronaut+i)->pin == pin){
                correct_name = 1;
            }
        }
        if(correct_name==0){
            printf("Username or pin was incorect! Please try again\n");
            attemps++;
        }
        }while(attemps <= 3&& correct_name==0);
return(correct_name);
}
double WritAsteroids(struct Asteroids *asteroids){
    int i;
    int j;
    double speed = 25;
    double impact = 0;

    FILE *Fasteroids = fopen("asteroids.txt","r"); ///This opens the asteroids text file
    FILE *Fdistance = fopen("distance.txt","w");///This opens the distance text file

    if(Fasteroids == NULL){
        printf ("File does not exist.\n");
        printf("please check the existence of the input file\n");
    }else{
        while(!feof(Fasteroids)){
            fscanf(Fasteroids,"%s %lf %lf %lf ", (asteroids + i)->ID, &(asteroids + i)->x, &(asteroids + i)->y, &(asteroids + i)->z); ///Scanning in Name and x y z
            (asteroids + i)->distance = DistanceCalc((asteroids + i)->x, (asteroids + i)->y, (asteroids + i)->z);  ///Calling your function to calculate Distance
            printf("%s %.2lf %.2lf %.2lf %.2lf \n", (asteroids + i)->ID, &(asteroids + i)->x, &(asteroids + i)->y, &(asteroids + i)->z); //Print name x y z and distance to your output screen
            fprintf (Fdistance, "%s %.2lf %.2lf %.2lf %.2lf \n", (asteroids + i)->ID, (asteroids + i)->x, (asteroids + i)->y, (asteroids + i)->z); ///Print the name and disrtance to file
            if((asteroids + i)->distance < 750){
                impact = (asteroids + i)->distance / SPEED;
                printf("WARNING - WARNING - WARNING \n");
                printf("Nearest asteroid %s is at %lf km away\n", (asteroids + i)->ID,(asteroids + i)->distance);
                printf("Time to impact %lf seconds\n", impact);
            }
        }
    }
    fclose(Fasteroids);
    fclose(Fdistance);

    for(i = 0; i < 10; i++){
        printf("%c", asteroids[i].ID);
        for(j = 0; j < asteroids[i].distance; j++){
            printf("*");
        }
    }
}