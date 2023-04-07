/*
    cd ~/Documents/Development/cpp/simple_hours_calculator && g++ -std=c++11 taxes.cpp -o taxes
    ./taxes
*/

#include <iostream>
#include <vector>
#include <map>
#include <limits>

double calculate_tax(const std::vector<std::pair<double, double>> &tax_brackets, double income, double pay_periods)
{
    double tax = 0;
    double annual_income = income * pay_periods;
    double remaining_income = annual_income;

    for (const std::pair<double, double> &bracket : tax_brackets)
    {
        double taxable_amount = std::min(remaining_income, bracket.first);
        tax += taxable_amount * bracket.second;
        remaining_income -= taxable_amount;

        if (remaining_income <= 0)
            break;
    }

    return tax / pay_periods;
}

double calculate_cpp(double pay, double pay_periods)
{
    const double cpp_rate = 0.0525;
    const double cpp_maximum = 3163.43;
    double cpp_deduction = pay * cpp_rate;

    if (cpp_deduction * pay_periods > cpp_maximum)
    {
        cpp_deduction = cpp_maximum / pay_periods;
    }

    return cpp_deduction;
}

double calculate_ei(double pay, double pay_periods)
{
    const double ei_rate = 0.0158;
    const double ei_maximum = 889.54;
    double ei_deduction = pay * ei_rate;

    if (ei_deduction * pay_periods > ei_maximum)
    {
        ei_deduction = ei_maximum / pay_periods;
    }

    return ei_deduction;
}

int main()
{
    std::map<std::string, std::vector<std::pair<double, double>>> provincial_tax_brackets = {
        {"NL", {{37929, 0.087}, {37930, 0.145}, {33408, 0.158}, {std::numeric_limits<double>::max(), 0.173}}}
        // Add other provinces' tax brackets here.
    };

    std::vector<std::pair<double, double>> federal_tax_brackets = {
        {48535, 0.15},
        {48534, 0.205},
        {53404, 0.26},
        {63895, 0.29},
        {std::numeric_limits<double>::max(), 0.33}};

    std::string province;
    std::cout << "Enter your province: ";
    std::getline(std::cin, province);

    double pay;
    std::cout << "Enter your gross pay: ";
    std::cin >> pay;

    double pay_periods;
    std::cout << "Enter the number of pay periods per year: ";
    std::cin >> pay_periods;

    double federal_tax = calculate_tax(federal_tax_brackets, pay, pay_periods);
    std::cout << "Estimated federal tax for this pay period: " << federal_tax << std::endl;

    if (provincial_tax_brackets.find(province) != provincial_tax_brackets.end())
    {
        double provincial_tax = calculate_tax(provincial_tax_brackets[province], pay, pay_periods);
        std::cout << "Estimated provincial tax for this pay period in " << province << ": " << provincial_tax << std::endl;

        double cpp_deduction = calculate_cpp(pay, pay_periods);
        std::cout << "Estimated CPP deduction for this pay period: " << cpp_deduction << std::endl;
        double ei_deduction = calculate_ei(pay, pay_periods);
        std::cout << "Estimated EI deduction for this pay period: " << ei_deduction << std::endl;

        double total_deductions = federal_tax + provincial_tax + cpp_deduction + ei_deduction;
        std::cout << "Total estimated deductions for this pay period: " << total_deductions << std::endl;

        double net_pay = pay - total_deductions;
        std::cout << "Estimated net pay for this pay period: " << net_pay << std::endl;
    }
    else
    {
        std::cout << "Invalid province entered." << std::endl;
    }

    return 0;
}