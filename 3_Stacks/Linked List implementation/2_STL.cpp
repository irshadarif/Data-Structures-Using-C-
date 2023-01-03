#include<iostream>
#include<stack>

using namespace std;
main()
{
	stack<int> intStack;
	intStack.push(2);
	intStack.push(5);
	intStack.push(6);
	cout<<"top operation:"<<endl;
	cout<<intStack.top()<<endl;
	cout<<"pop operation:"<<endl;
	intStack.pop();
	cout<<intStack.top()<<endl;
	return 0;
}
