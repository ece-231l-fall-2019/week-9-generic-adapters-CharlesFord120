template<typename T>
class Stack
{
	protected:
		List<T> c;
	public:
		Stack()
		{
		}
		Stack(std::initializer_list<T> a) : c(a)
		{
		}
		T& top()
		{
			return c.back();
		}

		const T& top() const
		{
			return c.back();
		}

		void push(const T& a)
		{
			c.push_back(a);
		}

		void pop()
		{
			c.pop_back();
		}

		size_t size() const
		{
			return c.size();
		}

		bool empty() const
		{
			return c.empty();
		}

		Stack<T>& operator=(const Stack<T>& a)
		{
			c = a.c;
			return *this;
		}
		template<typename TT>
		friend bool operator==(const Stack<TT>&, const Stack<TT>&);
		template<typename TT>
		friend bool operator==(const Stack<TT>&, const Stack<TT>&);
};

template<typename T>
bool operator==(const Stack<T>& a, const Stack<T>& b)
{
	return a.c == b.c;
}

template<typename T>
bool operator!=(const Stack<T>& a, const Stack<T>& b)
{
	return a.c != b.c;
}
