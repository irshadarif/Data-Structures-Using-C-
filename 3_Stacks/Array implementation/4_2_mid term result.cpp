#include <iostream>
#include<assert.h>
#include <iomanip>
#include <fstream>
#include <string>
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
	stackType stack(100);
	int Reg; // used to read name of employee from file
	float Q1,Q2,Q3,Q4,Q5,Q6,Q7; // used to read salary of employee from file
	float CLO1,CLO2,CLO3,total; // used to read dept of employee from file
	int highestMarks;
	
	ifstream inFile; // Handle for the input file
	char inputFileName[] = "4_2_mid term result.txt"; // file name, this file is in the current directory
	inFile.open(inputFileName); // Opening the file
	
	if (!inFile) //Step 3
	{
		cout << "The input file does not exist. Program terminates!" << endl;
		return 1;
	}
//	cout << fixed << showpoint; //Step 4
//	cout << setprecision(2); //Step 4
	inFile >> Reg >> Q1 >> Q2>> Q3	>> Q4 >> Q5	>> Q6 >> Q7 >> CLO1 >> CLO2 >> CLO3 >> total; //Step 5
	highestMarks = total; //Step 6
	while (inFile) //Step 7
	{
		if (total > highestMarks) //Step 7.1
		{
			stack.initializeStack(); //Step 7.1.1
			if (!stack.isFullStack()) //Step 7.1.2
				stack.push(Reg);
				highestMarks = total; //Step 7.1.3
		}
		else if (total == highestMarks) //Step 7.2
			if (!stack.isFullStack())
				stack.push(Reg);
			else
			{
				cout << "Stack overflows Program terminates!" << endl;
				return 1; //exit program
			}
		inFile >> Reg >> Q1 >> Q2>> Q3	>> Q4 >> Q5	>> Q6 >> Q7 >> CLO1 >> CLO2 >> CLO3 >> total;; //Step 7.3
	}
	cout << "Highest Marks = " << highestMarks << endl;//Step 8
	cout << "The students holding the highest Marks have reg no:" << endl;
	while (!stack.isEmptyStack()) //Step 9
		{
			cout << stack.top() << endl;
			stack.pop();
		} 
cout << endl;
return 0;
}

	
