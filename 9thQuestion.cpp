#include <iostream>
using namespace std;

class Circle{
    public:
        Circle(){
            radius = 0;
        }
        Circle(double r){
            radius = r;
        }
        void setRadius(){
            cout << "Enter radius: ";
            cin >> radius;
        }
        double getRadius(){
            return radius;
        }
        double getArea(){
            return PI * radius * radius;
        }
        double getCircumference(){
            return 2 * PI * radius;
        }

    private:
        double radius;
        double PI = 3.14159;
};

int main(){
    Circle c1;
    c1.setRadius();
    cout << "Diameter of c1: " << c1.getRadius() * 2 << endl; 
    cout << "Area of c1: " << c1.getArea() << endl;
    cout << "Circumference of c1: " << c1.getCircumference() << endl;

    return 0;
}