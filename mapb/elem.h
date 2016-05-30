#include <cstddef>

template <class T1, class T2>class elem
{
public:
	//*
	elem()
	{
		
	}
	//*/

	elem(T1 const &key)
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
	T2& get_val()
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
	void set_val(T1 const & val)
	{
		_val = val;
	}
	void set_right(T2 const &key)
	{
		if(right!=nullptr)
		{
			throw "Error: create right elem, elem exist\n";
		}
		else
		{
			right = new elem<T1, T2>(key);
		}
	
	}

	elem *get_left()
	{
		return left;
	}
	void set_left(T1 const &key)
	{
		if(left!=nullptr)
		{
			throw "Error: create left elem, elem exist\n";
		}
		else
		{
			left = new elem<T1, T2>(key);
		}
	}
protected:
	T1 _key;
	T2 _val;
	elem *right = nullptr;
	elem *left = nullptr;
};
