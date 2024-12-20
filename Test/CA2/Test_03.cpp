#include "./Date.h"
#include "./Date.cpp"
#include <iostream>
#include <string>


int main() {

	
	Date d = Date(1, 1, 1);
	
	//1#0#0
    std::cout << d.isValidDate(2, 28, 1);
	std::cout << "#";
	std::cout << d.isValidDate(6, 31, 2018);
	std::cout << "#";
	std::cout << d.isValidDate(2, 29, 3999);
	
	exit(0);
}
