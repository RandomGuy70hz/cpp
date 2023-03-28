#include <iostream>

int main()
{

    // currency variables
    double pesos, reais, soles;

    // amount in dollars variable
    double dollars;

    // ask for currency
    std::cout << "Enter number of Colombian Pesos: ";
    std::cin >> pesos;
    // Pesos to USD: 0.054 United States Dollar

    std::cout << "Enter number of Brazilian Reais: ";
    std::cin >> reais;
    // Reais to USD: 0.19 United States Dollar

    std::cout << "Enter number of Puruvian Soles: ";
    std::cin >> soles;
    // Soles to USD: 0.27 United States Dollar

    // calculate conversions to USD and get sum
    dollars = (0.054 * pesos) + (0.19 * reais) + (0.27 * soles);

    // print sum
    std::cout << "Us Dollars = $" << dollars << "\n";
}