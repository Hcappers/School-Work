#include <iostream>
#include <cmath>
using namespace std;

double bb_4ac();
void get_coeff(double& coeff, int pos);

int main (){
	
	double y;
	
	y = bb_4ac();

	cout << " The total valus for the discriminant is " << y << endl;
	return 0;
}
/* Function: Calculats the discriminant
   Parameters: Coefficients for a, b, and c
   Return: The value for the discriminant
   Description: This function take the valus the user inputs for a, b, and c. Then calculats the total value for the discriminant
*/
double bb_4ac(){
	double a, b ,c;
	get_coeff(c,0);
        get_coeff(b,1);
        get_coeff(a,2);
	return (b*b-4*a*c);
}

/* Function: Give the user inputed valuse for a, b, and c
   Parameters: none
   Return: user inputed valuse
   Description: Function to ask the user to input values for a, b, and c. Then passing the information over to the bb_4ac function.
*/

void get_coeff(double& coeff, int pos){
	cout << "Enter a  valuse for " <<  pos << " ";
	cin >> coeff;
}