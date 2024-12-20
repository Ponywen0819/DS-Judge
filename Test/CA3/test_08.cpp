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


	LockDList<double> ld1;
	
	ld1.insertFront(234.52);
	ld1.insertBack(2534.52343);
	ld1.insertAfter(2.23455, ld1.next(ld1.front()));
	ld1.insertBefore(2534.4, ld1.back());
	ld1.insertFront(23451);
	ld1.insertFront(13212);
	ld1.insertBack(35.3);
	ld1.insertAfter(5.5345, ld1.next(ld1.front()));
	ld1.insertBefore(4.2345, ld1.back());
	ld1.insertFront(12345);
	std::cout << endl;
	ld1.toString();
	
	std::cout << endl;
	std::cout << "#";
	std::cout << endl;
	
	ld1.lockNode(ld1.back());
	ld1.lockNode(ld1.front());
	DListNode<double>* ld1backNode = ld1.back();
	int ld1length = ld1.length();
	for(int i = 0; i < ld1length; i++) {
		DListNode<double>* temp = ld1.prev(ld1backNode);
		ld1.remove(temp);
		temp = ld1backNode;
	}
	std::cout << endl;
	ld1.toString();
	
	exit(0);
}
