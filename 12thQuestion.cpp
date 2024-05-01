#include <iostream>
#include <string>

using namespace std;

class Month
{
public:
    Month() : monthNumber(1), name("January") {}

    Month(string monthName)
    {
        setMonthByName(monthName);
    }

    void setMonthByName(string monthName)
    {
        static string months[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
        for (int i = 0; i < 12; ++i)
        {
            if (months[i] == monthName)
            {
                monthNumber = i + 1;
                name = monthName;
                break;
            }
        }
    }

    void setMonthByNumber(int monthNum)
    {
        static string months[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
        if (monthNum >= 1 && monthNum <= 12)
        {
            monthNumber = monthNum;
            name = months[monthNum - 1];
        }
    }

    string getMonthName() const
    {
        return name;
    }

    int getMonthNumber() const
    {
        return monthNumber;
    }

    Month &operator++()
    {
        monthNumber = monthNumber % 12 + 1;
        setMonthByNumber(monthNumber);
        return *this;
    }

    Month operator++(int)
    {
        Month temp = *this;
        ++*this;
        return temp;
    }

    Month &operator--()
    {
        monthNumber = (monthNumber - 2 + 12) % 12 + 1;
        setMonthByNumber(monthNumber);
        return *this;
    }

    Month operator--(int)
    {
        Month temp = *this;
        --*this;
        return temp;
    }

private:
    int monthNumber;
    string name;
};

int main()
{
    Month m1("April");
    cout << m1.getMonthName() << endl;
    cout << m1.getMonthNumber() << endl;
    m1++;
    cout << m1.getMonthName() << endl;
    cout << m1.getMonthNumber() << endl;
    m1--;
    cout << m1.getMonthName() << endl;
    cout << m1.getMonthNumber() << endl;
    return 0;
}