#include <ctime>
#include <iostream>
#include <cassert>
#include "./DList.h"
#include "./DList.cpp"
#include "./DListNode.h"
#include "./DListNode.cpp"
using namespace std;


int main() {
	DList<const char*> d1;

	d1.insertFront("Queen");
	d1.insertFront("King");
	d1.insertFront("Bus");
	d1.insertBack("Wendy"); 
	d1.insertBack("Amy");
	std::cout << endl;
	d1.toString();
	
	std::cout << endl;
	std::cout << "#";
	std::cout << endl;
	
	d1.insertAfter("Jerry", d1.next(d1.front()));
	d1.insertAfter("Jeff", d1.back());
	std::cout << endl;
	d1.toString();
	
	std::cout << endl;
	std::cout << "#";
	std::cout << endl;

	d1.insertAfter("Sienna",NULL);
	d1.insertBefore("Eric", d1.front());
	d1.insertBefore("Lion", d1.back());
	std::cout << endl;
	d1.toString();
	
	std::cout << endl;
	std::cout << "#";
	std::cout << endl;
	
	d1.insertBefore("Leo",NULL);
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
