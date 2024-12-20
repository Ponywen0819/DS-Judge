#include "./CA1Prob4.cpp"
#include <iostream>
#include <string>
#include <iomanip>


int main() {
	

	std::string name = "Nodding Trillium";
	int petal = 3;
	double price = 75.0;
	flower a = flower (name, petal, price);
	
	//Nodding Trillium#3#75.00000
    std::cout << a.getName ();
	std::cout << "#";
	std::cout << a.getPetal ();
	std::cout << "#";
	std::cout << std::fixed  <<  std::setprecision(5) << a.getPrice ();
	
	exit(0);
}
