#include <iostream>
#include <cmath>
using namespace std;

int main(){
    const float gravity = 9.8;
    const float pi = 3.14159;
    long int buoyancy;
    double density;
    double volume;
    double radius;
    
    cout << "****************************************************************" << endl;
    cout << "             Computer Science and Engineering                   " << endl;
    cout << "              CSCE 1030 - Computer Science 1                    " << endl;
    cout << "Haskell Cappers   --   hac0078    --  haskellcappers@my.unt.edu " << endl;
    cout << "****************************************************************" << endl;
    cout << endl;

    cout << "Please enter the density of the liquid: ";
    cin >> density; 

    cout << "Please enter the buoyant force of the object: ";
    cin >> buoyancy;

    volume = buoyancy / (gravity * density); 
    
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(3);
    cout << "The volume of the sphere is: " << volume  << " meters cubed" << endl;

    radius = cbrt((3 * volume) / ( 4 * pi));
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);
    cout << "The radius of the sphere is: " << radius << " meters" << endl;

    return 0;
}