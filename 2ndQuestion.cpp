#include <iostream>
using namespace std;

class TollBooth{
    public:
        TollBooth(){
            cars = amount = 0;
        }

        void payingCar(){
            cars++;
            amount += 0.5;
        }

        void nonPayingCar(){
            cars++;
        }

        void display() const{
            cout << "Total Cars: " << cars << ".\n" << "Total Amount: $" << amount << ".\n";
        }
    private:
        unsigned int cars;
        double amount;
};
int main(){
    TollBooth Booth;

    cout << "Press \'q\' for PayingCars and \'w\' for NonPayingCars. To Display record, press \'x\'.\nPress key: ";

    char option;
    cin >> option;

    while(option != 'x'){

        switch(option){
            case 'q':
                Booth.payingCar();
                break;
            case 'w':
                Booth.nonPayingCar();
                break;
            default:
                cout << "Press 'q' for PayingCars and 'w' for NonPayingCars.\nTry Again: ";
        }

        cin >> option;
    }

    Booth.display();

    return 0;
}
