/*   computes machine epsilon: compile with gcc mepsilon.c -lm  */

#include <stdio.h>
#include <math.h>

int main() {

  //float eps = 1.0, temp; // change float to double for double precision 
  double eps = 1.0, temp; 

  do{

    eps=eps/2.0;
    temp=eps+1.0;
    
  }while(temp > 1.0);
  
  eps=2.0*eps;
  temp = log(eps)/log(2.0);

  printf("\n Machine Epsilon from C code:\n");
  printf(" eps = %.16g = 2^%g\n",eps, temp);
  printf("\n");

}
