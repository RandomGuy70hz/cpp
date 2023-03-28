#include <iostream>
#include <cmath>
#include <regex>

int main()
{

    std::string run_again = "y";
    while (run_again == "y")
    {

        while (true)
        {

            double a, b, c;

            std::cout << "Enter a: ";
            std::cin >> a;

            std::cout << "Enter b: ";
            std::cin >> b;

            std::cout << "Enter c: ";
            std::cin >> c;

            /* Formulas:
            root1= (−b + b^2 − 4ac) /2a
            root2= (−b - b^2 − 4ac) /2a
            */

            double root1, root2;
            root1 = (-b + std::sqrt(b * b - 4 * a * c)) / (2 * a);
            root2 = (-b - std::sqrt(b * b - 4 * a * c)) / (2 * a);

            std::cout << "\n";

            std::cout << "Root 1 is " << root1 << "\n";
            std::cout << "Root 2 is " << root2 << "\n";

            // Ask user if they want to run program again
            std::cout << "Would you like to run this program again? (y/n): ";
            std::cin >> run_again;

            // validate user input
            std::regex run_again_pattern("[yY][eE]?[sS]?");

            if (!std::regex_match(run_again, run_again_pattern))
            {
                return 0;
            }
        }
    }
    return 0;
}
