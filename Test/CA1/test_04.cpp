#include "./CA1Prob4.cpp"
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

void output(flower f){
    std::cout << f.getName ();
	std::cout << "#";
	std::cout << f.getPetal ();
	std::cout << "#";
	std::cout << std::fixed  <<  std::setprecision(5) << f.getPrice () << "\n";
}

int main()
{

    string name;
    int petal;
    double price;

    cin >> name;
    cin >> petal;
    cin >> price;

    flower a = flower(name, petal, price);

    output(a);

    a.setName ("res");
	a.setPetal (petal * 2);
	a.setPrice (price * 3);

    output(a);

    exit(0);
}