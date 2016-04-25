#include "elem.h"

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
	T2 operator[](const T1 key)
	{

		T2 result;
		if(_size=0)
		{
			up.set(key);
			++_size;
			return up.get_val();
		}
		else
		{
			return get_set(key);
		}
	}

	T2 get_set(const T1 key)
	{
		elem<T1,T2>* cor;
		cor = &up;
		while(true)
		{
			if(cor->get_key()<key)
			{
				if(cor->get_right() != nullptr)
				{
					cor = cor->get_right();
				}
				else
				{
					cor->set_right((new elem<T1, T2>(key)));
				}
			}
			else if(cor->get_key()>key)
			{
				if(cor->get_left() != nullptr)
				{
					cor = cor->get_left();
				}
				else
				{
					cor->set_left(new elem<T1, T2>(key));
					return cor->get_left()->get_val();
				}
			}
			else if(cor->get_key()==key)
			{
				return cor->get_val();
			}

		}
	}
	void clear()
	{

	}
	void operator=(const int &_val)
	{

	}

protected:
	unsigned int _size = 0;
	elem<T1, T2> up;
};
