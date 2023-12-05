#include <iostream>
#include <cmath>
using namespace std;

const double PI = 3.14159;

float calcBaseArea(float r); // Calculates the total for the base area
float calcSideArea(float r, float h); // Calculates the total for the side area
void printSurfArea(float area_s, float area_b); //Takes the values for side and base area and adds them togeather

int main (){

	float h;
	float r;
	float base_area;
	float side_area;

	cout << "Enter the radius of the right cylinder in feet: ";
	cin >> r;
	
	cout << "Enter the height of the right cylinder in feet: ";
	cin >> h;

	base_area = calcBaseArea(r);
	cout << "Base surface area of right cylinder is " << base_area << " square feet. " << endl;

	side_area = calcSideArea(r,h);
	cout << "Side surface area of the right cylinder is " << side_area << " feet." << endl;

	printSurfArea(side_area, base_area);

	return 0;
}
/* Function: Calculats the base area
   Parameters: Radius
   Return: The value for the base area
   Description: Takes the valuse to calculate the area of the base
*/
float calcBaseArea(float r){
	return (2 * PI * pow(r, 2));
}
/* Function: Calculats the side area
   Parameters: Radius and Height
   Return: The value for the side area
   Description: Takes the valuse to calculate the area of the side of the cyilnder
*/
float calcSideArea(float h, float r){
	return h * (2 * PI * r);
}

/* Function: Calculats the total area
   Parameters:Side and base area totals
   Return: to total area of the cylinder
   Description: Takes the valuse of the side and base area and adds them togeather to get the total area
*/
void printSurfArea(float side_area, float base_area){
	float totalArea = 0;
	totalArea = side_area + base_area;
	cout << "The total surface area is " << totalArea << " square feet. " << endl;
}
