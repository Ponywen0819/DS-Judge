#include "./Date.h"
#include "./Date.cpp"
#include <iostream>
#include <string>

int main() {
	

	Date d = Date(12, 31, 4000);
	Date d1 = Date(12, 30, 4000);
	Date d2 = Date(1, 1, 4001);
	
	//0#0#1
    std::cout << d.isBefore(d);
	std::cout << "#";
	std::cout << d.isBefore(d1);
	std::cout << "#";
	std::cout << d.isBefore(d2);

	exit(0);
}
