#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring> 

using namespace std;

void get_input(int& num1, float& num2);
void modify(int& num1, float& num2);

int main (){
    int num1;
    float num2;

    get_input(num1, num2);
    cout << "Original valuse: num1 = " << num1 << " num2 = " << num2 << endl;

    modify(num1, num2);
    cout << "Num1 value is: " << num1 << endl;
    cout << "Num2 value is: " << num2 << endl;


    return 0;
}

void get_input(int& num1, float& num2){
    cout << "Enter an integer: ";
    cin >> num1;
    cout << "Enter a floating-point number: ";
    cin >> num2;

    return; 
}

void modify(int& num1, float& num2){
    srand(time(NULL));
    num1 = num1 * (rand() % 11 + 20);
    num2 = log(num2);

    return;
}