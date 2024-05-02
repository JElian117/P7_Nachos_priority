// threadtest.cc 
//	Simple test case for the threads assignment.
//
//	Create two threads, and have them context switch
//	back and forth between themselves by calling Thread::Yield, 
//	to illustratethe inner workings of the thread system.
//
// Copyright (c) 1992-1993 The Regents of the University of California.
// All rights reserved.  See copyright.h for copyright notice and limitation 
// of liability and disclaimer of warranty provisions.

#include "copyright.h"
#include "system.h"

//----------------------------------------------------------------------
// SimpleThread
// 	Loop 5 times, yielding the CPU to another ready thread 
//	each iteration.
//
//	"which" is simply a number identifying the thread, for debugging
//	purposes.
//----------------------------------------------------------------------

void
SimpleThread(int which)
{
    int num;
    
    for (num = 0; num < 5; num++) {
	//printf("*** thread %d looped %d times\n", which, num);
	printf("*** hebra %d ciclada %d veces\n", which, num);
        currentThread->Yield();
    }
}

//----------------------------------------------------------------------
// ThreadTest
// 	Set up a ping-pong between two threads, by forking a thread 
//	to call SimpleThread, and then calling SimpleThread ourselves.
//----------------------------------------------------------------------

void printMenu();
void ExOThreads(int which);
void largestFactorial(int buffer[]);
int factorial(int number);

void
ThreadTest()
{
    //DEBUG('t', "Entering SimpleTest");

    Thread *t = new Thread("forked thread");
    Thread *t2 = new Thread("forked thread");
    
    
    //SimpleThread(0);
	int option;
	printMenu();
	scanf("%d", &option);
	switch(option)
	{
		case 1:
			t->Fork(SimpleThread, 1);

			break;

		case 2:
			t2->Fork(ExOThreads, 2);
			break;
		case 3:
			return;
	}
}

//MY FUNCTIONS

void printMenu()
{
	printf("MENU: \n");
	printf("1. Simple Thread\n");
	printf("2. Example of threads (FCFS)\n");
	printf("3. Exit\n");
	printf("Select one option:\n");
}

void ExOThreads(int which)
{
	/*Thread o1
	switch(which)
	{
		case 0:
	}*/
}

void largestFactorial(int buffer[])
{
	int greatestNumber = -999999, factorialResult;
	for(int i = 0; i < 6; i++)
	{
		if(buffer[i] > greatestNumber)
		{
			greatestNumber = buffer[i];
		}
	}
	factorialResult = factorial(greatestNumber);
	printArray(buffer);
}

int factorial(int number)
{
	if(number == 0)
		return 0;

	return factorial(number - 1)
}
