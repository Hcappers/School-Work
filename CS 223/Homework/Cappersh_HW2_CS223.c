//This program is to take the user enterened data of the width and length of the yard to find area and the mow time of the yard.
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main (void){
  //declared variables
  double width_house = 0;
  double lenght_house = 0;
  double width_yard = 0;
  double lenght_yard = 0;
  double area_yard = 0;
  double area_house = 0;
  double area_grass = 0;
  double mow_time = 0;

  printf("Haskell Cappers \n"); //prints my name out.

  printf ("Please enter the width of the house that needs to be mowed.\n");	//Asking the user to enter the width of the house
  scanf ("%lf", &width_house);
  printf ("Please enter the length of the house that needs to be mowed.\n"); //Asking the user to enter the length of the house
  scanf ("%lf", &lenght_house);

  printf ("Please enter the width of the yard that needs to be mowed.\n");	//Asking the user to enter the width of the yard
  scanf ("%lf", &width_yard);
  printf ("Please enter the length of the yard that needs to be mowed.\n");	//Asking the user to enter the length of the yard
  scanf ("%lf", &lenght_yard);

  area_yard = width_yard * lenght_yard;
  area_house = width_house* lenght_house;
  area_grass = area_house - area_yard;
  mow_time = area_grass / (2 * 60);	

  printf ("The total area to be mowed is %.2lf square feet and it takes %.2lf minutes to mow it\n", area_yard, mow_time); //prints to the 

  return 0;
}