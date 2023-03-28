#include <iostream>

int main()
{

    /* Instructions:
    - It should ask him what his earth weight is.
    - Ask him to enter a number for the planet he wants to fight on.
    - It should then compute his weight on the destination planet.
    */

    double earth_weight, weight;
    int planet;

    std::cout << "Input is your earth weight in kg: ";
    std::cin >> earth_weight;

    std::cout << "Input a number for the planet you want to fight on: ";
    std::cin >> planet;

    std::cout << "\n";

    /* Planet Relative Gravity:
      Earth 9.8
      1	Mercury	0.38
      2	Venus	0.91
      3	Mars	0.38
      4	Jupiter	2.34
      5	Saturn	1.06
      6	Uranus	0.92
      7	Neptune	1.19

      std::cout << "\n";
    */

    switch (planet)
    {
    case 1:
        // Mercury 0.38 || Earth 9.8
        weight = earth_weight * 0.38 / 9.8;
        std::cout << "You have chosen Mercury. \nYour weight in kg on Mercury is: " << weight << "kg\n";
        break;

    case 2:
        // Venus 0.91 || Earth 9.8
        weight = earth_weight * 0.91 / 9.8;
        std::cout << "You have chosen Venus. \nYour weight in kg on Venus is: " << weight << "kg\n";
        break;

    case 3:
        // Mars	0.38 || Earth 9.8
        // W = W(Earth) × g/(g(Earth)
        weight = earth_weight * 0.38 / 9.8;
        std::cout << "You have chosen Mars. \nYour weight in kg on Mars is: " << weight << "kg\n";
        break;

    case 4:
        // W = W(Earth) × g/(g(Earth)
        //  Jupiter 2.34 || Earth 9.8
        weight = earth_weight * 2.34 / 9.8;
        std::cout << "You have chosen Jupiter. \nYour weight in kg on Jupiter is: " << weight << "kg\n";
        break;

    case 5:
        // W = W(Earth) × g/(g(Earth)
        //  Saturn	1.06 || Earth 9.8
        weight = earth_weight * 1.06 / 9.8;
        std::cout << "You have chosen Saturn. \nYour weight in kg on Saturn is: " << weight << "kg\n";
        break;

    case 6:
        // W = W(Earth) × g/(g(Earth)
        //  Uranus	0.92 || Earth 9.8
        weight = earth_weight * 0.92 / 9.8;
        std::cout << "You have chosen Uranus. \nYour weight in kg on Uranus is: " << weight << "kg\n";
        break;

    case 7:
        // W = W(Earth) × g/(g(Earth)
        //  Neptune 1.19 || Earth 9.8
        weight = earth_weight * 1.19 / 9.8;
        std::cout << "You have chosen Neptune. \nYour weight in kg on Neptune is: " << weight << "kg\n";
        break;

    default:
        std::cout << "We have not calculated this planet..\n";
        break;
    }
}