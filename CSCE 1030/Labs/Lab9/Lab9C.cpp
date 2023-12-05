#include <iostream>
#include <cmath>
#include <string>
using namespace std;

struct Record{
    string name;
    int feet, inches;
    float weight;
};
float calculateBMI(Record person);

int main (){
    float bmi;
    Record person;

    cout << "Enter the person's name: ";
    cin >> person.name;
    cout << "Enter the person's wight in pounds: ";
    cin >> person.weight;
    cout << "Enter the person's height in feet and inches: ";
    cin >> person.feet >> person.inches;

    bmi = calculateBMI(person);
    cout << "The BMI for " << person.name << " is: " << bmi << endl;

    return 0;

}
/*  Function: calculate BMI
    Parameters: height, weight
    Return: Returns the bmi calculation
    Description: Takes the information the user inputs and calculates the BMI
*/
float calculateBMI(Record person){
    int totalHeight = person.feet * 12 + person.inches;

    return (703 * person.weight) / pow(totalHeight, 2);
}