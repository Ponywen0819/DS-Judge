
//#include "mingw.thread.h"
#include <ctime>
#include <iostream>
#include <string>
#include <stdlib.h>

#include "./Integer.h"
#include "./Entry.h"
#include "./Double.h"
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
}
*/
template<typename K, typename V>
void initTable(HashTableChained<K, V>* table, int numBoards);

int main() {
	
//	std::thread mThread( timeOut );

    int numBoards = 100;

    HashTableChained<String*, Integer*>* table = new HashTableChained<String*, Integer*>(numBoards);
    initTable(table, numBoards);
	
	std::cout<<table->size()<< ", ";
	std::cout<<table->find(new String(std::to_string(numBoards-1)))<< ", ";
	table->remove(new String(std::to_string(numBoards-1)));
	std::cout<<table->find(new String(std::to_string(numBoards-1)))<< ", ";
	table->makeEmpty();
	std::cout<<table->isEmpty()<< ", ";
	table->insert(new String("aaaaaa"), new Integer(10000));
	table->insert(new String("bbbbbb"), new Integer(20000));
	std::cout<<table->size();
	
	exit(0);
}

template<typename K, typename V>
void initTable(HashTableChained<K, V>* table, int numBoards) {
    table->makeEmpty();
    for (int i = 0; i < numBoards; i++) {
        table->insert(new String(std::to_string(i)), new Integer(i));
    }
}

