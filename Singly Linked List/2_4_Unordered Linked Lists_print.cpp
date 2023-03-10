

#include <iostream>
using namespace std;
////////////////////////////////////////////////////////////////
//Definition of the node

class nodeType
	{
	public:
		int info;
		nodeType *link;
	};
/////////////////////////////////////////////////////////////////
//***********************************************************
// Author: D.S. Malik
//
// This class specifies the members to implement the basic
// properties of a linked list. This is an abstract class.
// We cannot instantiate an object of this class.
//***********************************************************
class linkedListType
	{
	private:
	void copyList(const linkedListType& otherList);
//Function to make a copy of otherList.
//Postcondition: A copy of otherList is created and assigned
// to this list.
	protected:
		int count; //variable to store the number of list elements
		nodeType *first; //pointer to the first node of the list
		nodeType *last; //pointer to the last node of the list
	public:
//		const linkedListType& operator=(const linkedListType&);//Overload the assignment operator.
//		void initializeList();//Initialize the list to an empty state.//Postcondition: first = NULL, last = NULL, count = 0;
//		bool isEmptyList() const;//Function to determine whether the list is empty.//Postcondition: Returns true if the list is empty,
		// otherwise it returns false.
		void print() const;//Function to output the data contained in each node.//Postcondition: none
//		int length() const;//Function to return the number of nodes in the list.//Postcondition: The value of count is returned.
//		void destroyList();//Function to delete all the nodes from the list.//Postcondition: first = NULL, last = NULL, count = 0;
//		int front() const;//Function to return the first element of the list.//Precondition: The list must exist and must not be empty.
		//Postcondition: If the list is empty, the program terminates;// otherwise, the first element of the list is returned.
//		int back() const;//Function to return the last element of the list.//Precondition: The list must exist and must not be empty.
		//Postcondition: If the list is empty, the program// terminates; otherwise, the last// element of the list is returned.
//		virtual bool search(const int& searchItem) const = 0;//Function to determine whether searchItem is in the list.
		//Postcondition: Returns true if searchItem is in the list,// otherwise the value false is returned.
		virtual void insertFirst(const int& newItem) = 0;//Function to insert newItem at the beginning of the list.
		//Postcondition: first points to the new list, newItem is// inserted at the beginning of the list, last points to/ the last node
		// in the list, and count is incremented by 1.
//		virtual void insertLast(const int& newItem) = 0;//Function to insert newItem at the end of the list.//Postcondition: first points 
		//to the new list, newItem is// inserted at the end of the list, last points to the// last node in the list, and count
		// is incremented by 1.
//		virtual void deleteNode(const int& deleteItem) = 0;//Function to delete deleteItem from the list.
		//Postcondition: If found, the node containing deleteItem is// deleted from the list. first points to the first node,
		// last points to the last node of the updated list, and// count is decremented by 1.
		//linkedListIterator begin();
		//Function to return an iterator at the beginning of the//linked list.//Postcondition: Returns an iterator such that current is set
		// to first.
		//linkedListIterator<Type> end();
		//Function to return an iterator one element past the last element of the linked list.Postcondition: Returns an iterator
		// such that current is set to NULL.
		linkedListType();//default constructor //Initializes the list to an empty state.Postcondition: first = NULL, last = NULL, count = 0;
		linkedListType(const linkedListType& otherList);//copy constructor
	//	~linkedListType();//destructor//Deletes all the nodes from the list.//Postcondition: The list object is destroyed.
	};
////////////////////////////////////////////////////////////////////////////////////
linkedListType::linkedListType() //default constructor
	{
	first = NULL;
	last = NULL;
	count = 0;
	}
//...............................................................

//....................................................................................
void linkedListType::print() const
	{
	nodeType *current= first; //pointer to traverse the list
//	current = first; //set current point to the first node
	while (current != NULL) //while more data to print
		{
		cout << current->info << " ";
		current = current->link;
		}
	}//end print
//...............................................................

//............................................................................
/////////////////////////////////////////////////////////////////////////////////////
class unorderedLinkedList: public linkedListType
	{
	public:
//		bool search(const int& searchItem) const;
		void insertFirst(const int& newItem);
//		void insertLast(const int& newItem);
//		void deleteNode(const int& deleteItem);
	};
/////////////////////////////////////////////////////////////////////////////////////
void unorderedLinkedList::insertFirst(const int& newItem)
	{
	nodeType *newNode; //pointer to create the new node
	newNode = new nodeType; //create the new node
	newNode->info = newItem; //store the new item in the node
	newNode->link = first; //insert newNode before first
	first = newNode; //make first point to the actual first node
	count++; //increment count
	if (last == NULL) //if the list was empty, newNode is also//the last node in the list
		last = newNode;
	}//end insertFirst
//....................................................................................


int main()
	{
	unorderedLinkedList list1, list2; //Line 5
	list1.insertFirst(10);
	list1.insertFirst(100);
	list1.insertFirst(1000);
	list1.insertFirst(10000);
	list1.print();

	return 0;
	}
