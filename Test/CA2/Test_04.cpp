#include "./Date.h"
#include "./Date.cpp"
#include <iostream>
#include <string>


int main() {

	
	Date d = Date(1, 1, 1);
	
	//1#1#0
    std::cout << d.isValidDate(12, 31, 9999);
	std::cout << "#";
	std::cout << d.isValidDate(2, 2, 2);
	std::cout << "#";
	std::cout << d.isValidDate(9999, 9999, 9999);
	
	exit(0);
}
