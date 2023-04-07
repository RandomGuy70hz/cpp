/* to run:
cd ~/Documents/Development/cpp/text-adventure-starting/ && g++ text-adventure.cpp -o t
./t
*/

//

#include <iostream>

// welcome user
void welcomeScreen();                        // welcomes user
int promptUser(const std::string &question); // prompts user to play/playagain

// path selection
int pathSelect();
int doorOfWisdom();    // different paths user can select
void doorOfStrength(); // different paths user can select
void doorOfFortune();  // different paths user can select

// when user guesses riddle correct inside Door of wisdom
void hiddenRoom();

// loops back so user can play again // subject to change since it calls main function
void playAgain();

// different ending paths
void lostEndings(int ending);
void winEndings(int ending);

// main function
int main()
{
    welcomeScreen();
    // int x = getUserInput();

    int x = promptUser("Would you like to play?\n");
    if (x == 1) // if play is yes
    {
        while (x == 1) // main game loop
        {
            bool game_is_running = true;

            int branch = pathSelect(); // note: each branch should have 3 choices
            if (branch == 1)           // Door of Wisdom
            {
                int _ans = doorOfWisdom();
                if (_ans == 4) // Correct answer
                {
                    std::cout << "Correct Answer!\n\n ";
                    /* Proceeds to the next part of the game
                    The player gains access to a hidden room with a valuable artifact. */
                    hiddenRoom();
                }
                else if (_ans >= 1 && _ans <= 5) // Wrong answer
                {
                    std::cout << "Wrong Answer! You have been trapped inside this room..\n\n";
                    lostEndings(_ans); // Call the specific ending based on the wrong answer
                    bool game_is_running = false;
                    break;
                }
                else // Error handler
                {
                    std::cout << "Invalid Input\n";
                }
            }
            else if (branch == 2) // Door of Strength
            {
                doorOfStrength();
                break;
            }
            else if (branch == 3) // Door of fortune
            {

                doorOfFortune();
                break;
            }
            else // Error handler
            {
                std::cout << "Invalid Input\n";
            }

            x = promptUser("Would you like to play again?\n");
        }
    }

    else if (x == 2) // Exit program
    {
        std::cout << "See ya next time!\n";
        return 0;
    }

    else // error handler
    {
        std::cout << "Invalid input.\n";
    }
}

// welcome message upon initiation
void welcomeScreen()
{
    // welcome screen
    std::cout << "\n====================================\n\n";
    std::cout << "  Welcome to The Forgotten Temple!\n\n";
    std::cout << "====================================\n\n";
}

// prompt user to play
int promptUser(const std::string &question)
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

// play again function // may need to change since it calls main function
void playAgain()
{
    int playAgain = promptUser("Would you like to play again?\n");

    if (playAgain == 1)
    {
        main();
        return;
    }
    else if (playAgain == 2)
    {
        return;
    }
    else
    {
        std::cout << "Invalid input.\n";
    }
}

// user select path
int pathSelect()
{
    int branch = 0;

    // storyline
    std::cout << "\n==========================================================================================================\n\n"
              << "In this story, you are an adventurous archaeologist.\n\n"
              << "You have stumbled upon an ancient forgotten temple hidden deep in the jungle.\n\n"
              << "Inside the temple, there are several rooms and puzzles to be solved.\n\n"
              << "Your task is to navigate through the temple, avoid traps, and make choices to discover the hidden treasure!\n\n"
              << "==========================================================================================================\n\n";

    std::cout << "You've just entered the temple through a mysterious entrance.\n"
              << "You find yourself in a dimly lit chamber with three doors... each door leads to a different path.\n\n";

    // change this
    std::cout << "Please choose your path:\n"
              << "1) Door of Wisdom\n"    // The player enters a room with a complex riddle on the wall.
              << "2) Door of Strength\n"  // The player enters a room with a heavy stone door that requires brute force to open.
              << "3) Door of Fortune\n\n" // The player enters a room with a spinning wheel of fortune.
              << "Enter your choice: ";
    std::cin >> branch;
    std::cout << "\n";

    return branch;
}

// path 1 - riddle: artifact
int doorOfWisdom()
{
    /* Branch 1 (Door of Wisdom):
    *Solve the riddle correctly:
        The player gains access to a hidden room with a valuable artifact.

    !Fail to solve the riddle:
        The player is locked inside the room, leading to one of the endings.
    */

    // Door of Wisdom
    int _ans = 0;
    std::cout << "\n\nWelcome to the Door of Wisdom!\n\n"
              << "You have entered a room with a complex riddle on the wall..\n\n"
              << "You must sove this riddle to continue...\n\n"
              << "Heres the riddle:\n\n"
              << "\"I can be cracked, made, told, and played. What am I?\"\n\n"
              << "Choose an answer from one of the 5 options below:\n"
              << "1) An Egg\n"
              << "2) A Secret\n"
              << "3) A Puzzle\n"
              << "4) A Joke\n" // Correct answer
              << "5) A Code\n\n";

    std::cout << "Enter your answer: ";
    std::cin >> _ans;
    std::cout << "\n";

    return _ans;
}

// path 2 - stone door: treasure map
// change brach_1 & 3 to return type of int
void doorOfStrength()
{
    /* Branch 2 (Door of Strength):
    *Successfully open the stone door:
        The player discovers a room with a treasure map.

    !Fail to open the stone door:
        The player is trapped in the room, leading to one of the endings.
    */

    // Door of Strength
    std::cout << "Door of Strength\n\n";
    return;
}

// path 3 - wheel of fortune : clue/tool to open stone door for path 2/booby trap leads to ending.
// may need to change return type
void doorOfFortune()
{
    /* Branch 3 (Door of Fortune):
    *Spin the wheel:
    *The player receives one of three outcomes:
        !(a) a clue to solve the riddle in the Door of Wisdom,
        !(b) a tool to open the stone door in the Door of Strength, or
        !(c) a booby trap is activated, leading to one of the endings.
    */

    // Door of Fortune
    std::cout << "Door of Fortune\n\n";
    return;
}

// when user guesses riddle correctly // contains artifact
void hiddenRoom() // after user guesses correct answer
{
    // The player gains access to a hidden room with a valuable artifact.
    std::cout << "Hidden Room\n\n";
    std::cout << "You have now entered a hidden room with a valuable artifact...\n";
    return; // may need to remove
}

// ending when user loses
void lostEndings(int ending)
{
    switch (ending)
    {
    case 1:
        // Ending 1
        std::cout << "You hear a cracking sound and the floor beneath you collapses, trapping you inside the room.\n";
        playAgain();
        break;
    case 2:
        // Ending 2
        std::cout << "The walls start closing in, and you find yourself trapped inside the room with no escape.\n";
        playAgain();
        break;
    case 3:
        // Ending 3
        std::cout << "The room starts filling with water, and you're unable to find a way out before it's too late.\n";
        playAgain();
        break;
    case 5:
        // Ending 4
        std::cout << "The room starts to heat up, and you're unable to decipher the code in time to escape.\n";
        playAgain();
        break;
    default:
        std::cout << "Invalid input.";
        break;
    }
}

// ending when user wins
void winEndings(int ending)
{
    switch (ending)
    {
    case 1:
        // Ending 1
        std::cout << "You've won!\n";
        playAgain();
        break;
    case 2:
        // Ending 2
        std::cout << "You've won!\n";
        playAgain();
        break;
    case 3:
        // Ending 3
        std::cout << "You've won!\n";
        playAgain();
        break;
    case 5:
        // Ending 4
        std::cout << "You've won!\n";
        playAgain();
        break;
    default:
        std::cout << "Invalid input.";
        break;
    }
}
