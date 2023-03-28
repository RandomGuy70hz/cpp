/* Task:
    ! Write a leap_year.cpp program that:
        * Takes a year as input.
        * Checks to see if the year is a four-digit number.
        * Displays whether or not the year falls on a leap year.

    ! There are 3 criteria that must be taken into account to identify a leap year:
        * If the year can be evenly divided by 4 then it is a leap year, however…
        * If that year can be evenly divided by 100, and it is not evenly divided by 400, then it is NOT a leap year.
        * If that year is evenly divisible by 400, then it is a leap year.
        *
        * // if y / 4 = 0                         -> leap year
        * // if y / 100 = 0 and y / 400 not=0     -> not leap year
        * // if y % 400 = 0                       -> leap year
*/

#include <iostream>

int main()
{
    // Takes a year as input:
    int y;
    std::cout << "Input a year: ";
    std::cin >> y;

    // checks if its a four digit number
    if (y <= 1000 || y >= 9999)
    {
        std::cout << "Invalid Year.\n";
    }
    // checks if y/4=0 and y/100!=0(inverse), or y/400=0
    else if (y % 4 == 0 && y % 100 != 0 || y % 400 == 0)
    {
        std::cout << "The year " << y << " is a leap year!\n";
    }
    // anything else
    else
    {
        std::cout << "Not a leap year.\n";
    }
}