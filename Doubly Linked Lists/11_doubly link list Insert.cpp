
#include <iostream>
using namespace std;
////////////////////////////////////////////////////////////////
//Definition of the node

struct nodeType
{
int info;
nodeType *next;
nodeType *back;
};
////////////////////////////////////////////////////////////////
class doublyLinkedList
	{
	private:
		void copyList(const doublyLinkedList& otherList);
	protected:
		int count;
		nodeType *first; 
		nodeType *last; 
	public:
		doublyLinkedList();
//		const doublyLinkedList& operator=(const doublyLinkedList &);
		bool isEmptyList() const;
		void destroy();
		void initializeList();
		void print() const;
		void reversePrint() const;
		int length() const;
//		int front() const;
//		int back() const;
		bool search(const int& searchItem) const;
		void insert(const int& insertItem);
//		void deleteNode(const int& deleteItem);

//		doublyLinkedList(const doublyLinkedList& otherList);
//		~doublyLinkedList();
	};
//..............................................................
doublyLinkedList::doublyLinkedList()
	{
	first= NULL;
	last = NULL;
	count = 0;
	}
//.............................................................
bool doublyLinkedList::isEmptyList() const
	{
	return (first == NULL);
	}
//............................................................
void doublyLinkedList::destroy()
	{
	nodeType *temp; //pointer to delete the node
	while (first != NULL)
		{
		temp = first;
		first = first->next;
		delete temp;
		} 
	last = NULL;
	count = 0;
	}
//.............................................................
void doublyLinkedList::initializeList()
	{
	destroy();
	}
//..............................................................
int doublyLinkedList::length() const
	{
	return count;
	}
//................................................................
void doublyLinkedList::print() const
	{
	nodeType *current; //pointer to traverse the list
	current = first; //set current to point to the first node
	while (current != NULL)
		{
		cout << current->info << " "; //output info
		current = current->next;
		}//end while
	}//end print
//...............................................................
void doublyLinkedList::reversePrint() const
	{
	nodeType *current; //pointer to traverse the list
	current = last; //set current to point to the last node
	while (current != NULL)
		{
		cout << current->info << " ";
		current = current->back;
		}//end while
	}//end reversePrint
//..................................................................
bool doublyLinkedList ::search(const int& searchItem) const
	{
	bool found = false;
	nodeType *current; //pointer to traverse the list
	current = first;
	while (current != NULL && !found)
		{
		if (current->info >= searchItem)
			found = true;
		else
			current = current->next;
		}
		if (found)
			found = (current->info == searchItem); //test for equality
	return found;
}//end search
//................................................................
void doublyLinkedList::insert(const int& insertItem)
	{
	nodeType *current; //pointer to traverse the list
	nodeType *trailCurrent; //pointer just before current
	nodeType *newNode; //pointer to create a node
	bool found;
	newNode = new nodeType; //create the node
	newNode->info = insertItem; //store the new item in the node
	newNode->next = NULL;
	newNode->back = NULL;
	if (first == NULL) //if list is empty, newNode is the only node
		{
		first = newNode;
		last = newNode;
		count++;
		}
	else//search the list
		{
		found = false;
		current = first;
		while (current != NULL && !found) //search the list
			{
			if (current->info >= insertItem)
				found = true;
			else
				{
				trailCurrent = current;
				current = current->next;
				}
			}
	if (current == first) //insert newNode before first
		{
		first->back = newNode;
		newNode->next = first;
		first = newNode;
		count++;
		}
	else//insert newNode between trailCurrent and current
		{	
		if (current != NULL)//between like 20
			{
			trailCurrent->next = newNode;
			newNode->back = trailCurrent;
			newNode->next = current;
			current->back = newNode;
			}
		else // insert last like 45
			{
			trailCurrent->next = newNode;
			newNode->back = trailCurrent;
			last = newNode;
			} 
	count++;
		}//end else
	}//end else
	}//end insert
////////////////////////////////////////////////////////////////
int main()
	{
	doublyLinkedList list1, list2; //Line 5
	int num; 
	cout << " Enter numbers ending with -999." << endl; 
	cin >> num; 
	while (num != -999) 
		{ 
		list1.insert(num); 
		cin >> num; 
		}
	list1.print();

	return 0;
	}
