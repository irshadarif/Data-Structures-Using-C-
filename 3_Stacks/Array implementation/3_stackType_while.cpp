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
	stackType a(100);
	int c=0;
	while(c!=-1)
		{
			cout<<"enter a positve int number to continue:"<<endl;
			cout<<"OR enter -1 to finish list"<<endl;
			int b;
			cin>>b;
			if(b!=-1)
			a.push(b);
			c=b;
		}
	cout<<"the top element of the stack is :";
	cout<<a.top()<<endl;

	return 0;
}
	
