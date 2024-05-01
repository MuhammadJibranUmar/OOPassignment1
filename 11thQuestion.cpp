#include <iostream>
using namespace std;

class Numbers {
public:
    Numbers(int n) {
        number = n;
    }

    void print() {
        if (number < 20) {
            cout << lessthan20[number] << endl;
        } else if (number < 100) {
            cout << tens[number / 10 - 2];
            if (number % 10 != 0) cout << " " << lessthan20[number % 10];
            cout << endl;
        } else if (number < 1000) {
            cout << lessthan20[number / 100] << " hundred ";
            if (number % 100 != 0) {
                printLessThan100(number % 100);
            } else {
                cout << endl;
            }
        } else if (number < 10000) {
            cout << lessthan20[number / 1000] << " thousand ";
            if (number % 1000 != 0) {
                printLessThan1000(number % 1000);
            } else {
                cout << endl;
            }
        }
    }

private:
    int number;
    static string lessthan20[20];
    static string tens[9];

    void printLessThan100(int n) {
        if (n < 20) {
            cout << lessthan20[n] << endl;
        } else {
            cout << tens[n / 10 - 2];
            if (n % 10 != 0) cout << " " << lessthan20[n % 10];
            cout << endl;
        }
    }

    void printLessThan1000(int n) {
        if (n < 100) {
            printLessThan100(n);
        } else {
            cout << lessthan20[n / 100] << " hundred ";
            if (n % 100 != 0) {
                printLessThan100(n % 100);
            } else {
                cout << endl;
            }
        }
    }
};

string Numbers::lessthan20[] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};
string Numbers::tens[] = {"twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety", "hundred"};

int main() {
    int n;
    cout << "Enter a number between 0 and 9999: ";
    cin >> n;
    Numbers n1(n);
    n1.print();

    return 0;
}
