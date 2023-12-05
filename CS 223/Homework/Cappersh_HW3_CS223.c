//Total area of the grass and the time it takes to mow the yard, or message about why mowing is not possible. 
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main (void){
  //declared variables
  double width_yard = 0;
  double lenght_yard = 0;
  double width_house = 0;
  double lenght_house = 0;
  double area_yard = 0;
  double area_house = 0;
  double area_grass = 0;
  double mow_time = 0;
  double mow_speed = 0;
  int rain = 0;
  
  printf("Haskell Cappers \n"); //prints my name

  printf("Is it raining today? Enter 1 for yes or 0 for no.\n"); //asks the user if it raining or not
  scanf("%d", &rain);

  //runs a check to see if it is raining or not, if it is raining it closes the program if its not it continues on
  if(rain == 1){
      printf("Sorry, it is raining, you cannot mow now\n"); //closes the program if its raining
  }
  else{
      printf ("Please enter the width of the house that needs to be mowed.\n");	//Asking the user to enter the width of the house
      scanf ("%lf", &width_house);

        if(width_house >= 100 && width_house <= 1000){ //verifies that the dimentions of the house are in the peramiters
          printf("Please enter the length of the house that needs to be mowed.\n"); //Asking the user to enter the length of the house
          scanf("%lf", &lenght_house);

          if(lenght_house >= 1000 || lenght_house <= 1000){ //verifies that the dimentions of the house are in the peramiters
              printf("Please enter the width of the yard that needs to be mowed.\n"); //Asking the user to enter the width of the yard
              scanf("%lf", &width_yard);

              if(width_yard >= 1000 || width_yard <= 1000){ //verifies that the dimentions of the house are in the peramiters
                  printf("Please enter the length of the yard that needs to be mowed.\n"); //Asking the user to enter the length of the yard
                  scanf("%lf", &lenght_yard);

                  if(lenght_yard >= 1000 || lenght_yard <= 1000){ //verifies that the dimentions of the house are in the peramiters
                      printf("Please enther the speed of the mower. The values should be between 1.5 and 3.0\n"); //Asking the user for the speed of the mower
                      scanf("%lf", &mow_speed);
                      
                      if(mow_speed >= 1.5 || mow_speed <= 3.0){ //verifies that the speed of the mowers are in the peramiters
                          area_yard = width_yard * lenght_yard;
                          area_house = width_house * lenght_house;
                          area_grass = area_yard - area_house;
                          
                          //checks to see if the area of the house is small than the area of yard, if the yard is bigger then the house it closes the program if its smaller it continues on
                          if(area_yard  > area_house){
                              mow_time = area_grass / (mow_speed * 60);
                              printf ("The total area to be mowed is %.2lf square feet and it takes %.2lf minutes to mow it\n", area_grass, mow_time); // prints to the user how the area of the yard was and how long it would take for it to be mowed in min.
                          }
                          else{
                              printf ("Error, The area of the yard should be bigger than the house. Please re-run the program\n"); //closes the program if the area of the house is small then the yard 
                          }
                      }
                      else{
                          printf("Sorry the values you entered are not valid. The mow speed should be between 1.5 and 3.0\n"); //closes the program if the speed of the mower is not in the peramiters given.
                        }
                  }
                  else{
                      printf("Sorry the values you entered are not valid. The length of the yard should be between 100 and 1000\n"); //closes the program if the length of the yard are not in the peramiters 
                  }
              }
              else{
                  printf("Sorry the values you entered are not valid. The width of the yard should be between 100 and 1000\n"); //closes the program if the width of the yard are not in the peramiters 
              }
          }
          else{
              printf("Sorry the values you entered are not valid. The length of the house should be between 100 and 1000\n"); //closes the program if the length of the house are not in the peramiters 
          }
      }
      else{
          printf("Sorry the values you entered are not valid. The width of the house should be between 100 and 1000\n"); //closes the program if the width of the house are not in the peramiters 
      }
  }
  return 0;
  
}