#include <iostream>
#include <cmath>

int main()
{
    // Ask user if they want to add, subtract, multiply, divide.
    std::cout << "Choose one of the following: Add = 1, Subtract = 2, Multiply = 3, Divide = 4 \nEnter your selection: ";
    double reply, number1, number2, answer;

    // store selection in variable
    std::cin >> reply;

    if (reply == 1)
    {
        // addition
        std::cout << "\nYou have chosen addition.\n";

        std::cout << "Input your first number: ";
        std::cin >> number1;

        std::cout << "Input your second number: ";
        std::cin >> number2;

        // calculate
        answer = number1 + number2;

        // Return answer
        std::cout << "Your answer is:" << answer << "\n";
    }
    else if (reply == 2)
    {
        // subtraction
        std::cout << "\nYou have chosen subtraction.\n";

        std::cout << "Input your first number: ";
        std::cin >> number1;

        std::cout << "Input your second number: ";
        std::cin >> number2;

        // calculate
        answer = number1 - number2;

        // Return answer
        std::cout << "Your answer is: " << answer << "\n";
    }
    else if (reply == 3)
    {
        // multiply
        std::cout << "\nYou have chosen multiplication.\n";

        std::cout << "Input your first number: ";
        std::cin >> number1;
        std::cout << "Input your second number: ";
        std::cin >> number2;

        // calculate
        answer = number1 * number2;

        // Return answer
        std::cout << "Your answer is:" << answer << "\n";
    }
    else if (reply == 4)
    {
        // divide
        std::cout << "\nYou have chosen division.\n";

        std::cout << "Input your first number: ";
        std::cin >> number1;
        std::cout << "Input your second number: ";
        std::cin >> number2;

        // calculate
        answer = number1 / number2;

        // Return answer
        std::cout << "Your answer is:" << answer << "\n";
    }
}