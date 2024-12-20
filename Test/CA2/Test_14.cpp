#include "./Date.h"
#include "./Date.cpp"
#include <iostream>
#include <string>

int main() {

	
	Date d = Date("12/31/9999");
	
	//12/31/9999
    std::cout << d.toString();
	
	exit(0);
}