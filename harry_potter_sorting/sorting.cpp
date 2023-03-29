/*  Houses:
      gryffindor
      hufflepuff
      ravenclaw
      slytherin
*/

#include <iostream>

int main()
{

    // points variables
    int gryffindor, hufflepuff, ravenclaw, slytherin = 0;

    // answers variables
    int answer1, answer2, answer3, answer4;

    // muggle has started the quiz
    std::cout << "Sorting Hat Quiz!\n";

    /* questions */

    // Q1
    std::cout << "\nQ1) When I'm dead, I want people to remember me as: \n"; // Question 1
    std::cout << "1) The Good\n";                                            // answer to q1
    std::cout << "2) The Great\n";                                           // answer to q1
    std::cout << "3) The Wise\n";                                            // answer to q1
    std::cout << "4) The Bold\n";                                            // answer to q1
    std::cout << "Input your answer: ";
    std::cin >> answer1; // Store answer in answer1 variable

    // Control Flow for Question 1
    if (answer1 == 1)
    {
        hufflepuff + 1; // add a point
    }
    else if (answer1 == 2)
    {
        slytherin + 1; // add a point
    }
    else if (answer1 == 3)
    {
        ravenclaw + 1; // add a point
    }
    else if (answer1 == 4)
    {
        gryffindor + 1; // add a point
    }
    else
    {
        std::cout << "Invalid input.\n"; // error control
    }

    // Q2
    std::cout << "\nQ2) Dawn or Dusk?\n"; // Question 2
    std::cout << "1) Dawn\n";             // answer to q2
    std::cout << "2) Dusk\n";             // answer to q2
    std::cout << "Input your answer: ";
    std::cin >> answer2; // Store answer in answer2 variable

    // Control Flow for Question 2
    if (answer2 == 1)
    {
        gryffindor, ravenclaw + 1; // point
    }
    else if (answer2 == 2)
    {
        hufflepuff, slytherin + 1; // point
    }
    else
    {
        std::cout << "Invalid Input.\n"; // error checking
    }

    // Q3
    std::cout << "\nQ3) Which kind of instrument most pleases your ear?\n"; // Question 3
    std::cout << "1) The violin\n";                                         // answer to q3
    std::cout << "2) The trumpet\n";                                        // answer to q3
    std::cout << "3) The piano\n";                                          // answer to q3
    std::cout << "4) The drum\n";                                           // answer to q3
    std::cout << "Input your answer: ";
    std::cin >> answer3; // Store answer in answer3 variable

    // Control Flow for Question 3
    if (answer3 == 1)
    {
        slytherin + 1; // add a point
    }
    else if (answer3 == 2)
    {
        hufflepuff + 1; // add a point
    }
    else if (answer3 == 3)
    {
        ravenclaw + 1; // add a point
    }
    else if (answer3 == 4)
    {
        gryffindor + 1; // add a point
    }
    else
    {
        std::cout << "Invalid input.\n"; // error control
    }

    // Q4
    std::cout << "\nQ4) Which road tempts you most?\n";               // Question 4
    std::cout << "1) The wide, sunny grassy lane\n";                  // answer to q4
    std::cout << "2) The narrow, dark, lantern-lit alley\n";          // answer to q4
    std::cout << "3) The twisting, leaf-strewn path through woods\n"; // answer to q4
    std::cout << "4) The cobbled street lined (ancient buildings)\n"; // answer to q4
    std::cout << "Input your answer: ";
    std::cin >> answer4; // Store answer in answer3 variable

    // Control Flow for Question 4
    if (answer4 == 1)
    {
        hufflepuff + 1; // add a point
    }
    else if (answer4 == 2)
    {
        slytherin + 1; // add a point
    }
    else if (answer4 == 3)
    {
        gryffindor + 1; // add a point
    }
    else if (answer4 == 4)
    {
        ravenclaw + 1; // add a point
    }
    else
    {
        std::cout << "Invalid input.\n"; // error control
    }

    // calculate answer
    int max = 0;       // starts at 0
    std::string house; // house variable

    if (gryffindor > max)
    {
        max = gryffindor;
        house = "Gryffindor";
    }
    if (hufflepuff > max)
    {
        max = hufflepuff;
        house = "Hufflepuff";
    }
    if (ravenclaw > max)
    {
        max = ravenclaw;
        house = "Ravenclaw";
    }
    if (slytherin > max)
    {
        max = slytherin;
        house = "Slytherin";
    }

    std::cout << "\nYou belong to " << house << "!\n"; // house answer
}
