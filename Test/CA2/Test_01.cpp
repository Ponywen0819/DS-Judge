#include "./Date.h"
#include "./Date.cpp"
#include <iostream>
#include <string>

int main() {
	Date d = Date(1, 1, 1);
	
	//1#0#1
    std::cout << d.isLeapYear(2096);
	std::cout << "#";
	std::cout << d.isLeapYear(2097);
	std::cout << "#";
	std::cout << d.isLeapYear(2000);
	
	exit(0);
}
