
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
//		void initializeList();
		bool isEmptyList() const;
		void destroy();
//		void print() const;
//		void reversePrint() const;
//		int length() const;
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

////////////////////////////////////////////////////////////////
int main()
	{

	return 0;
	}
