#include "./CA1Prob1.cpp"
#include <iostream>

using namespace std;

int main()
{
    int n = 0;
    cin >> n;

    int a[20], b[20];

    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    for(int i=0;i<n;i++){
        cin >> b[i];
    }

    cout << dotProduct(a, b, n);

    exit(0);
}