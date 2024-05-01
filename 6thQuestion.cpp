#include <iostream>
using namespace std;

class Area{
    public:
        Area(double length){
            area = length * length;

            cout << "Area of Square = " << area << endl;
            }

        Area(double base, double height){
            area = 0.5 * base * height;

            cout << "Area of Triangle = " << area << endl;
        }

        Area(int width, int length){
            area = width * length;

            cout << "Area of Rectangle = " << area << endl;
        }

    private:
        double area;
};

int main(){
    Area obj1(30);
    Area obj2(23, 5);
    Area obj3(4, 32);

    return 0;
}
