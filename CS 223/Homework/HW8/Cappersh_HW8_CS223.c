#include<stdio.h>
#include<stdlib.h>
#include <math.h>
#include <string.h>

double Cal_Distance(double,double,double); //uses the distance formula to calculate the distance for each name on the location.txt file

/*This program is to read the flowing text file named “location.txt”. Each line of the file represents the name and x,y,z 
coordinate of an object in 3D space. Calculate the distance of each object with respect to 0,0,0 coordinate (where x,y, and z axes 
intersect), then write the names and the distances in the file called distance.txt and display the names, x,y,z coordinates and the 
distances on screen)*/
int main(void){
    double x; //first number in each row
    double y; //second number in each row
    double z; //third number in each row
    double distance = 0; //using the distance formula to find the distance for each name
    char name[10]; //name from file

    FILE *flocation = fopen ("location.txt","r"); //reads the txt file
    FILE *fdistance = fopen("distance.txt","w"); //creats and writes to the new txt file

    if(flocation == NULL){ //error checks to make sure it is opening the correct file
        printf("File does not exist. \n");
        printf("Please verify that you have the right input file\n");
    }else{
        fprintf(fdistance,"Name\t Distance\n"); //making header on the distance.txt file
        printf("Name\t X\t Y\t Z\t Distance\n"); //making the heard for the terminal output
       while(!feof(flocation)){ //while loop to run until the end of the file
           fscanf(flocation, "%s %lf %lf %lf", name, &x, &y, &z);
           distance = Cal_Distance(x,y,z);
           fprintf(fdistance, "%s\t %.2lf\n", name, distance);
           printf("%s\t %.0lf\t %.0lf\t %.0lf\t %.2lf\n", name, x, y, z, distance);
       }
    }
    fclose(flocation); //closes the location.txt file
    fclose(fdistance); //closes the distance.txt file 
    return 0;
}

double Cal_Distance(double x,double y,double z){
    double distance = 0;
    distance = sqrt(((pow(x,2)) + (pow(y,2)) + (pow(z,2))));

    return distance;
}