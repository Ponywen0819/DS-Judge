#include <ctime>
#include <iostream>
#include <cassert>
#include "./DList.h"
#include "./DList.cpp"
#include "./DListNode.h"
#include "./DListNode.cpp"
using namespace std;

int main() {


	DList<double> d1;

	d1.insertFront(1.221);
	d1.insertFront(3132221.789);
	d1.insertFront(999.2849301);
	d1.insertBack(2.839034); 
	d1.insertBack(2222134);
	d1.insertFront(1.90341);
	d1.insertFront(3);
	d1.insertFront(9123499);
	d1.insertBack(22143); 
	d1.insertBack(25422);
	std::cout << endl;
	d1.toString();
	
	std::cout << endl;
	std::cout << "#";
	std::cout << endl;
	
	d1.insertAfter(12214345, d1.next(d1.front()));
	d1.insertAfter(121323456, d1.back());
	d1.insertAfter(1254345, d1.next(d1.front()));
	d1.insertAfter(12213456, d1.back());
	d1.insertAfter(123545, d1.next(d1.front()));
	d1.insertAfter(12378456, d1.back());
	std::cout << endl;
	d1.toString();
	
	std::cout << endl;
	std::cout << "#";
	std::cout << endl;

	d1.insertAfter(3241,NULL);
	d1.insertBefore(4.234, d1.front());
	d1.insertBefore(41.2434, d1.back());
	d1.insertAfter(41.21,NULL);
	d1.insertBefore(24.314, d1.front());
	d1.insertBefore(4.4, d1.back());
	std::cout << endl;
	d1.toString();
	
	std::cout << endl;
	std::cout << "#";
	std::cout << endl;
	
	d1.insertBefore(412.31,NULL);
	d1.remove(NULL);
	d1.remove(d1.next(d1.next(d1.front())));
	d1.remove(d1.front());
	d1.remove(d1.front());
	d1.remove(d1.back());
	d1.remove(d1.back());
	d1.remove(d1.back());
	d1.remove(d1.back());
	d1.insertBefore(14231,NULL);
	d1.remove(NULL);
	d1.remove(d1.next(d1.next(d1.front())));
	d1.remove(d1.front());
	d1.remove(d1.front());
	d1.remove(d1.back());
	d1.remove(d1.back());
	d1.remove(d1.back());
	d1.remove(d1.back());
	std::cout << endl;
	d1.toString();
	
	exit(0);
}
