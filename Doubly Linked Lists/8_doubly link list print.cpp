
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
//		void reversePrint() const;
		int length() const;
//		int front() const;
//		int back() const;
//		bool search(const int& searchItem) const;
//		void insert(const int& insertItem);
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
////////////////////////////////////////////////////////////////
int main()
	{

	return 0;
	}
