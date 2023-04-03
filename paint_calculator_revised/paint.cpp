/* To compile:
    g++ <filename>.cpp -o <filename> -std=c++17
    g++ debug3.cpp -o debug3 -std=c++17

    ./<filename>
*/

#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <iomanip>
#include <fstream>
#include <filesystem>

// Function prototypes
void calculateInteriorPainting();
void calculateExteriorPainting();
void saveOutputToFile();

int main()
{
    int numRooms;
    int paintArea;
    int numSides;
    double totalSquareFeet = 0;
    std::string input;
    std::vector<std::string> supplies;
    std::vector<std::string> roomNames;
    std::vector<double> roomSquareFeet;
    std::vector<double> gallonsNeeded;
    std::vector<double> litresNeeded;

    // Greet user
    std::cout << "Welcome to the Paint Calculator!\n\n"
              << std::endl;

    // Ask user if they're painting interior, exterior, or both
    std::cout << "What are you painting today?" << std::endl;
    std::cout << "1) Interior" << std::endl;
    std::cout << "2) Exterior" << std::endl;
    std::cout << "3) Both Interior & Exterior" << std::endl;
    std::cout << "\nEnter your selection: ";
    std::cin >> paintArea;
    std::cin.ignore();

    if (paintArea == 1)
    {
        calculateInteriorPainting();
        saveOutputToFile();
    }

    else if (paintArea == 2)
    {
        // calculateExteriorPainting(numRooms, paintArea, numSides, totalSquareFeet, input, supplies, roomNames, roomSquareFeet, gallonsNeeded, litresNeeded);
        calculateExteriorPainting();
        saveOutputToFile();
    }
    else if (paintArea == 3)
    {
        calculateInteriorPainting();
        calculateExteriorPainting();
        saveOutputToFile();
    }
    else
    {
        std::cout << "Invalid selection. Please try again." << std::endl;
    }
    return 0;
}

void calculateInteriorPainting()
{

    //  Get number of rooms
    int numRooms;
    int paintArea;
    int numSides;
    double totalSquareFeet = 0;
    std::string input;
    std::vector<std::string> supplies;
    std::vector<std::string> roomNames;
    std::vector<double> roomSquareFeet;
    std::vector<double> gallonsNeeded;
    std::vector<double> litresNeeded;

    std::cout << "\n\nHow many rooms will be painted? ";
    std::cin >> numRooms;
    std::cin.ignore();
    roomNames.resize(numRooms);
    roomSquareFeet.resize(numRooms);
    gallonsNeeded.resize(numRooms);
    litresNeeded.resize(numRooms);

    // Get room names and dimensions
    for (int i = 0; i < numRooms; i++)
    {
        double length, width, height;
        char dummy;
        std::cout << "\nEnter the name for room " << i + 1 << ": ";
        getline(std::cin, roomNames[i]);
        std::cout << "\n\nEnter the dimensions (length, width, height) in feet for " << roomNames[i] << " (separated by commas): ";
        std::cin >> length >> dummy >> width >> dummy >> height;
        std::cin.ignore();
        roomSquareFeet[i] = 2 * height * (length + width);
        totalSquareFeet += roomSquareFeet[i];
        gallonsNeeded[i] = std::ceil(roomSquareFeet[i] / 350);
        litresNeeded[i] = std::ceil(roomSquareFeet[i] / 350 * 3.78541);
    }

    // Check for forgotten rooms
    std::string forgottenRooms;
    std::cout << "\nHave you forgotten any rooms? (yes/no): ";
    std::getline(std::cin, forgottenRooms);

    while (forgottenRooms == "yes")
    {
        int additionalRooms;
        std::cout << "\nHow many additional rooms will be painted? ";
        std::cin >> additionalRooms;
        std::cin.ignore();

        numRooms += additionalRooms;
        roomNames.resize(numRooms);
        roomSquareFeet.resize(numRooms);
        gallonsNeeded.resize(numRooms);
        litresNeeded.resize(numRooms);

        // Get dimensions of additional rooms
        for (int i = numRooms - additionalRooms; i < numRooms; i++)
        {
            double length, width, height;
            char dummy;
            std::cout << "\nEnter the name for room " << i + 1 << ": ";
            getline(std::cin, roomNames[i]);
            std::cout << "\n\nEnter the dimensions (length, width, height) in feet for " << roomNames[i] << " (separated by commas): ";
            std::cin >> length >> dummy >> width >> dummy >> height;
            std::cin.ignore();
            roomSquareFeet[i] = 2 * height * (length + width);
            totalSquareFeet += roomSquareFeet[i];
            gallonsNeeded[i] = std::ceil(roomSquareFeet[i] / 350);
            litresNeeded[i] = std::ceil(roomSquareFeet[i] / 350 * 3.78541);
        }

        std::cout << "\nHave you forgotten any rooms? (yes/no): ";
        std::getline(std::cin, forgottenRooms);
    }

    // Print room information
    std::cout << "\n\nThe total square footage for each room is listed below:" << std::endl;
    for (int i = 0; i < numRooms; i++)
    {
        std::cout << roomNames[i] << ": " << roomSquareFeet[i] << " square feet" << std::endl;
    }

    std::cout << "\n\nSee the amount of paint needed for each room listed below:" << std::endl;
    for (int i = 0; i < numRooms; i++)
    {
        std::cout << roomNames[i] << " requires " << gallonsNeeded[i] << " gallons or " << litresNeeded[i] << " litres" << std::endl;
    }

    // Get list of supplies
    std::cout << "\n\nNow we need a list of supplies/items needed to complete this job. Press \"return\" or \"enter\" when complete." << std::endl;
    std::cout << "\nPlease enter them below:" << std::endl;
    std::cin.ignore();
    while (std::getline(std::cin, input) && !input.empty())
    {
        supplies.push_back(input);
    }

    // Ask if the user has forgotten any supplies
    std::string forgottenResponse;
    std::cout << "\nHave you forgotten any supplies? (yes/no): ";
    std::getline(std::cin, forgottenResponse);

    while (forgottenResponse == "yes")
    {
        std::cout << "\n\nPlease enter the additional supplies below (press \"return\" or \"enter\" when complete):" << std::endl;
        while (std::getline(std::cin, input) && !input.empty())
        {
            supplies.push_back(input);
        }
        std::cout << "\nHave you forgotten any supplies? (yes/no): ";
        std::getline(std::cin, forgottenResponse);
    }

    // Print summary
    std::cout << "\nThank you for your inputs." << std::endl;

    std::cout << "\n\nBelow is a total summary:" << std::endl;
    std::cout << std::endl;

    std::cout << "Total rooms = " << numRooms << std::endl;
    for (int i = 0; i < numRooms; i++)
    {
        std::cout << roomNames[i] << " = " << roomSquareFeet[i] << " square feet. You will need " << gallonsNeeded[i] << " gallons or " << litresNeeded[i] << " litres to paint this room."
                  << std::endl;
    }

    std::cout << "Total square footage for all rooms: " << totalSquareFeet << std::endl;
    std::cout << "Total amount of paint for all rooms: " << std::ceil(totalSquareFeet / 350) << " gallons or " << std::ceil(totalSquareFeet / 350 * 3.78541) << " litres" << std::endl;

    std::cout << "\nSupplies needed:" << std::endl;
    for (const std::string &item : supplies)
    {
        std::cout << "- " << item << std::endl;
    }
}

void calculateExteriorPainting()
{
    // ... (Same exterior code as before)
    int numRooms;
    int paintArea;
    int numSides;
    double totalSquareFeet = 0;
    std::string input;
    std::vector<std::string> supplies;
    std::vector<std::string> roomNames;
    std::vector<double> roomSquareFeet;
    std::vector<double> gallonsNeeded;
    std::vector<double> litresNeeded;

    // Get number of rooms
    std::cout << "\n\nHow many sides will be painted? ";
    std::cin >> numRooms;
    std::cin.ignore();
    roomNames.resize(numRooms);
    roomSquareFeet.resize(numRooms);
    gallonsNeeded.resize(numRooms);
    litresNeeded.resize(numRooms);

    // Get room names and dimensions
    for (int i = 0; i < numRooms; i++)
    {
        double length, width, height;
        char dummy;
        std::cout << "\nEnter the name for side " << i + 1 << ": ";
        getline(std::cin, roomNames[i]);
        std::cout << "\n\nEnter the dimensions (length, width, height) in feet for " << roomNames[i] << " (separated by commas): ";
        std::cin >> length >> dummy >> width >> dummy >> height;
        std::cin.ignore();
        roomSquareFeet[i] = 2 * height * (length + width);
        totalSquareFeet += roomSquareFeet[i];
        gallonsNeeded[i] = std::ceil(roomSquareFeet[i] / 350);
        litresNeeded[i] = std::ceil(roomSquareFeet[i] / 350 * 3.78541);
    }

    // Print room information
    std::cout << "\n\nThe total square footage for each room is listed below:" << std::endl;
    for (int i = 0; i < numRooms; i++)
    {
        std::cout << roomNames[i] << ": " << roomSquareFeet[i] << " square feet" << std::endl;
    }

    std::cout << "\n\nSee the amount of paint needed for each room listed below:" << std::endl;
    for (int i = 0; i < numRooms; i++)
    {
        std::cout << roomNames[i] << " requires " << gallonsNeeded[i] << " gallons or " << litresNeeded[i] << " litres" << std::endl;
    }

    // Get list of supplies
    std::cout << "\n\nNow we need a list of supplies/items needed to complete this job. Press \"return\" or \"enter\" when complete." << std::endl;
    std::cout << "\nPlease enter them below:" << std::endl;
    std::cin.ignore();
    while (std::getline(std::cin, input) && !input.empty())
    {
        supplies.push_back(input);
    }

    // Ask if the user has forgotten any supplies
    std::string forgottenResponse;
    std::cout << "\nHave you forgotten any supplies? (yes/no): ";
    std::getline(std::cin, forgottenResponse);

    while (forgottenResponse == "yes")
    {
        std::cout << "\n\nPlease enter the additional supplies below (press \"return\" or \"enter\" when complete):" << std::endl;
        while (std::getline(std::cin, input) && !input.empty())
        {
            supplies.push_back(input);
        }
        std::cout << "\nHave you forgotten any supplies? (yes/no): ";
        std::getline(std::cin, forgottenResponse);
    }

    // Print summary
    std::cout << "\nThank you for your inputs." << std::endl;

    std::cout << "\n\nBelow is a total summary:" << std::endl;
    std::cout << std::endl;

    std::cout << "Total rooms = " << numRooms << std::endl;
    for (int i = 0; i < numRooms; i++)
    {
        std::cout << roomNames[i] << " = " << roomSquareFeet[i] << " square feet. You will need " << gallonsNeeded[i] << " gallons or " << litresNeeded[i] << " litres to paint this room."
                  << std::endl;
    }
}

void saveOutputToFile()
{
    // Prompt user to save output to a file
    int numRooms;
    int paintArea;
    int numSides;
    double totalSquareFeet = 0;
    std::string input;
    std::vector<std::string> supplies;
    std::vector<std::string> roomNames;
    std::vector<double> roomSquareFeet;
    std::vector<double> gallonsNeeded;
    std::vector<double> litresNeeded;

    std::string saveToFile;
    std::cout << "\n\nWould you like to save the output to a file? (yes/no): ";
    std::getline(std::cin, saveToFile);

    if (saveToFile == "yes")
    {
        std::string filename;
        std::cout << "\nEnter the file name (e.g., output.txt): ";
        std::getline(std::cin, filename);

        std::ofstream outputFile(filename);

        if (outputFile.is_open())
        {
            outputFile << "\n\nTotal rooms = " << numRooms << std::endl;
            for (int i = 0; i < numRooms; i++)
            {
                outputFile << roomNames[i] << " = " << roomSquareFeet[i] << " square feet. You will need " << gallonsNeeded[i] << " gallons or " << litresNeeded[i] << " litres to paint this room.\n"
                           << std::endl;
            }

            outputFile << "\nTotal square footage for all rooms: " << totalSquareFeet << std::endl;
            outputFile << "\nTotal amount of paint for all rooms: " << std::ceil(totalSquareFeet / 350) << " gallons or " << std::ceil(totalSquareFeet / 350 * 3.78541) << " litres" << std::endl;

            outputFile << "\nSupplies needed:" << std::endl;
            for (const std::string &item : supplies)
            {
                outputFile << "- " << item << std::endl;
            }

            outputFile.close();
            std::cout << "\n\nOutput saved to " << filename << std::endl;
            std::filesystem::path currentPath = std::filesystem::current_path();
            std::cout << "\n\nThe file was saved to: " << currentPath / filename << std::endl;
        }
        else
        {
            std::cout << "\n\nUnable to open file " << filename << " for writing." << std::endl;
        }
    }
}