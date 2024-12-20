#include "./CA1Prob1.cpp"
#include <iostream>
using namespace std;

int main()
{
    int a[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    int b[] = {5, 9, 1, 6, 0, 1, 4, 1, 2, 1, 6, 4, 4, 3};

	//0
    std::cout << dotProduct(a, b, 14);

	exit(0);
}