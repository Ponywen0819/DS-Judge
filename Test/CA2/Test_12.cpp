#include "./Date.h"
#include "./Date.cpp"
#include <iostream>
#include <string>


int main() {
	

	Date d = Date(10, 10, 2018);
	Date d1 = Date(12, 12, 12);
	Date d2 = Date(3, 3, 4000);
	
	//0#732613#-723690
    std::cout << d.difference(d);
	std::cout << "#";
	std::cout << d.difference(d1);
	std::cout << "#";
	std::cout << d.difference(d2);

	exit(0);
}