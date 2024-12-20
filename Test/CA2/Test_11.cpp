#include "./Date.h"
#include "./Date.cpp"
#include <iostream>
#include <string>

int main() {
	

	
	Date d = Date(10, 10, 2018);
	Date d1 = Date(11, 11, 11);
	Date d2 = Date(12, 31, 4000);
	
	//283#315#366
    std::cout << d.dayInYear();
	std::cout << "#";
	std::cout << d1.dayInYear();
	std::cout << "#";
	std::cout << d2.dayInYear();

	exit(0);
}