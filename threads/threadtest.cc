//Team members:
//Alpuche Castrejon Ana Paula
//Aranda Cazares Daniel Alejandro
//Padrón Jasso Jesús Elian


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


int Buffer[6];

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


void PrintThreadID(int which)
{
	// I do not understand anything
	printf("*** Thread name: %s\tPriority of the thread: %d\n", currentThread->getName(), currentThread->getPriority());
	currentThread->Yield();
}

//----------------------------------------------------------------------
// ThreadTest
// 	Set up a ping-pong between two threads, by forking a thread 
//	to call SimpleThread, and then calling SimpleThread ourselves.
//----------------------------------------------------------------------


void ThreadTest(char *name)
{
    DEBUG('t', "Entering SimpleTest");

    Thread *t = new Thread(name);
    t->Fork(PrintThreadID, 1);

    PrintThreadID(0);
}

void ThreadTest(char *name, int priority)
{
    DEBUG('t', "Entering SimpleTest");

    Thread *t = new Thread(name, priority);
    t->Fork(PrintThreadID, 1);

    PrintThreadID(0);
}


//FUNCTION DECLARATION
void sortThread(int N);
void printMenu();
void fillArray();
void largestFactorial(int N);
int factorial(int number);
void averageThread(int N);
void priority();

void
ThreadTest()
{
	//Program specified to use threads
    DEBUG('t', "Entering SimpleTest");
	Thread *t = new Thread("forked thread");
	
	//We choose an option
	int option;
	printMenu();
	printf("opcion\n");
	scanf("%d", &option);

	switch(option)
	{
		//Case 1 executes SimpleThread as usual
		//Function calls are inside the case
		case 1:
			t->Fork(SimpleThread, 1);
			SimpleThread(0);
			break;

		//Case 2 asks the user to fill the array
		case 2:{
			fillArray();
			
			//Creation of threads
			Thread *factorialThread = new Thread("Factorial thread");
			Thread *sortedThread = new Thread("Sorted thread");
			Thread *avgThread = new Thread("Average thread");

			//Threads being calledd
			factorialThread -> Fork(largestFactorial, 6);
			sortedThread -> Fork(sortThread, 6);
			avgThread -> Fork(averageThread, 6); //avg = Average
			break;
		}
		
		case 3:{
			priority();
		}
	}
	
}

//MY FUNCTIONS

//This function prints the menu that shows the possible options
void printMenu()
{
	printf("MENU: \n");
	printf("1. Simple Thread\n");
	printf("2. Example of threads (FCFS)\n");
	printf("3. Example of threads (Priority)\n");
	printf("4. Exit\n");
	printf("Select one option:\n");
}

//With this function Buffer gets filled
void fillArray(){
	printf("Enter 6 numbers\n");
	int i;
	
	for(i = 0; i < 6; i++){
		scanf("%d", &Buffer[i]);
		
	}
	printf("\n");
	currentThread->Yield();
}

//This function calculates the greatest number in Buffer
void largestFactorial(int N)
{
	int greatestNumber = -999999, factorialResult;
	printf("Arreglo:\n");
	for(int i = 0; i < N; i++)
	{
		printf("%d ", Buffer[i]);
		if(Buffer[i] > greatestNumber)
		{
			greatestNumber = Buffer[i];
		}
	}
	printf("\n\n");
	factorialResult = factorial(greatestNumber);
	printf("El numero mas grande del arreglo es %d, su factorial es de %d\n",greatestNumber, factorialResult);
	currentThread->Yield();
}

//This function returns the factorial of a number
int factorial(int number)
{
	if(number == 0)
		return 1;

	return number * factorial(number - 1);
}

//This function sorts Buffer in descending order
void sortThread(int N)
{
	int i, j;
	for(i = 0; i < N - 1; i++){
		for(j = i + 1; j < N; j++){
			if(Buffer[i] < Buffer[j]){
				int temp = Buffer[i];
				Buffer[i] = Buffer[j];
				Buffer[j] = temp;
				
			}
			
		}
		
	}

	printf("\n\nArreglo ordenado:\n");
	for(int d = 0; d < N; d++){
		printf("%d ", Buffer[d]);
	}
	printf("\n");
	currentThread->Yield();
}

//This function gets the integer average of Buffer
void averageThread(int N)
{
	int sum = 0;
	for(int i = 0; i < N; i++){
		sum = sum + Buffer[i];
	}

	printf("\n\nPromedio del arreglo: %d\n\n", sum/N);
}

void priority()
{
	int n, tPriority;
	char name[20];
	printf("Introduce la cantidad de hilos:\n");
	scanf("%d", &n);
	
	Thread *threads[n];
	for (int i = 0; i < n; i++)
	{
		printf("Thread name and priority:\n");
		scanf("%s", name);
		scanf("%d", &tPriority);
		threads[i] = new Thread(name, tPriority);
	}

	for (int i = 0; i < n; i++)
		threads[i]->Fork(PrintThreadID, 1);
}
