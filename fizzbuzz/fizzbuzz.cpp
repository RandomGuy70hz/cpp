#include <iostream>

int main()
{
    /* Task:
        output numbers from 1 - 100

        multiples of 3 print Fizz for i
        multiples of 5 print Buzz for i
        multiples of both 5 & 3 print FizzBuzz
    */

    // variables
    int i = 0;
    // int fizz = i % 3;
    // int buzz = i % 5;

    for (i = 1; i < 100; i++)
    {

        // if remainder of i/3 is zero print fizz
        if (i % 3 == 0)
        {
            std::cout << "Fizz\n";
        }
        // if remainder of i/5 is zero print buzz
        else if (i % 5 == 0)
        {
            std::cout << "Buzz\n";
        }
        // if remainder of i/3 & i/5 is zero print fizzbuzz
        else if (i % 3 == 0 && i % 5 == 0)
        {
            std::cout << "FizzBuzz\n";
        }
        else
        {
            std::cout << i << "\n";
        }
    }
}