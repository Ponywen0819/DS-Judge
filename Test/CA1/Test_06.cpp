#include "./CA1Prob2.cpp"
#include <iostream>
#include <string>


int main() {

	int *a = showPrime (104418705);
	
	//104418703#104418767
    std::cout << a[0];
	std::cout << "#";
	std::cout << a[1];
	
	exit(0);
}
