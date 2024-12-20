#include "./Date.h"
#include "./Date.cpp"
#include <iostream>
#include <string>


int main() {
	

	Date d = Date("10/10/2018");
	
	//10/10/2018
    std::cout << d.toString();
	
	exit(0);
}