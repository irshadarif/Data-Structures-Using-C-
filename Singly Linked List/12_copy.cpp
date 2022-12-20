

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
    	void initializeList();//Initialize the list to an empty state.//Postcondition: first = NULL, last = NULL, count = 0;
		bool isEmptyList() const;//Function to determine whether the list is empty.//Postcondition: Returns true if the list is empty,
		// otherwise it returns false.
		void print() const;//Function to output the data contained in each node.//Postcondition: none
		int length() const;//Function to return the number of nodes in the list.//Postcondition: The value of count is returned.
		void destroyList();//Function to delete all the nodes from the list.//Postcondition: first = NULL, last = NULL, count = 0;
		int front() const;//Function to return the first element of the list.//Precondition: The list must exist and must not be empty.
		//Postcondition: If the list is empty, the program terminates;// otherwise, the first element of the list is returned.
		int back() const;//Function to return the last element of the list.//Precondition: The list must exist and must not be empty.
		//Postcondition: If the list is empty, the program// terminates; otherwise, the last// element of the list is returned.
		virtual bool search(const int& searchItem) const = 0;//Function to determine whether searchItem is in the list.
		//Postcondition: Returns true if searchItem is in the list,// otherwise the value false is returned.
		virtual void insertFirst(const int& newItem) = 0;//Function to insert newItem at the beginning of the list.
		//Postcondition: first points to the new list, newItem is// inserted at the beginning of the list, last points to/ the last node
		// in the list, and count is incremented by 1.
		virtual void insertLast(const int& newItem) = 0;//Function to insert newItem at the end of the list.//Postcondition: first points 
		//to the new list, newItem is// inserted at the end of the list, last points to the// last node in the list, and count
		// is incremented by 1.
		virtual void deleteNode(const int& deleteItem) = 0;//Function to delete deleteItem from the list.
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
bool linkedListType::isEmptyList() const
	{
	return (first == NULL);
	}
//....................................................................................
void linkedListType::print() const
	{
	nodeType *current= first; //pointer to traverse the list
//	current = first; //set current point to the first node
	if (current != NULL)
		{
		while (current != NULL) //while more data to print
			{
			cout << current->info << " ";
			current = current->link;
			}
		cout<<endl;
		}//end print
	
	else 
		cout<<"List is empty";
	}

//...............................................................

int linkedListType::length() const
	{
	return count;
	}
//.....................................................................
int linkedListType::front() const
	{
//	assert(first != NULL);
	return first->info; //return the info of the first node
	}//end front
//............................................................................
int linkedListType::back() const
	{
	//assert(last != NULL);
	return last->info; //return the info of the last node
	}//end back
//..................................................................................
void linkedListType::destroyList()
	{
	nodeType *temp; //pointer to deallocate the memory//occupied by the node
	while (first != NULL) //while there are nodes in the list
		{
		temp = first; //set temp to the current node
		first = first->link; //advance first to the next node
		delete temp; //deallocate the memory occupied by temp
		} 
last = NULL; //initialize last to NULL; first has already
//been set to NULL by the while loop
count = 0;
}
void linkedListType::initializeList()
	{
	destroyList(); //if the list has any nodes, delete them
	}
void linkedListType::copyList(const linkedListType& otherList)
	{
	nodeType *newNode; //pointer to create a node
	nodeType *current; //pointer to traverse the list
	if (first != NULL) //if the list is nonempty, make it empty
		destroyList();
	if (otherList.first == NULL) //otherList is empty
		{
		first = NULL;
		last = NULL;
		count = 0;
		}
	else
		{
		current = otherList.first; //current points to the//list to be copied
		count = otherList.count;//copy the first node
		first = new nodeType; //create the node
		first->info = current->info; //copy the info
		first->link = NULL; //set the link field of the node to NULL
		last = first; //make last point to the first node
		current = current->link; //make current point to the next
		// node//copy the remaining list
		while (current != NULL)
			{
			newNode = new nodeType; //create a node
			newNode->info = current->info; //copy the info
			newNode->link = NULL; //set the link of newNode to NULL
			last->link = newNode; //attach newNode after last
			last = newNode; //make last point to the actual last
			//node
			current = current->link; //make current point to the
			//next node
			}//end while
		}//end else
	}//end copyList
/////////////////////////////////////////////////////////////////////////////////////
//                       unorderedLinkedList
/////////////////////////////////////////////////////////////////////////////////////
class unorderedLinkedList: public linkedListType
	{
	public:
		bool search(const int& searchItem) const;
		void insertFirst(const int& newItem);
		void insertLast(const int& newItem);
		void deleteNode(const int& deleteItem);
	};
/////////////////////////////////////////////////////////////////////////////////////
	bool unorderedLinkedList::search(const int& searchItem) const
	{
	nodeType *current; //pointer to traverse the list
	bool found = false;
	current = first; //set current to point to the first//node in the list
	while (current != NULL && !found) //search the list
		{	
		if (current->info == searchItem) //searchItem is found
			found = true;
		else
			current = current->link; //make current point to//the next node
		}
	return found;
	}//end search
//...................................................................................
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
void unorderedLinkedList::insertLast(const int& newItem)
	{
	nodeType *newNode; //pointer to create the new node
	newNode = new nodeType; //create the new node
	newNode->info = newItem; //store the new item in the node
	newNode->link = NULL; //set the link field of newNode to NULL
	if (first == NULL) //if the list is empty, newNode is//both the first and last node
		{
		first = newNode;
		last = newNode;
		count++; //increment count
		}
	else //the list is not empty, insert newNode after last
		{
		last->link = newNode; //insert newNode after last
		last = newNode; //make last point to the actual//last node in the list
		count++; //increment count
		}
	}//end insertLast
//..................................................................................
void unorderedLinkedList::deleteNode(const int& deleteItem)
	{
	nodeType *current; //pointer to traverse the list
	nodeType *trailCurrent; //pointer just before current
	bool found;
	if (first == NULL) //Case 1; the list is empty.
		cout << "Cannot delete from an empty list."<< endl;
	else
		{
		if (first->info == deleteItem) //Case 2
			{
			current = first;
			first = first->link;
			count--;
			if (first == NULL) //the list has only one node
				last = NULL;
			delete current;
			}
		else //search the list for the node with the given info
			{
			found = false;
			trailCurrent = first; //set trailCurrent to point//to the first node
			current = first->link; //set current to point to//the second node
			while (current != NULL && !found)
				{
				if (current->info != deleteItem)
					{
					trailCurrent = current;
					current = current-> link;
					}
				else
					found = true;
				}//end while
				if (found) //Case 3; if found, delete the node
					{
					trailCurrent->link = current->link;
					count--;
					if (last == current) //node to be deleted was the last node
						last = trailCurrent; //update the value of last
				delete current; //delete the node from the list
					}
			else
				cout << "The item to be deleted is not in "<< "the list." << endl;
			}//end else
		}//end else
	}//end deleteNode

int main()
	{
	unorderedLinkedList list1, list2; //Line 5
	list1.insertLast(10);
	list1.insertLast(100);
	list1.insertLast(1000);
	list1.insertLast(10000);
	
	list1.print();
	list1.initializeList();
	list1.print();
	
	
	return 0;
	}
