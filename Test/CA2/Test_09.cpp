#include "./Date.h"
#include "./Date.cpp"
#include <iostream>
#include <string>

int main() {
	

	
	Date d = Date(10, 10, 2018);
	Date d1 = Date(10, 11, 2018);
	Date d2 = Date(10, 10, 2018);
	
	//1#0#1
    std::cout << d.isEqual(d);
	std::cout << "#";
	std::cout << d.isEqual(d1);
	std::cout << "#";
	std::cout << d.isEqual(d2);

	exit(0);
}