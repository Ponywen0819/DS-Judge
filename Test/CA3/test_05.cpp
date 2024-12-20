#include <ctime>
#include <iostream>
#include <cassert>
#include "./DList.h"
#include "./DList.cpp"
#include "./DListNode.h"
#include "./DListNode.cpp"
using namespace std;


int main() {


	DList<char> d1;

	d1.insertFront('q');
	d1.insertFront('w');
	d1.insertFront('e');
	d1.insertBack('r'); 
	d1.insertBack('t');
	std::cout << endl;
	d1.toString();
	
	std::cout << endl;
	std::cout << "#";
	std::cout << endl;
	
	d1.insertAfter('y', d1.next(d1.front()));
	d1.insertAfter('u', d1.back());
	std::cout << endl;
	d1.toString();
	
	std::cout << endl;
	std::cout << "#";
	std::cout << endl;

	d1.insertAfter('i',NULL);
	d1.insertBefore('a', d1.front());
	d1.insertBefore('y', d1.back());
	std::cout << endl;
	d1.toString();
	
	std::cout << endl;
	std::cout << "#";
	std::cout << endl;
	
	d1.insertBefore('z',NULL);
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
