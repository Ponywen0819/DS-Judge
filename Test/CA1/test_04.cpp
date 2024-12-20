#include "./CA1Prob2.cpp"
#include <iostream>
#include <string>
using namespace std;

int main()
{

    int *a = showPrime (104395302);

	//104395301#104395303
    std::cout << a[0];
	std::cout << "#";
	std::cout << a[1];

	exit(0);
}