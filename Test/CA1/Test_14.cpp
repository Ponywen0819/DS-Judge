#include "./CA1Prob5.cpp"
#include <iostream>
#include <string>
#include <iomanip>


int main() {

	double width = 10.12345;
	double length = 10.12345;
	rectangle a = rectangle (0, 0);
	a.setLength (length);
	a.setWidth (width);
	
	//10.12345#10.12345#40.49380#102.48424#1
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