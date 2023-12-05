#include <iostream>
#include <cmath>
using namespace std;

int main (){
	const int SIZE = 8; //number of students to calculate
	int height[SIZE]; //array to store height of 8 students
	int above_average[SIZE]; //array to check  the height of the students is above average
	int sum = 0, above_count = 0;
	float avg_height;

	for (int i = 0; i < SIZE; ++i){
		cout << "Enter height in inches of students #" << i + 1 << ": "; //user inputs the hight of 8 students
		cin >> height[i];
		sum += height[i];
	}
	cout << endl;
	avg_height = sum / static_cast<float>(SIZE); // Calculate average height of 8 students

	cout << "You entered: " << endl;

  for(int i = 0; i < SIZE; ++i){
    cout << "Height in inches of student #" << i + 1 << ":" << height[i] << endl;
    if(height[i] > avg_height){
      above_average[above_count] = height[i];
      above_count += 1;
    }
  }
	
	return 0;
}