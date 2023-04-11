/* To compile:
cd ~/Documents/Development/cpp/simple_hours_calculator && g++ hours_overtime_calculator.cpp -o hours_overtime_estimator
./hours_overtime_estimator
*/

#include <iostream>
#include <fstream>
#include <filesystem>

void print_separator()
{
    std::cout << "\n\n---------------------------------------------------------------\n\n";
}

double get_input(const std::string &prompt, const std::string &prefix = "", const std::string &suffix = "")
{
    double input;
    char confirm;

    while (true)
    {
        std::cout << prompt;
        std::cin >> input;

        std::cout << "\nYou entered: " << prefix << input << suffix << "\n\nIs this correct? (y/n) : ";
        std::cin >> confirm;

        if (confirm == 'y' || confirm == 'Y')
            break;
    }

    print_separator();
    return input;
}

void save_summary_to_file(const std::string &file_path, double hourly_rate, double regular_hours, double regular_overtime_hours, double holiday_overtime_hours, double total_hours, double gross_pay)
{
    std::ofstream output_file(file_path);

    output_file << "===============================================================\n\n"
                << "                    Hours summary below:\n\n"
                << "===============================================================\n\n"
                << "                Hourly rate: $" << hourly_rate << "\n"
                << "                Total regular hours: " << regular_hours << " hr(s)\n"
                << "                Total regular overtime hours: " << regular_overtime_hours << " hr(s)\n"
                << "                Total holiday overtime hours: " << holiday_overtime_hours << " hr(s)\n\n"
                << "---------------------------------------------------------------\n\n"
                << "                Total hours: " << total_hours << " hr(s)\n"
                << "                Expected gross pay: $" << gross_pay << "\n\n"
                << "===============================================================\n";

    output_file.close();
}

int main()
{
    std::cout << "\n\n===============================================================\n\n"
              << "                Welcome! Lets get started.\n\n"
              << "===============================================================\n\n"
              << "              First we will need some inputs.\n";
    print_separator();

    double hourly_rate = get_input("Enter your hourly rate ($): ", "$");
    double regular_hours = get_input("Next, enter your regular worked hours: ", "", " hr(s)");
    double regular_overtime_hours = get_input("Next, enter amount of hours worked in regular overtime: ", "", " hr(s)"); // move this to line 65


    


    char worked_stat_holiday;
    std::cout << "Did you work during a statutory holiday? (y/n) : ";
    std::cin >> worked_stat_holiday;
    print_separator();

    double holiday_overtime_hours = 0;
    if (worked_stat_holiday == 'y' || worked_stat_holiday == 'Y')
    {
        holiday_overtime_hours = get_input("Enter number of hours you worked on the statutory holiday: ", "", " hr(s)");
        //double regular_overtime_rate = get_input("Enter overtime rate for regular overtime: ", "x");
    }


    double regular_overtime_rate = get_input("Enter overtime rate for regular overtime: ", "x");
    //double holiday_overtime_rate = get_input("Enter overtime rate for statutory holiday: ", "x");

    double holiday_overtime_rate = 0;
    if (worked_stat_holiday == 'y' || worked_stat_holiday == 'Y')
    {
        holiday_overtime_rate = get_input("Enter overtime rate for statutory holiday: ", "x");
    }


    std::cout
        << "===============================================================\n\n"
        << "    Thank you for your inputs. See summary below:\n\n"
        << "===============================================================\n\n"
        << "                Hourly rate: $" << hourly_rate << "\n"
        << "                Total regular hours: " << regular_hours << " hr(s)\n"
        << "                Total regular overtime hours: " << regular_overtime_hours << " hr(s)\n"
        << "                Total holiday overtime hours: " << holiday_overtime_hours << " hr(s)\n\n"
        << "---------------------------------------------------------------\n\n";

    double total_hours = regular_hours + (regular_overtime_hours * regular_overtime_rate) + (holiday_overtime_hours * holiday_overtime_rate);
    std::cout << "                Total hours: " << total_hours << " hr(s)\n";

    double gross_pay = (hourly_rate * regular_hours) +
                       (hourly_rate * regular_overtime_hours * regular_overtime_rate) +
                       (hourly_rate * holiday_overtime_hours * holiday_overtime_rate);

    std::cout << "                Expected gross pay: $" << gross_pay << "\n\n"
              << "===============================================================\n";

    char save_to_file;
    std::cout << "Save summary to file? (y/n) : ";
    std::cin >> save_to_file;

    if (save_to_file == 'y' || save_to_file == 'Y')
    {
        std::string file_path = "summary.txt";
        save_summary_to_file(file_path, hourly_rate, regular_hours, regular_overtime_hours, holiday_overtime_hours, total_hours, gross_pay);
        std::cout << "\nSummary saved to " << file_path << "\n";
    }



    return 0;
}

/* Here's a detailed explanation of each part of the code:
    #include <iostream>: 
        - This line tells the computer to include a library called "iostream" which allows the program to read from and write to the terminal.
    #include <fstream>: 
        - This line tells the computer to include a library called "fstream" which allows the program to read from and write to files.
    #include <filesystem>: 
        - This line tells the computer to include a library called "filesystem" which allows the program to work with paths and directories.
    void print_separator(): 
        - This is a small function that makes it easy to print a line of dashes to separate different parts of the output.
    double get_input(...): 
        - This function takes three input arguments (prompt, prefix, and suffix), and is used to get input from the user in a consistent way throughout the program. It prints the prompt, gets the user's input, and then asks if the input is correct before moving on.
    void save_summary_to_file(...): 
        - This function takes seven input arguments (file_path, hourly_rate, regular_hours, regular_overtime_hours, holiday_overtime_hours, total_hours, and gross_pay), and saves the summary of the hours and pay to a file.
    
    int main(): This is the main function of the program, where everything begins. 
    It does the following steps:
        - a. Prints a welcome message.
        - b. Gets user input for hourly_rate, regular_hours, regular_overtime_hours, and whether the user worked during a statutory holiday.
        - c. If the user worked during a statutory holiday, it asks for holiday_overtime_hours.
        - d. Gets user input for regular_overtime_rate and, if applicable, holiday_overtime_rate.
        - e. Prints a summary of the user's inputs.
        - f. Calculates the total_hours and gross_pay.
        - g. Prints the total_hours and gross_pay.
        - h. Asks the user if they want to save the summary to a file.
        - i. If the user wants to save the summary, it saves the summary to a file and prints the file location.
*/