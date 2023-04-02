#include <iostream>

int main()
{
    /* Task:
        output numbers from 1 - 100

        multiples of 3 print Fizz for i
        multiples of 5 print Buzz for i
        multiples of both 5 & 3 print FizzBuzz
    */

    int i = 0;

    for (i = 1; i < 100; i++)
    {
        int fizz = i % 3;
        int buzz = i % 5;

        // if remainder of i/3 is zero print fizz
        if (fizz == 0)
        {
            std::cout << "Fizz\n";
        }
        // if remainder of i/5 is zero print buzz
        else if (buzz == 0)
        {
            std::cout << "Buzz\n";
        }
        // if remainder of i/3 & i/5 is zero print fizzbuzz
        else if (fizz == 0 && buzz == 0)
        {
            std::cout << "FizzBuzz\n";
        }
        else
        {
            std::cout << i << "\n";
        }
    }
}