#include<iostream>
#include<stack>

using namespace std;
main()
{
	stack<int> intStack;
	intStack.push(16); 
	intStack.push(8); 
	intStack.push(20); 
	intStack.push(3);
	cout << "The top element of intStack: "
	<< intStack.top() << endl; 
	intStack.pop(); 
	cout << "After the pop operation, the top element of intStack: "
	<< intStack.top() << endl; 
	cout << "intStack elements: "; 
	while (!intStack.empty()) 
		{ 
		cout << intStack.top() << " "; 
		intStack.pop(); 
		} 
	cout << endl; 
	return 0; 
	} 

