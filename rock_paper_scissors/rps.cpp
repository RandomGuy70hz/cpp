/* Logic:
  Scissors cuts Paper.
  Paper covers Rock.
  Rock crushes Lizard.
  *9 possibilities total

  Lizard poisons Spock.
  Spock smashes Scissors.
  Scissors decapitate Lizard.
  Lizard eats Paper.
  Paper disproves Spock.
  Spock vaporizes Rock.
  (and as it always has) Rock crushes Scissors.
*/

#include <iostream>
#include <stdlib.h>

int main()
{

    // Ask user if they want to play
    int play = 0;
    std::cout << "Would you like to play Rock, Paper, Scissors? \n";
    std::cout << "1) Yes\n";
    std::cout << "2) No\n";
    std::cout << "Enter your input: ";

    std::cin >> play;

    // if yes
    if (play != 2)
    {

        while (play != 2)
        {

            // random number for computer choice
            srand(time(NULL));
            int computer = rand() % 3 + 1;

            // users choice
            int user = 0;

            // prompt user for selection
            std::cout << "\n====================\n";
            std::cout << "Rock, Paper Scissors!\n";
            std::cout << "====================\n";

            std::cout << "1) ✊\n";
            std::cout << "2) ✋\n";
            std::cout << "3) ✌️\n";

            std::cout << "Shoot: ";
            std::cin >> user; // store user input to variable
            std::cout << "\n";
            // user choice
            if (user == 1)
            {
                std::cout << "\nYou chose paper: ✊\n";
            }
            else if (user == 2)
            {
                std::cout << "You chose: ✋\n";
            }
            else if (user == 3)
            {
                std::cout << "You chose: ✌️\n";
            }
            else
            {
                std::cout << "Invalid Input.\n";
            }

            // computer choice
            if (computer == 1)
            {
                std::cout << "Computer chose paper: ✊\n";
            }
            else if (computer == 2)
            {
                std::cout << "Computer chose: ✋\n";
            }
            else if (computer == 3)
            {
                std::cout << "Computer chose: ✌️\n";
            }
            else
            {
                std::cout << "Invalid Input.\n";
            }

            // tie logic
            if (user == 1 && computer == 1 || user == 2 && computer == 2 || user == 3 && computer == 3)
            {
                std::cout << "Its a tie!\n";
            }

            // game logic
            if (user == 1 && computer == 2)
            {
                std::cout << "\nComputer wins!\n";
            }
            else if (user == 1 && computer == 3)
            {
                std::cout << "\nYou win!\n";
            }
            else if (user == 2 && computer == 1)
            {
                std::cout << "\nYou win!\n";
            }
            else if (user == 2 && computer == 3)
            {
                std::cout << "\nComputer wins!\n";
            }
            else if (user == 3 && computer == 1)
            {
                std::cout << "\nComputer wins!\n";
            }
            else if (user == 3 && computer == 2)
            {
                std::cout << "\nYou win!\n";
            }

            std::cout << "\nPlay again?\n";
            std::cout << "1) Yes\n";
            std::cout << "2) No\n";
            std::cout << "Enter your input: ";
            std::cin >> play;

            if (play == 2)
            {
                return 0;
            }
        }

        // if no
    }
    else if (play != 1)
    {
        std::cout << "Thanks for playing!\n";
    }
    else
    {
        std::cout << "Invalid input.\n"; // error detection
    }

    return 0;
}