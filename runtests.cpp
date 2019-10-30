#include <iostream>

// change the value below to 1 to run tests against your StringList class.
// change the value below to 0 to run tests against the built in std::list.
#include <stdlib.h>
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
#include <queue>
typedef std::queue<std::string> StringQueue;
typedef std::queue<int> IntQueue;
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

	int random1,random2; // used for random num generator
	// Testing IntStack
	IntStack a;
	IntStack b;

	for(int i = 0; i <= 50; i++)
		a.push(i);
	for(int i = 50; i >= 0; i--)
		b.push(i);

	Assert(a.top() == 50, "top is 50"); //1
	Assert(b.top() == 0, "Top is 0"); //2
	a.pop();
	b.pop();
	Assert(a.top() == 49, "top is 49"); //3
	Assert(b.top() == 1, "Top is 1"); //4
	IntStack c;
	c = a;
	Assert (a == c, "a == c"); //5
	Assert (a.top() == c.top(), "a.top() == c.top()");//6
	a.pop();
	Assert (a != c, "a != c"); //7

	// Testing StringStack
	StringStack d;
	StringStack e;
	
	d.push("A");
	d.push("B");
	e.push("A");
	e.push("B");
	e.push("C");
	e.pop();
	
	Assert (e == d, "e == d"); //8
	Assert (e.top() == d.top(), "e.top() == d.top()");//9
	Assert (e.top() == "B", "e.top() == B");//10
	d.pop();
	Assert (d.top() == "A", "d.top() == A");//11
	d.pop();
	Assert (d.empty() == true , "d is EMPTY");//12
	Assert (e.empty() == false , "e is NOT EMPTY");//13
	StringStack strstk = {"Hi", "Hello", "world", "Goodbye"};
	StringStack smol;
	smol = strstk;
	Assert(smol == strstk, "They are EQUAL");//38
	smol.pop();
	Assert(smol.top() == "world", "No more Goodbye");//39
	smol.pop();
	Assert(smol.top() == "Hello","smol.top() is Hello");//40
	Assert(smol != strstk, "The Stacks are not equal anymore");//41

	// Testing IntQueue
	IntQueue f;
	IntQueue g = {1,2,3,4,5,6,7,8,9,10,1000};
	for(int i = 0; i < 50; i++)
	{
		random1 = rand() % 1000 + 1;
		f.push(random1);
	}
	Assert(g != f, "g != f");//14
	while(!f.empty())
	{
		f.pop();
	}
	Assert(f.empty() == true, "f is EMPTY");//15
	Assert(g.size() == 11, "g size is 11");//16
	f = g;
	Assert(f == g, "f is equal to g");//17
	g.pop();
	Assert(g.front() == 2, "The new front for g is 2");//18
	f.pop();
	f.pop();
	Assert(f.front() == 3, "The new front for f is 3");//19
	Assert(f.back() == 1000, "The back for f is 1000");//20
	IntQueue qw;
	qw.push(6);
	qw.push(8);
	qw.push(9);
	qw.push(50);	
	while(!f.empty())
	{
		f.pop();
	}
	Assert(qw != f, "The operator not equals works for IntQueue");//49

	// Testing StringQueue
	StringQueue sa;
	StringQueue sb = {"B","A","N","A","N","A"};
	sa.push("A");
	sa.push("N");
	sa.push("A");
	sa.push("N");
	sa.push("A");
	sa.push("B");
	Assert(sa == sb, "sa is equal to sb");//21
	sa.pop();
	Assert(sa.front() == "A", "sa is at A");//22
	sb.pop();
	sb.pop();
	sb.pop();
	sb.pop();
	Assert(sb.front() == "N", "sb front is now at N");//23
	Assert(sb.back() == "A", "sb back is at A");//24
	StringQueue strque = {"I","<3","C++","and","C#"};
	strque.push("not python");
	Assert(strque.front() == "not python", "The front method works");//42
	Assert(strque.back() == "C#", "The back method works");//43
	strque.pop();
	Assert(strque.front() == "I", "The first element has been popped");//44
	Assert(strque != sb, "the function operator not equals works");//50

	//Testing IntList
	IntList ia;
	IntList ib = {1,2,6,5,7,8,12,556,482};
	ia.push_front(1);
	ia.push_front(2);
	ia.push_front(5);
	ia.push_back(6);
	ia.push_back(32);
	Assert(ia != ib, "They are not EQUAL");//25
	ia.pop_front();
	ia.pop_back();
	Assert(ia.front() == 2, "We are at 2");//26
	Assert(ib.back() == 482, "We are at 482");//27
	ib.pop_back();
	Assert(ib.back() == 556, "We are at 556");//28
	ib.clear();
	Assert(ib.empty() == true, "We are EMPTY");//29
	Assert(ia.empty() != true, "We are not EMPTY");//30
	ia.clear();
	for(int i = 0; i < 50; i++)
	{
		random1 = rand() % 1000 + 1;
		ia.push_front(random1);
		random2 = rand() % 1000 + 1;
		ia.push_back(random2);
	}
	Assert(ia.size() == 100, "ia has a size of 100");//31
	IntList ie;
	ie = ia;
	Assert(ie == ia, "The equals operator works");//45
	ie.clear();
	Assert(ie.empty() == true, "ie has been cleared and emptied");//46
	ie.push_front(1);
	ie.push_back(2);
	ie.push_front(3);
	Assert(ie.front() == 3, "The front method for IntList works");//47
	ie.push_back(4);
	ie.push_back(6);
	ie.push_front(9);
	Assert(ie.back() == 6, "The back method for IntList works");//48

	//Testing StringList
	StringList sl = {"Why so many Tests?", "I can't think of this many", "I wanna be done!", "Before the truth will set you free it will piss you off." };
	StringList ss;
	ss.push_front(sl.back());	
	Assert(ss.front() == "Before the truth will set you free it will piss you off.", "Front method works");//32
	Assert(sl.size() == 4, "I have 4 strings!");//33
	sl.pop_front();
	Assert(sl.front() == "I can't think of this many", "I am having trouble coming up with test cases");//34
	sl.pop_back();
	Assert(sl.back() == "I wanna be done!", "pop back function works");//35
	Assert(sl != ss, "The StringList are not EQUAL");//36
	StringList py;
	py.push_back("HELP ME ESCAPE");
	py.push_front("HAPPY HALLOWEEN");
	py.clear();
	Assert(py.empty() == true, "WE ARE EMPTY");//37
	
	return 0;
}


