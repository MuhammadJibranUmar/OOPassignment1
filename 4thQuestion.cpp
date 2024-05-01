#include <iostream>
using namespace std;

class Employee{
    public:
        Employee(){
            empNumber = 0;
            empCompensation = 0;
        }

        Employee(int number, float compensation){
            empNumber = number;
            empCompensation = compensation;
        }

        void setdata(int number, float compensation){
            empNumber = number;
            empCompensation = compensation;
        }

        void getdata(){
            cout << "Employee Number: " << empNumber << endl;
            cout << "Employee Compensation: " << empCompensation << endl;
        }

    private:
        int empNumber;
        float empCompensation;
};

int main(){
    Employee obj1(1, 30.5);
    Employee obj2(2, 50);
    Employee obj3;

    obj3.setdata(3, 40.8);

    obj1.getdata();
    obj2.getdata();
    obj3.getdata();

    return 0;
}
