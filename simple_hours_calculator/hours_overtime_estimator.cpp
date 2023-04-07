/* To compile:
cd ~/Documents/Development/cpp/simple_hours_calculator && g++ overtime2.cpp -o overtime2
./overtime2
*/

#include <iostream>

void print_separator()
{
    std::cout << "---------------------------------------------------------------\n\n";
}

double get_input(const std::string &prompt, const std::string &prefix = "")
{
    double input;
    int confirm;

    while (true)
    {
        std::cout << prompt;
        std::cin >> input;

        std::cout << "\nYou entered: " << prefix << input << ". Is this correct?\n1) Yes\n2) No\n\n";
        std::cin >> confirm;

        if (confirm == 1)
            break;
    }

    print_separator();
    return input;
}

int main()
{
    std::cout << "\n\n===============================================================\n\n"
              << "                Welcome! Lets get started.\n\n"
              << "===============================================================\n\n"
              << "First we will need some inputs.\n\n";
    print_separator();

    double hourly_rate = get_input("Input your hourly rate: ", "$");
    double regular_hours = get_input("Next, input your regular worked hours: ");
    double regular_overtime_hours = get_input("Next, input amount of hours worked in regular overtime: ");

    int worked_stat_holiday;
    std::cout << "Next, did you work during a statutory holiday?\n1) Yes\n2) No\n\n";
    std::cin >> worked_stat_holiday;
    print_separator();

    double holiday_overtime_hours = 0;
    if (worked_stat_holiday == 1)
    {
        holiday_overtime_hours = get_input("Input amount of hours you worked on the statutory holiday: ");
    }

    double regular_overtime_rate = get_input("Input overtime rate for regular overtime: ", "x");
    double holiday_overtime_rate = get_input("Input overtime rate for statutory holiday: ", "x");

    std::cout << "===============================================================\n\n"
              << "    Thank you for your inputs. See summary below:\n\n"
              << "===============================================================\n\n"
              << "                Hourly rate: " << hourly_rate << "\n"
              << "                Total regular hours: " << regular_hours << "\n"
              << "                Total regular overtime hours: " << regular_overtime_hours << "\n"
              << "                Total holiday overtime hours: " << holiday_overtime_hours << "\n\n"
              << "---------------------------------------------------------------\n\n";

    double total_hours = regular_hours + (regular_overtime_hours * regular_overtime_rate) + (holiday_overtime_hours * holiday_overtime_rate);
    std::cout << "                Total hours overall: " << total_hours << "\n";

    double gross_pay = (hourly_rate * regular_hours) +
                       (hourly_rate * regular_overtime_hours * regular_overtime_rate) +
                       (hourly_rate * holiday_overtime_hours * holiday_overtime_rate);

    std::cout << "                Expected gross pay: " << gross_pay << "\n\n"
              << "===============================================================\n";

    return 0;
}
