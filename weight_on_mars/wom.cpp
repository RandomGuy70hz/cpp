#include <iostream>

int main() {
  // Create a program that takes in the weight of an item and then calculates how much that item would weigh on Mars.  
  
  double weight;
  double mars;

  std::cout << "Input the weight in kg of an item: ";
  std::cin >> weight;

  //W(Mars) = W(Earth) × g(Mars)/(g(Earth)
  mars = weight * 3.721/9.8;

  std::cout << "The item weighs " << mars << "kg on Mars.\n";
}
