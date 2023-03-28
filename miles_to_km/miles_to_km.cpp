#include <iostream>

int main() {
  // Create a program that asks for a distance in miles as input. 
  
  // * miles by 1.609344.
  double miles;
  double km;

  std::cout << "Input miles: ";
  std::cin >> miles;

  km = miles * 1.609344;
  std::cout << miles << " miles in km is: " << km << "\n";

}
