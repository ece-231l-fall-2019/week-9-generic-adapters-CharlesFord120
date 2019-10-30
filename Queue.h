template<typename T>
class Queue
{
	protected:
		List<T> c;
	public:
		Queue()
		{
		}
		Queue(std::initializer_list<T> x) : c(x)
		{
		}
		T& front()
		{
			return c.front();
		}
		T& back()
		{
			return c.back();
		}
		const T& front() const
		{
			return c.front();
		}
		const T& back() const
		{
			return c.back();
		}
		void push(const T& a)
		{
			c.push_front(a);
		}
		void pop()
		{
			c.pop_front();
		}
		size_t size() const
		{
			return c.size();
		}
		bool empty() const
		{
			return c.empty();
		}
		Queue<T>& operator=(const Queue<T>& x)
		{
			c = x.c;
			return *this;
		}
		template<typename XX>
		friend bool operator==(const Queue<XX>&, const Queue<XX>&);
		template<typename XX>
		friend bool operator!=(const Queue<XX>&, const Queue<XX>&);

};
template<typename T>
bool operator==(const Queue<T>& x, const Queue<T>& y)
{
	return x.c == y.c;
}
template<typename T>
bool operator!=(const Queue<T>& x, const Queue<T>& y)
{
	return x.c != y.c;
}
