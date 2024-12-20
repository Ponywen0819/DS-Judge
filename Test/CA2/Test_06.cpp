#include "./Date.h"
#include "./Date.cpp"
#include <iostream>
#include <string>


int main() {
	

	Date d = Date(12, 31, 4000);
	
	//12/31/4000
    std::cout << d.toString();
	
	exit(0);
}
