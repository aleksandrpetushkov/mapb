template<class T1, class T2> class mapb
{
public:
	mapb<T1, T2>()
	{
		
	}
	unsigned int size()
	{
		return _size;
	}
	T2 operator[](const T1)
	{
		T2 result;


		return result;
	}

	void clear()
	{

	}

protected:
	unsigned int _size = 0;
};
