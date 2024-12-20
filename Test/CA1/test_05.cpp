#include "./CA1Prob2.cpp"
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;


int main()
{

	int *a = showPrime (104417767);

	//104417767#0
    std::cout << a[0];
	std::cout << "#";
	std::cout << a[1];

	exit(0);
}