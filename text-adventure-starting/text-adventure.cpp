/* Instructions:

    *1. Project Goals:
        Create a C++ text adventure with the storyline of your choosing.
        The program should use your knowledge of C++ conditionals, logic, and loops.


    *2. Story:
        !Your program should have a storyline with:
            - a beginning
            - at least three possible endings
            - It can help to map out your ideas on paper and draw out your possible branches before you begin coding anything.

            In our solution, we used Alice’s Adventures in Wonderland as the premise for our storyline, but you can choose any topic you like!

        !Some possible ideas include:
            - A fantasy book you love
            - Your favorite TV show
            - A funny movie
            - A murder mystery
            - A game show

    *3. Should contain:
        At least 3 branch points where the user must make a choice about what to do next.

        !At each branch point, the program should:
            - Give the user at least two choices
            - Accept user input
            *- Note: that not every story branch needs its own ending; it can also add something and then reconnect with another storyline.


    *4. Your program should handle user choices using conditional logic.
        - We encourage you to use if/else if statements and switch statements where you see fit.
        - Note: If your user has reached an ending, you can use return 0; to exit the main() function and end the program.
*/

/* My storyline:
    *Title:
    The Forgotten Temple

    *Storyline:
    The player, an adventurous archaeologist, stumbles upon an ancient forgotten temple hidden deep in the jungle. Inside the temple, there are several rooms and puzzles to be solved. The player must navigate through the temple, avoid traps, and make choices to discover the hidden treasure.

    *Beginning:
    The adventure begins with the player entering the temple through a mysterious entrance. They find themselves in a dimly lit chamber with three doors, each leading to different paths.

    *Branch 1:
    !Three doors: (1) Door of Wisdom, (2) Door of Strength, and (3) Door of Fortune.

    *Door of Wisdom:
    The player enters a room with a complex riddle on the wall.

    *Door of Strength:
    The player enters a room with a heavy stone door that requires brute force to open.

    *Door of Fortune:
    The player enters a room with a spinning wheel of fortune.

    *Branch 2 (Door of Wisdom):

    Solve the riddle correctly: The player gains access to a hidden room with a valuable artifact.
    Fail to solve the riddle: The player is locked inside the room, leading to one of the endings.

    *Branch 2 (Door of Strength):

    Successfully open the stone door: The player discovers a room with a treasure map.
    Fail to open the stone door: The player is trapped in the room, leading to one of the endings.

    *Branch 2 (Door of Fortune):

    Spin the wheel: The player receives one of three outcomes: (a) a clue to solve the riddle in the Door of Wisdom, (b) a tool to open the stone door in the Door of Strength, or (c) a booby trap is activated, leading to one of the endings.

    *Branch 3:
    After gathering the artifact and treasure map, the player must choose between two paths:

    Follow the treasure map.
    Investigate the origin of the artifact.

    *Endings:
    Failed to solve the riddle or open the stone door: The player is trapped in the temple forever.

    *Follow the treasure map:
    The player discovers a hidden chamber with the temple's treasure but accidentally triggers a trap that seals the chamber, leaving the player with a lifetime supply of treasure but no escape.

    *Investigate the artifact:
    The player learns about an ancient civilization and uncovers a hidden passage that leads to a secret underground city, earning fame and fortune as a renowned archaeologist.

    *Extra:
    Riddle: "I can be cracked, made, told, and played. What am I?"

    Answer: A joke

    Here are five possible answers for the riddle, including the correct one:

        - A joke (correct answer)
        - A secret
        - A puzzle
        - An egg
        - A code

    Players will be presented with these five choices, and they must select the correct one (a joke) to proceed in the Door of Wisdom branch.

    If they choose any of the other options, they will fail to solve the riddle and become locked in the room, leading to one of the endings.

    *Explanation:
    The riddle describes different aspects of a joke:

    *Cracked:
        People often say they "cracked a joke."
    *Made:
        Jokes are created or made up.
    *Told:
        Jokes are usually told to other people.
    *Played:
        A joke can be played on someone, as in a prank.
        In the Door of Wisdom branch, the player must input the correct answer to the riddle.

    *If the player answers "a joke," they gain access to the hidden room with the valuable artifact.

    !If they fail to provide the correct answer, they will be locked inside the room, leading to one of the endings.

*/

/* to run:
cd ~/Documents/Development/cpp/text-adventure-starting/ && g++ text-adventure.cpp -o t
./t
*/
#include <iostream>

void endings(int ending);
void welcomeScreen();
int promptUser(const std::string &question);
void playAgain();
int branchSelect();
int doorOfWisdom();
void hiddenRoom();
void doorOfStrength();
void doorOfFortune();

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

            int branch = branchSelect(); // note: each branch should have 3 choices
            if (branch == 1)             // Door of Wisdom
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
                    endings(_ans); // Call the specific ending based on the wrong answer
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

void endings(int ending)
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

void welcomeScreen()
{
    // welcome screen
    std::cout << "\n====================================\n\n";
    std::cout << "  Welcome to The Forgotten Temple!\n\n";
    std::cout << "====================================\n\n";
}

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

int branchSelect()
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

void hiddenRoom() // after user guesses correct answer
{
    // The player gains access to a hidden room with a valuable artifact.
    std::cout << "Hidden Room\n\n";
    std::cout << "You have now entered a hidden room with a valuable artifact...\n";
    return; // may need to remove
}

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
