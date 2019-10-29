#include <iostream>

// change the value below to 1 to run tests against your StringList class.
// change the value below to 0 to run tests against the built in std::list.

#include <string>

#if 1
#include "List.h"
typedef List<std::string> StringList;
typedef List<int> IntList;
#include "Stack.h"
typedef Stack<std::string> StringStack;
typedef Stack<int> IntStack;
#include "Queue.h"
typedef Queue<std::string> StringQueue;
typedef Queue<int> IntQueue;
#else
#include <list>
typedef std::list<std::string> StringList;
typedef std::list<int> IntList;
#include <stack>
typedef std::stack<std::string> StringStack;
typedef std::stack<int> IntStack;
#endif
using namespace std;
void Assert(bool cond, std::string message)
{
	if (cond)
		std::cout << "Pass: " << message << std::endl;
	else
		std::cerr << "FAIL: " << message << std::endl;
}

int main()
{
	IntList AC;
	for(int i = 0; i <= 50; i++)
		AC.push_front(i);
	cout << "The size of AC is: " << AC.size() << endl;
	// Testing IntStack
	IntStack a;
	IntStack b;

	for(int i = 0; i <= 50; i++)
		a.push(i);
	for(int i = 50; i >= 0; i--)
		b.push(i);

	Assert(a.top() == 50, "top is 50");
	Assert(b.top() == 0, "Top is 0");
	a.pop();
	b.pop();
	Assert(a.top() == 49, "top is 49");
	Assert(b.top() == 1, "Top is 1");

	IntStack c;
	c = a;
	cout << a.size() << endl;
	Assert (a == c, "a == c");
	Assert (a.top() == c.top(), "a.top() == c.top()");
	// Testing StringStack
	StringStack d;
	StringStack e;
	
	d.push("A");
	d.push("B");
	e.push("A");
	e.push("B");
	e.push("C");
	e.pop();
	
	Assert (e == d, "e == d");
	Assert (e.top() == d.top(), "e.top() == d.top()");
	Assert (e.top() == "B", "e.top() == B");
	d.pop();
	Assert (d.top() == "A", "d.top() == A");
	d.pop();
	Assert (d.empty() == true , "d is EMPTY");
	Assert (e.empty() == false , "e is NOT EMPTY");
	// Testing IntQueue
	
	// Testing StringQueue
	return 0;
}


