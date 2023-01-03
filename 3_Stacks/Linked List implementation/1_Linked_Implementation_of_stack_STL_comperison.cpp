#include<iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <assert.h>

using namespace std;
class nodeType{
	public:
		nodeType() {
		link = 0;
		}
	int info;
	nodeType *link;
};
//------------------------------------------------------------
class linkedStackType
{
	private:
		nodeType *stackTop; //pointer to the stack
	public:
		linkedStackType();
		void initializeStack();
		void push(const int& newItem);
		int top() const;
		void pop();
		bool isEmptyStack() const;
	//	bool isFullStack() const; here no abstract class
		void  display() const;
};
//-------------IMPLEMENTATION---------------------------------
linkedStackType::linkedStackType()
	{
		stackTop = NULL;
	}
//-------------------------------------------------------------
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
//----------------------------------------------------------------
bool linkedStackType::isEmptyStack() const
	{
	return(stackTop == NULL);
	} //end isEmptyStack
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
	stack.push(2);
	stack.push(5);
	stack.push(6);
//	stack.display();
	cout<<"top operation:"<<endl;
	cout<<stack.top()<<endl;
	cout<<"pop operation:"<<endl;
	stack.pop();
	cout<<stack.top()<<endl;
	return 0;
}

