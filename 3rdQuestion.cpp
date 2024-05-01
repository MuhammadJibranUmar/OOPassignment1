#include <iostream>
using namespace std;

class Time{
    public:
        Time(){
            hours = min = sec;
        }

        Time(int h, int m, int s){
            hours = h;
            min = m;
            sec = s;
        }

        void display(){
            while(sec >= 60){
                sec -= 60;
                min++;
            }
            while(min >= 60){
                min -= 60;
                hours++;
            }
            cout << hours << ":" << min << ":" << sec << endl;
        }

        Time operator + (const Time &obj){
            Time result;

            result.hours = hours + obj.hours;
            result.min = min + obj.min;
            result.sec = sec + obj.sec;

            return result;
        }
    private:
        int hours, min, sec;
};

int main(){
    Time obj1(5, 65, 30);
    Time obj2(6, 23, 70);
    Time obj3;

    obj3 = obj1 + obj2;
    obj3.display();

    return 0;
}
