#define _WIN32_WINNT 0x0501
//#include "mingw.thread.h"
#include <ctime>
#include <iostream>

#include <stdlib.h>
#include <time.h>
#include "./Integer.h"
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
int main() {
	
//	std::thread mThread( timeOut );

    srand(3);

    int numBoards = 100;
	
	CheckerBoard* board = new CheckerBoard();
	CheckerBoard* checkBoard = new CheckerBoard();
    
	HashTableChained<CheckerBoard*, Integer*>* table = new HashTableChained<CheckerBoard*, Integer*>(numBoards);
    table->makeEmpty();
    for (int i = 0; i < numBoards; i++) {
		
		for (int y = 0; y < 8; y++) {
			for (int x = 0; x < 8; x++) {
				board->setElementAt(x, y, rand());
				checkBoard->setElementAt(x, y, rand()+1);
			}
		}
		
        table->insert(board, new Integer(i));
		
		if(board->equals(*checkBoard)){
			std::cout<<"0";
			break;
		}
    }
	
	std::cout<<"1, ";
	
	std::cout<<table->size()<< ", ";
	std::cout<<table->find(board)<< ", ";
	table->remove(board);
	std::cout<<table->find(board)<< ", ";
	table->makeEmpty();
	std::cout<<table->isEmpty()<< ", ";
	table->insert(board, new Integer(10000));
	table->insert(checkBoard, new Integer(20000));
	std::cout<<table->size();
	
	exit(0);
}

