
#include <ctime>
#include <iostream>
#include <stdlib.h>

#include "./Integer.h"
#include "./Double.h"
#include "./Double.cpp"
#include "./String.h"
#include "./Entry.h"
#include "./HashTableChained.h"
#include "./CheckerBoard.h"
#include "./HashTableChained.cpp"

template<typename K, typename V>
void initTable(HashTableChained<K, V>* table, int numBoards);

int main() {

    int numBoards = 100;

    HashTableChained<Double*, Integer*>* table = new HashTableChained<Double*, Integer*>(numBoards);
    initTable(table, numBoards);
	
	std::cout<<table->size()<< ", ";
	std::cout<<table->find(new Double(numBoards-1))<< ", ";
	table->remove(new Double(numBoards-1));
	std::cout<<table->find(new Double(numBoards-1))<< ", ";
	table->makeEmpty();
	std::cout<<table->isEmpty()<< ", ";
	table->insert(new Double(10000), new Integer(10000));
	table->insert(new Double(20000), new Integer(20000));
	std::cout<<table->size();

	exit(0);
}

template<typename K, typename V>
void initTable(HashTableChained<K, V>* table, int numBoards) {
    table->makeEmpty();
    for (int i = 0; i < numBoards; i++) {
        table->insert(new Double(i), new Integer(i));
    }
}

