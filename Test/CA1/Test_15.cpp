#include "./CA1Prob5.cpp"
#include <iostream>
#include <string>
#include <iomanip>

int main() {

	double width = 0.123;
	double length = 100.123;
	rectangle a = rectangle (1, 2);
	a.setDimension (width, length);
	
	//0.12300#100.12300#200.49200#12.31513#0
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