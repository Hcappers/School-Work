#include <iostream>
#include <string>
using namespace std;

struct Employee{
    string name;
    int experience;
    double bonus;
};

int main(){
    Employee *employee_ptr;
    employee_ptr = new Employee;

    // Assining the name and years of experience to the employee
    cout << "Enter the employees name: ";
    cin >> employee_ptr->name;
    cout << "Enter number of years of experience: ";
    cin >> employee_ptr->experience;

    // Assigning the bonus depending on the years experience
    employee_ptr->bonus = (employee_ptr->experience > 10) ? 5000.00 : 3000.00;

    // Displaying back the name and the amount for the bonus
    cout << "Employee name: " << employee_ptr->name << endl;
    cout << "Employee bonus: " << employee_ptr->bonus << endl;

    delete employee_ptr;

    return 0;
}