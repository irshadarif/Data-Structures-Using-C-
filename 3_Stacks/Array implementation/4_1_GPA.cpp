#include <iostream>
#include<assert.h>
#include <iomanip>
#include <fstream>
#include <string>
#include<iostream>
#include<assert.h>
using namespace std;
class stackType
{
	private:
		int maxStackSize;
		int stackTop;
		int *list;
		void copyStack(const stackType& otherStack);
	public:
		stackType(int stackSize = 100);
		stackType(const stackType& otherStack);
		const stackType& operator=(const stackType& otherStack);
		void initializeStack();
		void push(const int& newItem);
		int top() const;
		void pop();
		bool isEmptyStack() const;
		bool isFullStack() const;
};
//----------------------------------------------------------------
void stackType::copyStack(const stackType& otherStack)
	{
	delete [] list;
	maxStackSize = otherStack.maxStackSize;
	stackTop = otherStack.stackTop;
	list = new int[maxStackSize];
	//copy otherStack into this stack
	for (int j = 0; j < stackTop; j++)
		list[j] = otherStack.list[j];
	} //end copyStack
//--------------------------------------------------------------
stackType::stackType(int stackSize)
	{
	if (stackSize <= 0)
		{
		cout << "Size of the array to hold the stack must be positive." << endl;
		cout << "Creating an array of size 100." << endl;
		maxStackSize = 100;
		}
	else
	maxStackSize = stackSize; //set the stack size to the value specified by the parameter stackSize
	stackTop = 0; //set stackTop to 0
	list = new int[maxStackSize]; //create the array to hold the stack elements
	}//end constructor
//...............................................................
stackType::stackType(const stackType& otherStack)
	{
	list = NULL;
	copyStack(otherStack);
	}//end copy constructor
//--------------------------------------------------------------
const stackType& stackType::operator=(const stackType& otherStack)
	{
	if (this != &otherStack) //avoid self-copy
		copyStack(otherStack);
	return *this;
	} //end operator=
//..............................................................
void stackType::initializeStack()
	{
	stackTop = 0;
	}//end initializeStack
//---------------------------------------------------------
void stackType::push(const int& newItem)
	{
	if (!isFullStack())
		{
		list[stackTop] = newItem; //add newItem at the top
		stackTop++; //increment stackTop
		}
	else
		cout << "Cannot add to a full stack." << endl;
	}//end push
//--------------------------------------------------------
int stackType::top() const
	{
	assert(stackTop != 0); //if stack is empty, terminate the program
	return list[stackTop - 1]; //return the element of the stack
	//indicated by stackTop - 1
	}//end top
//--------------------------------------------------------------
void stackType::pop()
	{
	if (!isEmptyStack())
		stackTop--; //decrement stackTop
	else
		cout << "Cannot remove from an empty stack." << endl;
	}//end pop
//------------------------------------------------------------
bool stackType::isEmptyStack() const
	{
	return(stackTop == 0);
	}//end isEmptyStack
//------------------------------------------------------------
bool stackType::isFullStack() const
	{
	return(stackTop == maxStackSize);
	} //end isFullStack
//.................................................................
int main()
{
//Step 1
	float GPA;
	float highestGPA;
	int reg;
	stackType stack(100);
	
	ifstream infile;
	infile.open("4_1_GPA.txt"); //Step 2
	if (!infile) //Step 3
	{
		cout << "The input file does not exist. Program terminates!" << endl;
		return 1;
	}
//	cout << fixed << showpoint; //Step 4
//	cout << setprecision(2); //Step 4
	infile >> GPA >> reg; //Step 5
	highestGPA = GPA; //Step 6
	while (infile) //Step 7
		{
		if (GPA > highestGPA) //Step 7.1
			{
			stack.initializeStack(); //Step 7.1.1
			if (!stack.isFullStack()) //Step 7.1.2
				stack.push(reg);
				highestGPA = GPA; //Step 7.1.3
			}
		else if (GPA == highestGPA) //Step 7.2
			if (!stack.isFullStack())
				stack.push(reg);
			else
			{
				cout << "Stack overflows Program terminates!" << endl;
				return 1; //exit program
			}
		infile >> GPA >> reg; //Step 7.3
		}
	cout << "Highest GPA = " << highestGPA << endl;//Step 8
	cout << "The students holding the highest GPA have reg no:" << endl;
	while (!stack.isEmptyStack()) //Step 9
		{
		cout << stack.top() << endl;
		stack.pop();
		} 
	cout << endl;
	return 0;
	}

	
