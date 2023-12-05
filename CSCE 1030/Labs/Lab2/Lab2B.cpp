#include <iostream>
using namespace std;

int main (){
	int miles; 
	float  km;

	cout << "how many miles did you walk today?";
	cin >> miles;
	km = miles * 1.609;
	cout << "You walked " << km << " kilometers today!";

	return 0;
}
	