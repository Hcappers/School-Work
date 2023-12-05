#include <iostream>
#include <cmath>
using namespace std;

int main (){
	float Value_1, Total;
	const float Sales_Tax = 1.0825;	
	
	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(2);
	cout << "What is the sub total amount for the purchase? ";
	cin >> Value_1;
	Total = Value_1 * Sales_Tax;
	cout << "The total amount after tax is $ " << Total << endl;

	return 0;
}
	