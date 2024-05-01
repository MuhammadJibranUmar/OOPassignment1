#include <iostream>
using namespace std;

class Int{
    public:
        Int():variable(0){}

        Int(int value){
            variable = value;
        }

        void display(){
            cout << variable << endl;
        }

        Int operator +(Int obj){
            Int temp;
            temp.variable = variable + obj.variable;
            return temp;
        }
    private:
        int variable;
};

int main(){
    Int obj1(30);
    Int obj2(300);
    Int obj3;

    obj3 = obj1 + obj2;
    obj3.display();

    return 0;
}
