#include <cstddef>

template <class T1, class T2>class elem
{
public:
	elem()
	{
		
	}
	elem(T1 key)
	{
		_key = key;
	}
	void set(T1 const &key, T2 const &val)
	{
		_key = key;
		_val = val;
	}
	void set(T1 const &key)
	{
		_key = key;
	}
	T2 get_val()
	{
		return _val;
	}
	T1 get_key()
	{
		return _key;
	}
	elem *get_right()
	{
		return right;
	}

	void set_right(elem<T1, T2> *elem)
	{
		right = elem;
	}


	elem *get_left()
	{
		return left;
	}
	void set_left(elem<T1, T2> *elem)
	{
		left = elem;
	}
private:
	T1 _key;
	T2 _val;
	elem *right = nullptr;
	elem *left = nullptr;
};
