#include <iostream>

enum Months
{
    January, February, March,
    April, May, June,
    July, August, September,
    October, November, December
};

// Overloading the prefix "++" operator
Months operator++(Months &month)
{
    if(month == December)
    {
        month = January;
    }
    else
    {
        month = (Months) (month + 1);
    }
    return month;
}

// Overloading the postfix "++" operator
Months operator++(Months &month, int)
{
    Months old_month = month;
    operator++(month);
    return old_month;
}

// Overloading the prefix "--" operator
Months operator--(Months &month)
{
    if(month == January)
    {
        month = December;
    }
    else
    {
        month = (Months) (month - 1);
    }
    return month;
}

// Overloading the postfix "--" operator
Months operator--(Months &month, int)
{
    Months old_month = month;
    operator--(month);
    return old_month;
}

// Getting the name of month according to enum Months value
const char* getName(Months month)
{
    switch (month)
    {
        case January:
            return "January";
        case February:
            return "February";
        case March:
            return "March";
        case April:
            return "April";
        case May:
            return "May";
        case June:
            return "June";
        case July:
            return "July";
        case August:
            return "August";
        case September:
            return "September";
        case October:
            return "October";
        case November:
            return "November";
        default:
            return "December";
    }
}

int main()
{
    std::cout << "**Testing the operator ++ for enum Months: " << std::endl;
    for(Months monthOfYear = August; monthOfYear != February; monthOfYear++)
    {
        std::cout << getName(monthOfYear) << std::endl;
    }

    std::cout << "\n**Testing the operator -- for enum Months: " << std::endl;
    for(Months monthOfYear = June; monthOfYear != November; monthOfYear--)
    {
        std::cout << getName(monthOfYear) << std::endl;
    }

    std::cout << "\nDone";

    return 0;
}