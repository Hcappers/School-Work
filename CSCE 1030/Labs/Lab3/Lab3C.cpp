#include <iostream>
#include <cmath>
using namespace std;

int main (){
	const float OFFSET = 0.32;
	float var1 = 39.4;
	float var2 = 7.5;
	char var3 = '4';
	float var4 = 22;
	float var5;

	var5 = (var4 - var1) / var2 + var3 + OFFSET;
	cout << var5 << endl;
	
	return 0;
}