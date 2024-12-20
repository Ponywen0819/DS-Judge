#include "./Date.h"
#include "./Date.cpp"
#include <iostream>
#include <string>

int main() {

	
	Date d = Date(1, 1, 1);
	
	//28#28#28
    std::cout << d.daysInMonth(2, 1);
	std::cout << "#";
	std::cout << d.daysInMonth(2, 1111);
	std::cout << "#";
	std::cout << d.daysInMonth(2, 3000);
	
	exit(0);
}