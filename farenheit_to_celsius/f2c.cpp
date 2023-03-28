/*
#include <iostream>

int main() {
  
 // Temp in NY = 56
 //double tempf = 56;

 double tempf; 
 std::cout << "Input the current temperature in Farenheit: ";
 std::cin >> tempf;

 // Farenheit to Celcsius: C = (F - 32)/1.8
 double tempc;
 tempc = (tempf - 32)/1.8;

std::cout << "The temp is " << tempc << " degrees Celsius.\n";
  
}*/

#include <iostream>

int main() {
  
  double tempf;
  double tempc;
  
  // Ask the user
  std::cout << "Enter the temperature in Farenheit: ";
  std::cin >> tempf;
  
  tempc = (tempf - 32) / 1.8;
  
  std::cout << "The current temperature is " << tempc << " degrees Celsius.\n";
  
}
