#include "./CA1Prob5.cpp"
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

void checkParameter(rectangle rect)
{
    std::cout << std::fixed << std::setprecision(5) << rect.getWidth();
    std::cout << "#";
    std::cout << std::fixed << std::setprecision(5) << rect.getLength();
    std::cout << "#";
    std::cout << std::fixed << std::setprecision(5) << rect.getPerimeter();
    std::cout << "#";
    std::cout << std::fixed << std::setprecision(5) << rect.getArea();
    std::cout << "#";
    std::cout << std::fixed << std::setprecision(5) << rect.isSquare() << "\n";
}

int main()
{
    double width, length;
    cin >> width;
    cin >> length;

    rectangle a = rectangle(width, length);
    checkParameter(a);

    a.setLength(length * 2);
    a.setWidth(width * 4);
    checkParameter(a);

    a.setDimension(width * 3, length * 2);
    checkParameter(a);

    exit(0);
}