#include <iostream>
#include <string>

class StringList
{
	private:
	typedef struct llist 
	{
		std::string str;
		struct llist *next;
		struct llist *prev;
	} llist;

	size_t _size;
	llist *_front;
	llist *_back;


	public:
	
	// default constructor
	StringList()
	{

		_size = 0;
		_front = 0;
		_back = 0;
	}

	// copy constructor
	StringList(const StringList&); 	

	// destructor	
	~StringList()
	{
		while(!empty())
		{
			pop_front();
		}
	}
	
	// operator =
	StringList& operator=(const StringList& a)
	{
		for(const llist* b = a._front; b != 0; b = b -> next)
		{
			push_back(b -> str);
		}
	
		return *this;
	}
	
	// front
	std::string& front()
	{
		return _front->str;
	}

	// back
	std::string& back()
	{
		return _back->str;
	}

	// size
	size_t size()
	{
		return _size;
	}


	// push_back
	void push_back(std::string str)
	{
		llist *newBackItem = new llist;
		newBackItem -> str = str;
		newBackItem -> prev = _back;
		newBackItem -> next = 0;
		
		if (_back != 0)
		{
			_back -> next = newBackItem;
		}		
		if (_front == 0)
		{
			_front = newBackItem;
		}
	
		_back = newBackItem;
		_size++;
	}

	// push_front
	void push_front(std::string str)
	{
		if (_front == 0)
		{
			llist *newNode = new llist;
			newNode -> str = str;
			newNode -> next = 0;
			newNode -> prev = 0;
			_front = newNode;
			_back = newNode;
		}
		else
		{
			llist *newFrontItem = new llist;
			newFrontItem -> str = str;
			newFrontItem -> next = _front;
			newFrontItem -> prev = 0;
			_front = newFrontItem;	
			newFrontItem -> next -> prev = newFrontItem;
		}
		_size++;
	}
	
	// pop_front
	void pop_front()
	{
		llist *saveFront = _front;
		_front = _front -> next;
		
		if (_front)
 		{
			_front -> prev = 0;
		}
		else
		{
			_back = 0;
		}
		
		delete saveFront;
		_size--;		
	}

	// pop_back
	void pop_back()
	{
		llist *saveBack = _back;
		_back = _back -> prev;
		
		if (_back)
		{
			_back -> next = _back -> next -> next;
		}
		else 
		{
			_front = 0;
		}
		
		delete saveBack;
		_back -> next = NULL;
		_size--;	
	}

	// empty
	bool empty() const
	{
		return _front == 0;
	}

	// reverse
	void reverse()
	{
		for (llist *z = _front; z != 0; z = z -> prev)
		{
			llist *temp = z -> next;
			z -> next = z -> prev;
			z -> prev = temp;
		}
		
		llist *save;
		save = _back;
		_back = _front;
		_front = save;
	}

	// unique
	void unique()
	{
		for (llist *i = _front; i != 0; i = i -> next)
		{
			while (i -> next != 0 && i -> str == i -> next -> str)
			{
				llist *save = i -> next;
				i -> next = save -> next;
				
				if (save -> next != 0)
				{
					save -> next -> prev = i;
					delete save;
				}
				else 
				{
					_back = i;
					delete save;
				}
				_size--;
			}
		}
	}

	// print
	void print() 
	{
		llist *temp = _front;
		while (temp != 0)
		{
			std::cout << temp -> str << " ";
			temp = temp -> next;
		}
		std::cout << std::endl;
	}

};
