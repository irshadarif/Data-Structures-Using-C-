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
	stackType stack(50);
	stackType copyStack(50);
	stackType dummyStack(100);
	stack.initializeStack();
	stack.push(23);
	stack.push(45);
	stack.push(38);
	copyStack = stack; //copy stack into copyStack
	cout << "The elements of copyStack: ";
	while (!copyStack.isEmptyStack()) //print copyStack
		{
		cout << copyStack.top() << " ";
		copyStack.pop();
		}
	cout << endl;
	copyStack = stack;

	if (!stack.isEmptyStack())
	cout << "The original stack is not empty." << endl
	<< "The top element of the original stack: "
	<< copyStack.top() << endl;
	dummyStack = stack; //copy stack into dummyStack
	cout << "The elements of dummyStack: ";
	while (!dummyStack.isEmptyStack()) //print dummyStack
		{
		cout << dummyStack.top() << " ";
		dummyStack.pop();
		} 
	cout << endl;
	return 0;
	}
