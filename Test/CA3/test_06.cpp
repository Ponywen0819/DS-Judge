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


	LockDList<char> ld1;
	
	ld1.insertFront('a');
	ld1.insertBack('b');
	ld1.insertAfter('c', ld1.next(ld1.front()));
	ld1.insertBefore('d', ld1.back());
	ld1.insertFront('e');
	ld1.insertFront('a');
	ld1.insertBack('b');
	ld1.insertAfter('c', ld1.next(ld1.front()));
	ld1.insertBefore('d', ld1.back());
	ld1.insertFront('e');
	ld1.insertFront('a');
	ld1.insertBack('b');
	ld1.insertAfter('c', ld1.next(ld1.front()));
	ld1.insertBefore('d', ld1.back());
	ld1.insertFront('e');
	ld1.insertFront('a');
	ld1.insertBack('b');
	ld1.insertAfter('c', ld1.next(ld1.front()));
	ld1.insertBefore('d', ld1.back());
	ld1.insertFront('e');
	std::cout << endl;
	ld1.toString();
	
	std::cout << endl;
	std::cout << "#";
	std::cout << endl;
	
	ld1.lockNode(ld1.back());
	ld1.lockNode(ld1.front());
	DListNode<char>* ld1backNode = ld1.back();
	int ld1length = ld1.length();
	for(int i = 0; i < ld1length; i++) {
		DListNode<char>* temp = ld1.prev(ld1backNode);
		ld1.remove(temp);
		temp = ld1backNode;
	}
	std::cout << endl;
	ld1.toString();
	
	exit(0);
}
