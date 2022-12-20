
#include <iostream>
using namespace std;
////////////////////////////////////////////////////////////////
//Definition of the node

class nodeType
	{
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
	protected:
		int count; 
		nodeType *first; 
		nodeType *last; 
	public:
		const linkedListType& operator=(const linkedListType&);
		void initializeList();
		bool isEmptyList() const;
		void print() const;
		int length() const;
		void destroyList();
		int front() const;
		int back() const;
		virtual bool search(const int& searchItem) const = 0;
		virtual void insertFirst(const int& newItem) = 0;
		virtual void insertLast(const int& newItem) = 0;
		virtual void deleteNode(const int& deleteItem) = 0;
		linkedListType();
		linkedListType(const linkedListType& otherList);
		~linkedListType();
	};
////////////////////////////////////////////////////////////////
class unorderedLinkedList: public linkedListType
	{
	public:
		bool search(const int& searchItem) const;
		void insertFirst(const int& newItem);
		void insertLast(const int& newItem);
		void deleteNode(const int& deleteItem);
	};
int main()
	{

	return 0;
	}
