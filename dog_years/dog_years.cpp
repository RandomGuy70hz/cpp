#include <iostream>
#include <regex>

int main()
{

	std::string run_again = "y";

	while (run_again == "y")
	{

		// input name of dog
		std::string name;
		std::cout << "Input your dog's name: ";
		std::cin >> name;

		// input the age of your dog in years
		// dogs older than 2 years old.
		std::string age_input;
		std::regex age_pattern("\\d+");

		while (true)
		{
			std::cout << "Input the age of your dog: ";
			std::cin >> age_input;

			if (!std::regex_match(age_input, age_pattern))
			{
				std::cout << "Invalid input. Please enter an integer." << std::endl;
			}
			else
			{
				break;
			}
		}

		int dog_age = std::stoi(age_input);

		// first two years count as 21 human years.
		int early_years = 21;

		// following years counts as 4 human years.
		// later_years=(dog_age−2)∗4
		int later_years = (dog_age - 2) * 4;

		// total human years
		// Add early_years and later_years
		int human_years = early_years + later_years;

		// practice conditional statements
		// The first two years of a dog’s life count as 21 human years.
		if (dog_age == 1)
		{
			std::cout << "My name is " << name << "! Ruff ruff, I am "
					  << "10.5"
					  << " years old in human years. \n";
		}
		else if (dog_age == 2)
		{
			std::cout << "My name is " << name << "! Ruff ruff, I am "
					  << "21"
					  << " years old in human years. \n";
		}
		else
		{
			std::cout << "My name is " << name << "! Ruff ruff, I am " << human_years << " years old in human years. \n";
		}

		// Ask user if they want to run program again
		std::cout << "Would you like to run this program again? (y/n): ";
		std::cin >> run_again;

		// validate user input
		std::regex run_again_pattern("[yY][eE]?[sS]?");

		if (!std::regex_match(run_again, run_again_pattern))
		{
			// std::cout << "Invalid input. Program stopped." << std::endl;
			return 0;
		}
	}

	return 0;
}
