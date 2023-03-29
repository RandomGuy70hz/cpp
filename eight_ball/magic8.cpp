#include <iostream>
#include <cstdlib>

int main()
{

    // ask user if they want to play
    std::cout << "Would you like to play Magic 8-Ball? y/n: ";

    std::string play;
    std::cin >> play;
    std::cin.ignore();

    if (play != "n")
    {

        while (play != "n")
        {

            std::cout << "\nAsk Magic 8-Ball a question: ";
            std::string question;             // Add a variable to store the question
            std::getline(std::cin, question); // Read the question using std::getline()

            // generate random response
            srand(time(NULL));
            int answer = std::rand() % 19;
            std::cout << "\nMAGIC 8-BALL: ";

            // possible answers
            if (answer == 0)
            {
                std::cout << "It is certain.\n";
            }
            else if (answer == 1)
            {
                std::cout << "Without a doubt.\n";
            }
            else if (answer == 2)
            {
                std::cout << "It is decidedly so.\n";
            }
            else if (answer == 3)
            {
                std::cout << "Yes - definitely.\n";
            }
            else if (answer == 4)
            {
                std::cout << "You may rely on it.\n";
            }
            else if (answer == 5)
            {
                std::cout << "As I see it, yes.\n";
            }
            else if (answer == 6)
            {
                std::cout << "Most likely.\n";
            }
            else if (answer == 7)
            {
                std::cout << "Outlook good.\n";
            }
            else if (answer == 8)
            {
                std::cout << "Yes.\n";
            }
            else if (answer == 9)
            {
                std::cout << "Signs point to yes.\n";
            }
            else if (answer == 10)
            {
                std::cout << "Reply hazy, try again.\n";
            }
            else if (answer == 11)
            {
                std::cout << "Ask again later.\n";
            }
            else if (answer == 12)
            {
                std::cout << "Better not tell you now.\n";
            }
            else if (answer == 13)
            {
                std::cout << "Cannot predict now.\n";
            }
            else if (answer == 14)
            {
                std::cout << "Concentrate and ask again.\n";
            }
            else if (answer == 15)
            {
                std::cout << "Don't count on it.\n";
            }
            else if (answer == 16)
            {
                std::cout << "My reply is no.\n";
            }
            else if (answer == 17)
            {
                std::cout << "My sources say no.\n";
            }
            else if (answer == 18)
            {
                std::cout << "Outlook not so good.\n";
            }
            else
            {
                std::cout << "Very doubtful.\n";
            }

            // ask user if they want to play again
            std::string playAgain;
            std::cout << "\nWould you like to play again? y/n: ";
            std::cin >> playAgain;
            std::cin.ignore();

            // if answer is not y, exit
            if (playAgain != "y")
            {
                return 0;
            }
        }
    }

    else
    {
        return 0;
    }
    return 0;
}
