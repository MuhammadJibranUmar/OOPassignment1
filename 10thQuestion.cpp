#include <iostream>
#include <string>

using namespace std;

class Payroll {
public:
    Payroll(double hourlyRate = 0) : hourlyRate(hourlyRate), numberOfHours(0), totalPay(0) {}

    void setHours(int hours) {
            numberOfHours = hours;
            calculatePay();
    }

    double getTotalPay() const {
        return totalPay;
    }

private:
    void calculatePay() {
        totalPay = hourlyRate * numberOfHours;
    }

    double hourlyRate;
    int numberOfHours;
    double totalPay;
};

int main() {
    Payroll employees[7] = { Payroll(10), Payroll(12), Payroll(15), Payroll(11), Payroll(13), Payroll(14), Payroll(16) };

    for (int i = 0; i < 7; ++i) {
        int hours;
        cout << "Enter number of hours worked for employee " << (i + 1) << ": ";
        cin >> hours;
        if (hours > 0 && hours <= 60) {
        employees[i].setHours(hours);
        }
        else {
            cout << "Invalid number of hours. Please enter a value between 1 and 60.\n";
            i--;
        }
    }

    for (int i = 0; i < 7; ++i) {
        cout << "Total pay for employee " << (i + 1) << " is: " << employees[i].getTotalPay() << "\n";
    }

    return 0;
}