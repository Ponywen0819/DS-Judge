#include "./CA1Prob5.cpp"
#include <iostream>
#include <string>
#include <iomanip>


int main() {

	double width = 10;
	double length = 5;
	rectangle a = rectangle(width, length);
	
	//10.00000#5.00000#30.00000#50.00000#0
    std::cout << std::fixed  <<  std::setprecision(5) << a.getWidth ();
	std::cout << "#";
	std::cout << std::fixed  <<  std::setprecision(5) << a.getLength ();
	std::cout << "#";
	std::cout << std::fixed  <<  std::setprecision(5) << a.getPerimeter ();
	std::cout << "#";
	std::cout << std::fixed  <<  std::setprecision(5) << a.getArea ();
	std::cout << "#";
	std::cout << std::fixed  <<  std::setprecision(5) << a.isSquare ();
	
	exit(0);
}