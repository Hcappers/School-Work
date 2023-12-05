#include <iostream>
using namespace std;

int main(){
  int grade;
  int count = 0;
  int numGrades;
  double sum = 0;
  double average;

  cout << "How many grades would you like to enter? ";
  cin  >> numGrades;
  
  while (count < numGrades){
    cout << "Enter grade: ";
    cin  >> grade;
    sum += grade;
    count++;
  }

  average = sum/numGrades;
  cout << "The average is " << average << endl;

  return 0;
}