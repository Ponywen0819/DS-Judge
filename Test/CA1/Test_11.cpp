#include "./CA1Prob4.cpp"
#include <iostream>
#include <string>
#include <iomanip>


int main() {

	std::string name = "Prairie Rose";
	int petal = 5;
	double price = 100.75;
	flower a = flower ("", 0, 0);
	a.setName (name);
	a.setPetal (petal);
	a.setPrice (price);
	
	//Prairie Rose#5#100.75000
    std::cout << a.getName ();
	std::cout << "#";
	std::cout << a.getPetal ();
	std::cout << "#";
	std::cout << std::fixed  <<  std::setprecision(5) << a.getPrice ();
	
	exit(0);
}