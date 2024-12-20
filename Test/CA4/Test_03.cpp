
//#include "mingw.thread.h"
#include <ctime>
#include <iostream>

#include <string>
#include <stdlib.h>
#include "./Integer.h"
#include "./Double.h"
#include "./Double.cpp"
#include "./String.h"
#include "./String.cpp"
#include "./HashTableChained.h"
#include "./CheckerBoard.h"
#include "./HashTableChained.cpp"
#include "./CheckerBoard.cpp"
/*
void timeOut() {
	
	int wait_time = 20;
	std::string measure;
	time_t st,et;
	clock_t sc,ec;

	st=time(NULL);
	while(time(NULL)-st<wait_time);
	et=time(NULL);
	std::cout<<"Time Out in waiting "<<et-st<<"s";
	
	exit(0);
}*/

int main() {
	
//	std::thread mThread( timeOut );

    int numBoards = 10000;

    HashTableChained<Double*, Integer*>* table = new HashTableChained<Double*, Integer*>(numBoards);
    table->makeEmpty();
    for (int i = 0; i < numBoards; i++) {
        table->insert(new Double(i), new Integer(i));
    }
	
	std::cout<<table->size()<< ", ";
	std::cout<<table->find(new Double(numBoards-1))<< ", ";
	table->remove(new Double(numBoards-1));
	std::cout<<table->find(new Double(numBoards-1))<< ", ";
	table->makeEmpty();
	std::cout<<table->isEmpty()<< ", ";
	table->insert(new Double(10000), new Integer(10000));
	table->insert(new Double(20000), new Integer(20000));
	std::cout<<table->size();
	
	std::cout<<"#";
	
	HashTableChained<String*, Integer*>* stringTable = new HashTableChained<String*, Integer*>(numBoards);
    stringTable->makeEmpty();
    for (int i = 0; i < numBoards; i++) {
        stringTable->insert(new String(std::to_string(i)), new Integer(i));
    }
	
	std::cout<<stringTable->size()<< ", ";
	std::cout<<stringTable->find(new String(std::to_string(numBoards-1)))<< ", ";
	stringTable->remove(new String(std::to_string(numBoards-1)));
	std::cout<<stringTable->find(new String(std::to_string(numBoards-1)))<< ", ";
	stringTable->makeEmpty();
	std::cout<<stringTable->isEmpty()<< ", ";
	stringTable->insert(new String("aaaaaa"), new Integer(10000));
	stringTable->insert(new String("bbbbbb"), new Integer(20000));
	std::cout<<stringTable->size();
	
	exit(0);
}