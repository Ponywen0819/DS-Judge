#include <ctime>
#include <iostream>
#include <cassert>
#include "./DList.h"
#include "./DList.cpp"
#include "./DListNode.h"
#include "./DListNode.cpp"
#include "./LockDList.h"
#include "./LockDList.cpp"
#include "./LockDListNode.h"
#include "./LockDListNode.cpp"

using namespace std;

int main() {
	LockDList<const char*> ld1;
	
	ld1.insertFront("Apple");
	ld1.insertBack("Candy");
	ld1.insertAfter("Cindy", ld1.next(ld1.front()));
	ld1.insertBefore("Adam", ld1.back());
	ld1.insertFront("Tony");
	std::cout << endl;
	ld1.toString();
	
	std::cout << endl;
	std::cout << "#";
	std::cout << endl;
	
	ld1.lockNode(ld1.back());
	ld1.lockNode(ld1.front());
	DListNode<const char*>* ld1backNode = ld1.back();
	int ld1length = ld1.length();
	for(int i = 0; i < ld1length; i++) {
		DListNode<const char*>* temp = ld1.prev(ld1backNode);
		ld1.remove(temp);
		temp = ld1backNode;
	}
	std::cout << endl;
	ld1.toString();
	
	exit(0);
}
