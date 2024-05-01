#include <iostream>
using namespace std;

class Distance{
    public:
        Distance(){
            feet = 0;
            inches = 0;
        }

        void setDistance(){
            cout << "Enter feet: ";
            cin >> feet;
            cout << "Enter inches: ";
            cin >> inches;
        }

        Distance operator + (Distance obj){
            Distance temp;
            temp.feet = feet + obj.feet;
            temp.inches = inches + obj.inches;

            while(temp.inches >= 12){
                temp.inches -= 12;
                temp.feet++;
            }

            return temp;
        }

        Distance operator - (Distance obj){
            Distance temp;
            temp.feet = feet - obj.feet;
            temp.inches = inches - obj.inches;

            while(temp.inches < 0){
                temp.inches += 12;
                temp.feet--;
            }

            return temp;            
        }

        Distance operator * (Distance obj){
            Distance temp;
            temp.feet = feet * obj.feet;
            temp.inches = inches * obj.inches;

            while(temp.inches >= 12){
                temp.inches -= 12;
                temp.feet++;
            }

            return temp;
        }
        
        Distance& operator ++ (){
            feet++;

            while(inches >= 12){
                inches -= 12;
                feet++;
            }

            return *this;
        }

        Distance operator ++ (int){
            Distance temp = *this;
            feet++;

            while(inches >= 12){
                inches -= 12;
                feet++;
            }

            return temp;
        }

        void display(){
            cout << "Distance: " << feet << "\"" << inches << "\'\n";
        }
    private:
        int feet;
        int inches;
};

void mainMenu(){
    cout << "Main Menu\n";
    cout << "[1]. Add two distances\n";
    cout << "[2]. Subtract two distances\n";
    cout << "[3]. Multiply two distances\n";
    cout << "[4]. Pre Increment a distance\n";
    cout << "[5]. Post Increment a distance\n";
    cout << "[6]. Exit\n";
    cout << "Enter your choice: ";
}

int main(){
    Distance d1, d2;
    int choice;

    do{
        mainMenu();
        cin >> choice;
                
        switch (choice)
        {
        case 1:
            d1.setDistance();
            d2.setDistance();
            (d1 + d2).display();
            break;
        case 2:
            d1.setDistance();
            d2.setDistance();
            (d1 - d2).display();
            break;
        case 3:
            d1.setDistance();
            d2.setDistance();
            (d1 * d2).display();
            break;
        case 4:
            d1.setDistance();
            (++d1).display();
            break;
        case 5:
            d1.setDistance();
            (d1++).display();
            cout << "After post increment: ";
            d1.display();
            break;
        case 6:
            cout << "Exiting...\n";
            break;    
        default:
            cout << "Invalid choice\n";
            break;
        }
    }while (choice != 6);
    
    return 0;
}