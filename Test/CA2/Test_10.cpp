#include "./Date.h"
#include "./Date.cpp"
#include <iostream>
#include <string>

int main() {
	

	Date d = Date(1, 1, 1);
	
	//1
    std::cout << d.dayInYear();

	exit(0);
}
