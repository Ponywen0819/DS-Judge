#include <ctime>
#include <iostream>
#include <cassert>
#include "./DList.h"
#include "./DList.cpp"
#include "./DListNode.h"
#include "./DListNode.cpp"
using namespace std;

int main() {
	DList<int> d1;

	d1.insertFront(1);
	d1.insertFront(3);
	d1.insertFront(999);
	d1.insertBack(2); 
	d1.insertBack(222);
	d1.insertFront(1);
	d1.insertFront(3);
	d1.insertFront(999);
	d1.insertBack(2); 
	d1.insertBack(222);
	d1.insertFront(1);
	d1.insertFront(3);
	d1.insertFront(999);
	d1.insertBack(2); 
	d1.insertBack(222);
	std::cout << endl;
	d1.toString();
	
	std::cout << endl;
	std::cout << "#";
	std::cout << endl;
	
	d1.insertAfter(12345, d1.next(d1.front()));
	d1.insertAfter(123456, d1.back());
	std::cout << endl;
	d1.toString();
	
	std::cout << endl;
	std::cout << "#";
	std::cout << endl;

	d1.insertAfter(1,NULL);
	d1.insertBefore(4, d1.front());
	d1.insertBefore(44, d1.back());
	std::cout << endl;
	d1.toString();
	
	std::cout << endl;
	std::cout << "#";
	std::cout << endl;
	
	DListNode<int>* d1backNode = d1.back();
	int d1length = d1.length();
	for(int i = 0; i < d1length; i++) {
		DListNode<int>* temp = d1.prev(d1backNode);
		d1.remove(temp);
		temp = d1backNode;
	}
	std::cout << endl;
	d1.toString();
	
	exit(0);
}
