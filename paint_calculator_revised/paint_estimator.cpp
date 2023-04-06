/* To compile:
    g++ -o paint_estimator paint_estimator.cpp -std=c++11
    ./paint_estimator
*/

#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <iomanip>
#include <fstream>
#include <filesystem>

struct PaintJob
{
    int numRooms;
    double totalSquareFeet = 0;
    std::vector<std::string> roomNames;
    std::vector<double> roomSquareFeet;
    std::vector<double> gallonsNeeded;
    std::vector<double> litresNeeded;
    std::vector<std::string> supplies;

    double area;
    double paintCost;
    double laborCost;
    double totalTime;
    double totalCost;
};

void calculatePainting(PaintJob &paintJob, bool isInterior);
void saveOutputToFile(const PaintJob &paintJob, const std::string &filename);

int main()
{
    int paintArea;
    PaintJob interiorJob, exteriorJob;

    std::cout << "Welcome to the Paint Calculator!\n\n"
              << std::endl;

    std::cout << "What are you painting today?" << std::endl;
    std::cout << "1) Interior" << std::endl;
    std::cout << "2) Exterior" << std::endl;
    std::cout << "3) Both Interior & Exterior" << std::endl;
    std::cout << "\nEnter your selection: ";
    std::cin >> paintArea;
    std::cin.ignore();

    switch (paintArea)
    {
    case 1:
        std::cout << "Enter the interior area to be painted in square feet: ";
        std::cin >> interiorJob.area;
        calculatePainting(interiorJob, true);
        saveOutputToFile(interiorJob, "interior_output.txt");
        break;
    case 2:
        std::cout << "Enter the exterior area to be painted in square feet: ";
        std::cin >> exteriorJob.area;
        calculatePainting(exteriorJob, false);
        saveOutputToFile(exteriorJob, "exterior_output.txt");
        break;
    case 3:
        std::cout << "Enter the interior area to be painted in square feet: ";
        std::cin >> interiorJob.area;
        std::cout << "Enter the exterior area to be painted in square feet: ";
        std::cin >> exteriorJob.area;
        calculatePainting(interiorJob, true);
        calculatePainting(exteriorJob, false);
        saveOutputToFile(interiorJob, "interior_output.txt");
        saveOutputToFile(exteriorJob, "exterior_output.txt");
        break;
    default:
        std::cout << "Invalid selection. Please try again." << std::endl;
        break;
    }
    return 0;
}

void calculatePainting(PaintJob &paintJob, bool isInterior)
{
    double paintPricePerGallon = isInterior ? 20.0 : 30.0;
    double sqFeetPerGallon = 350.0;
    double laborRatePerHour = 20.0;
    double sqFeetPerHour = 150.0;

    int gallonsRequired = std::ceil(paintJob.area / sqFeetPerGallon);
    paintJob.paintCost = gallonsRequired * paintPricePerGallon;
    paintJob.totalTime = paintJob.area / sqFeetPerHour;
    paintJob.laborCost = paintJob.totalTime * laborRatePerHour;
    paintJob.totalCost = paintJob.paintCost + paintJob.laborCost;
}

void saveOutputToFile(const PaintJob &paintJob, const std::string &filename)
{
    std::ofstream outputFile(filename);

    if (!outputFile)
    {
        std::cerr << "Error: Could not open the output file." << std::endl;
        return;
    }

    outputFile << "Area: " << paintJob.area << " square feet" << std::endl;
    outputFile << "Paint cost: $" << paintJob.paintCost << std::endl;
    outputFile << "Labor cost: $" << paintJob.laborCost << std::endl;
    outputFile << "Total time: " << paintJob.totalTime << " hours" << std::endl;
    outputFile << "Total cost: $" << paintJob.totalCost << std::endl;

    outputFile.close();
}
