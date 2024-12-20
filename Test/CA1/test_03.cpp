#include "./CA1Prob1.cpp"
#include <iostream>
using namespace std;

int main()
{

    int a[] = {1, -1, 21, 10, 99, 21, 1, 31, 97, 0, 5, 7, 8, 9, 100, 100};
    int b[] = {5, -9, -6, -6, 10, -1, 4, 23, -2, 1, 6, 4, 4, 3, 100, 100};

	//1437
    std::cout << dotProduct(a, b, 14);

	exit(0);
}