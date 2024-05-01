#include <iostream>
using namespace std;

class Human{
    public:
        Human(){
            name = "Nauman";
            age = 22;
            gender = 'M';
            nationality = "Pakistani";

            cout << "Name =" << name << "\nAge: " << age << "\nGender: " << gender << "\nNationality: " << nationality << endl;
        }


        Human(string n, int a, char g, string c){
            name = n;
            age = a;
            gender = g;
            nationality = c;

            cout << "Name =" << name << "\nAge: " << age << "\nGender: " << gender << "\nNationality: " << nationality << endl;
        }
    private:
        string name;
        int age;
        char gender;
        string nationality;
};

int main(){
    Human obj1;
    cout << "---------------\n";
    Human obj2("Ali", 23, 'M', "Pakistani");
    return 0;
}
