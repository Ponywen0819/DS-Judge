#include "./CA1Prob2.cpp"
#include <iostream>
using namespace std;

int main()
{
    int inputNum = 0;
    cin >> inputNum;
    int *a = showPrime(inputNum);

    cout << a[0] << "#" << a[1];

    exit(0);
}