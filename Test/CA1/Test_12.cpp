#include "./CA1Prob4.cpp"
#include <iostream>
#include <string>
#include <iomanip>

int main() {

	std::string name = "Bluebell";
	int petal = 6;
	double price = 85.85;
	flower a = flower ("", 0, 0);
	a.setName (name);
	a.setPetal (petal);
	a.setPrice (price);
	a = flower (name, petal, price);
	
	//Bluebell#6#85.85000
    std::cout << a.getName ();
	std::cout << "#";
	std::cout << a.getPetal ();
	std::cout << "#";
	std::cout << std::fixed  <<  std::setprecision(5) << a.getPrice ();
	
	exit(0);
}