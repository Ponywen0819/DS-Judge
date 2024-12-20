#include "./Date.h"
#include "./Date.cpp"
#include <iostream>
#include <string>

int main() {
	

	Date d = Date("1/1/18");
	
	//1/1/18
    std::cout << d.toString();
	
	exit(0);
}