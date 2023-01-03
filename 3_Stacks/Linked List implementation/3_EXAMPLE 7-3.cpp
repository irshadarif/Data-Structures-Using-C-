#include<iostream>
#include <iomanip>
#include <string>
#include <assert.h>

using namespace std;
class nodeType{
	public:
		nodeType()
			{link = 0;}
		int info;
		nodeType *link;
};
//------------------------------------------------------------
class linkedStackType
{
	private:
		nodeType *stackTop; //pointer to the stack
		void copyStack(const linkedStackType& otherStack);//Function to make a copy of otherStack.
	public:
		linkedStackType();
		linkedStackType(const linkedStackType& otherStack);//Copy constructor
		const linkedStackType& operator=(const linkedStackType&);//Overload the assignment operator.
		void initializeStack();
		void push(const int& newItem);
		int top() const;
		void pop();
		bool isEmptyStack() const;
	//	bool isFullStack() const; here no abstract class
		void  display() const;
};
//-------------IMPLEMENTATION---------------------------------
void linkedStackType::copyStack(const linkedStackType& otherStack)
	{
	nodeType *newNode, *current, *last;
	if (stackTop != NULL) //if stack is nonempty, make it empty
		initializeStack();
	if (otherStack.stackTop == NULL)
		stackTop = NULL;
	else
		{
		current = otherStack.stackTop; //set current to point.to the stack to be copie.copy the stackTop element of the stack
		stackTop = new nodeType; //create the node
		stackTop->info = current->info; //copy the info
		stackTop->link = NULL; //set the link field to NULL
		last = stackTop; //set last to point to the node
		current = current->link; //set current to point to the
		//next node//copy the remaining stack
		while (current != NULL)
			{
			newNode = new nodeType;
			newNode->info = current->info;
			newNode->link = NULL;
			last->link = newNode;
			last = newNode;
			current = current->link;
			}//end while
		}//end else
	} //end copyStack
//.........................................................
linkedStackType::linkedStackType()
	{
	stackTop = NULL;
	}
//-------------------------------------------------------------
linkedStackType::linkedStackType(const linkedStackType& otherStack)
{
stackTop = NULL;
copyStack(otherStack);
}//end copy constructor
//.................................................................
const linkedStackType& linkedStackType::operator=(const linkedStackType& otherStack)
{
if (this != &otherStack) //avoid self-copy
copyStack(otherStack);
return *this;
}//end operator=
//..................................................................
bool linkedStackType::isEmptyStack() const
	{
	return(stackTop == NULL);
	} //end isEmptyStack
//----------------------------------------------------------------
void linkedStackType:: initializeStack()
	{
	nodeType *temp; //pointer to delete the node
	while (stackTop != NULL) //while there are elements inthe stack
		{
		temp = stackTop; //set temp to point to the current node
		stackTop = stackTop->link; //advance stackTop to the next node
		delete temp; //deallocate memory occupied by temp
		}
	} //end initializeStack
//----------------------------------------------------------------
void linkedStackType::push(const int& newElement)
	{
	nodeType *newNode; //pointer to create the new node
	newNode = new nodeType; //create the node
	newNode->info = newElement; //store newElement in the node
	newNode->link = stackTop; //insert newNode before stackTop
	stackTop = newNode; //set stackTop to point to the top node
	newNode=0;
	} //end push
//---------------------------------------------------------------
int linkedStackType::top() const
	{
	assert(stackTop != NULL); //if stack is empty,terminate the program
	return stackTop->info; //return the top element
	}//end top
//---------------------------------------------------------------
void linkedStackType::pop()
	{
	nodeType *temp; //pointer to deallocate memory
	if (stackTop != NULL)
		{
		temp = stackTop; //set temp to point to the top node
		stackTop = stackTop->link; //advance stackTop to the
		//next node
		delete temp; //delete the top node
		}
	else
		cout << "Cannot remove from an empty stack." << endl;
	}//end pop
//---------------------------------------------------------------
void linkedStackType:: display() const
	{
	nodeType *current; //pointer to traverse the list
	current = stackTop; //set current point to the first node
	while (current != NULL) //while more data to print
		{	
		cout <<"[ "<< current->info <<" ]"<<endl;
		current = current->link;
		}
	}
//-----------------------------------------------------------------
main()
	{
	linkedStackType stack;
	linkedStackType newStack;
	//Add elements into stack
	stack.push(34);
	stack.push(43);
	stack.push(27);
	//Use the assignment operator to copy the elements
	//of stack into newStack
	newStack = stack;
	cout << "After the assignment operator, newStack: "
	<< endl;
	//Output the elements of newStack
	while (!newStack.isEmptyStack())
		{
		cout << newStack.top() << endl;
		newStack.pop();
		}
		//Use the assignment operator to copy the elements
		//of stack into otherStack
	linkedStackType otherStack(stack);
	cout << "Testing the copy constructor." << endl;
	while (!otherStack.isEmptyStack())
		{
		cout << otherStack.top() << endl;
		otherStack.pop();
		}
	return 0;
}

