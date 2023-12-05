#include <iostream>
#include <cmath>
using namespace std;

int main(){
    float gravity;
    const float GRAV_CONSTANT = 6.673e-11;
    float mass;
    float radius;
    float height;
    float time;
    float gravity_2;

    cout << "Computer Science and Engineering" << endl;
    cout << "CSCE 1030 - Computer Science I" <<  endl;
    cout << "Haskell Cappers hac0078 haskellcappers@my.unt.edu" << endl;

    cout << "Enter mass in kg: ";
    cin >> mass;

    cout << "Enter radius in meter: ";
    cin >> radius;

    gravity = (GRAV_CONSTANT * mass) / (radius * radius);
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);

    cout << "The acceleration due to gravity is: " << gravity << " m/s^2" << endl;
    cout << "Enter height in feet: ";
    cin >> height;

    gravity_2 = gravity * 3.28;
    time = sqrt((2 * height) / gravity_2);
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);

    cout << "The object will hit the surface in: " << time << " seconds" << endl;
    return 0;
}
