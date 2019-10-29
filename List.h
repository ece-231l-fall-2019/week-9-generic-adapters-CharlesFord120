#include <iostream>
#include <string>
#include <initializer_list>
template<typename T>
class List
{
	private:
	typedef struct llist 
	{
		T value;
		struct llist *next;
		struct llist *prev;
	} llist;

	size_t _size;
	llist *_front;
	llist *_back;
	
	void reccopy(const llist *ptr)
	{
		if(ptr)
		{
			reccopy(ptr->next);
			push_front(ptr->value);
		}
	}

	public:
	
	// default constructor
	List()
	{

		_size = 0;
		_front = 0;
		_back = 0;
	}

	// copy constructor
	List(const List<T>& a)
	{
		clear();
		reccopy(a._front);
	}

	List(std::initializer_list<T>& a)
	{
		_size = 0;
		_front = 0;
		_back = 0;
		for(auto value : a)
		{
			push_front(value);
		}
	}
	// destructor	
	~List()
	{
		clear();
	}
	
	// operator =
	List& operator=(const List& a)
	{
		clear();
		reccopy(a._front);
		return *this;
	}
	
	// front
	T& front()
	{
		return _front->value;
	}

	const T& front() const
	{
		return _front->value;
	}

	// back
	T& back()
	{
		return _back->value;
	}
	const T& back() const
	{
		return _back->value;
	}

	// size
	size_t size() const
	{
		return _size;
	}

	// push_back
	void push_back(const T& value)
	{
		llist *ptr = new llist;
		ptr->value = value;
		ptr->next = NULL;
		ptr->prev = _back;
		if(_back != NULL)
		{
			_back->next = ptr;
		}
		if(_front == 0)
		{
			_front = ptr;
		}
		_back = ptr;
		_size++;
	}

	// push_front
	void push_front(const T& value)
	{
		llist *ptr = new llist;
		ptr->value = value;
		ptr->prev = NULL;
		ptr->next = _front;	
		_front = ptr;
		if(_back == NULL)
		{
			_back = ptr;
		}
		else
		{
			ptr->next->prev = ptr;
		}
		_front = ptr;
		_size++;
	}
	
	// pop_front
	void pop_front()
	{
		llist *saveptr = _front;
		_front = _front->next;
		if(_front)
			_front->prev = _front->prev->prev;
		else
			_back = 0;
		delete saveptr;
		_size--;		
	}

	// pop_back
	void pop_back()
	{
		llist *saveptr = _back;
		_back = _back->prev;
		if(_back)
			_back->next = _back->next->next;
		else
			_front = 0;
		delete saveptr;
		_size--;	
	}

	// empty
	bool empty() const
	{
		return (_front == 0)&&(_back == 0);	
	}

	void clear()
	{
		while(!empty())
		{
			pop_front();
		}
	}

	// reverse
	void reverse()
	{
		for (llist *z = _front; z != 0; z = z -> prev)
		{
			llist *temp = z->next;
			z->next = z->prev;
			z->prev = temp;
		}
		
		llist *save;
		save = _back;
		_back = _front;
		_front = save;
	}

	// unique
	void unique()
	{
		for (llist *ptr = _front; ptr != 0; ptr = ptr->next)
		{
			while (ptr->next != 0 && ptr->value == ptr->next->value)
			{
				llist *saveptr = ptr->next;
				ptr->next = saveptr->next;
				if (saveptr->next == 0)
				{
					saveptr->next->prev = ptr;
				}
				else 
				{
					_back = ptr;
				}
				delete saveptr;
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
			std::cout << temp->str << " ";
			temp = temp->next;
		}
		std::cout << std::endl;
	}
	template<typename V>
	friend bool operator==(const List<V>& a, const List<V>& b);
	template<typename V>
	friend bool operator!=(const List<V>& a, const List<V>& b);
};

template<typename T>
bool operator==(const List<T>& a, const List<T>& b)
{
	if(a.size() != b.size())
		return false;

	auto aptr = a._front;
	auto bptr = b._front;
	for( ;aptr != nullptr && bptr != nullptr;
			aptr=aptr->next, bptr=bptr->next)
	{
		if(aptr->value != bptr->value)
			return false;
	}
	return true;
}

template<typename T>
bool operator!=(const List<T>& a, const List<T>& b)
{
	if(a.size() != b.size())
		return true;

	auto aptr = a._front;
	auto bptr = b._front;
	for( ;aptr != nullptr && bptr != nullptr;
			aptr=aptr->next, bptr=bptr->next)
	{
		if(aptr->value != bptr->value)
			return true;
	}
	return false;
}
