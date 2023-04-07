/* To compile:
cd ~/Documents/Development/cpp/simple_hours_calculator && g++ hours.cpp -o hours
./hours
*/

#include <iostream>

/* inputs needed:
    - hourly rate
    - regular hours worked
    - regular overtime
    - user input
    - holiday overtime
    - regular overtime rate
    - holiday overtime rate

# of inputs = 7

*/

// greetings
void greeting();

// line seperator
void print_separator();

// user prompts
int prompt_user(const std::string &question);

// hourly rate
int hourly_rate();

// hours
int regular_hours();
int reg_overtime_hours();
int holiday_overtime_hours();

// rates
int regular_overtime_rate(double x);
int holiday_overtime_rate();

// main function
int main()
{
    greeting();

    // int x = prompt_user("Enter your hourly rate: ");
    // hourly_rate();
    int user_input;
    double hourly_rate;
    std::cout
        << "Input your hourly rate: ";
    std::cin >> hourly_rate;
    std::cout << "\n\n";
    std::cout
        << "You entered $"
        << hourly_rate
        << " is this correct?\n"
        << "1) Yes\n"
        << "2) No\n"
        << "Enter your answer: ";
    std::cin >> user_input;
}

// greeting msg
void greeting()
{
    std::cout << "\n\n===============================================================\n\n"
              << "                  Welcome! Lets get started.\n\n"
              << "===============================================================\n\n"
              << "First we will need some inputs.\n\n"
              << "---------------------------------------------------------------\n\n";
}

// user prompts
// refactored code
int prompt_user(const std::string &question)
{
    int response = 0;
    std::cout << question << "\n";
    std::cout << "1) Yes\n";
    std::cout << "2) No\n\n";
    std::cout << "Enter your answer: ";
    std::cin >> response;
    std::cout << "\n";
    return response;
}

int user_input(const std::string &question)
{
}

// hourly $ rate
int hourly_rate(const std::string &hourly_rate)
{
    double response = 0;
    std::cout << hourly_rate << "\n";
    std::cout << "Enter your hourly rate: ";
    std::cin >> response;
    std::cout << "\n";
    return response;
}

// regular overtime rate
int regular_overtime_rate(double x)
{
    double n = 0;
    std::cout << "Enter your regular overtime rate: ";
    std::cin >> n;

    return n;
}

// holiday overtime rate
int holiday_overtime_rate()
{
    double x = 0;
    std::cout << "";
}

// hours worked
int regular_hours()
{
    double x = 0;
    std::cout << "";
}

// regular overtime hours
int reg_overtime_hours()
{
    double x = 0;
    std::cout << "";
}

// holiday overtime hours
int holiday_overtime_hours()
{
    double x = 0;
    std::cout << "";
}

void print_separator()
{
    std::cout << "---------------------------------------------------------------\n\n";
}
