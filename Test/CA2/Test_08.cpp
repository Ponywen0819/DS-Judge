#include "./Date.h"
#include "./Date.cpp"
#include <iostream>
#include <string>

int main() {
	

	Date d = Date(1, 1, 4000);
	Date d1 = Date(12, 31, 3999);
	Date d2 = Date(12, 31, 5000);
	
	//0#1#0
    std::cout << d.isAfter(d);
	std::cout << "#";
	std::cout << d.isAfter(d1);
	std::cout << "#";
	std::cout << d.isAfter(d2);

	exit(0);
}
