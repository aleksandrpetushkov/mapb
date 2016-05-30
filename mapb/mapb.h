#include "elem.h"
#include <vector>

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
	T2& operator[](const T1 key)
	{

		if(_size==0)
		{
			up = new elem<T1, T2>(key);
			++_size;
			return up->get_val();
		}
		else
		{
			return get_set(key);
		}
	}
	
	T2& get_set(const T1 &key) //Возврат ссылки на значение по ключу.
	{
		elem<T1,T2>* cor; 
		cor = up;
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
					
					cor->set_right(key);
					++_size;
					return cor->get_right()->get_val();
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
					cor->set_left(key);
					++_size;
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
		std::vector<elem<T1, T2>*> vec;
		elem<T1, T2>* cor, *cor_t;
		cor = up;
		
//k		while (cor->get_left() != nullptr || vec.empty() || cor->get_right() != nullptr)
		while(cor!=nullptr)
		{
			if(cor->get_left()!=nullptr)
			{
				if(cor->get_right()!=nullptr)
				{
					vec.push_back(cor->get_right());
				}
				cor_t = cor->get_left();
				delete cor;
				cor = cor_t;
			}
			else if(cor->get_right()!=nullptr)
			{
				cor_t = cor->get_right();
				delete cor;
				cor = cor_t;
			}
			else if(!vec.empty())
			{
				delete cor;
				cor = vec.back();
				vec.pop_back();
			}
			else
			{
				delete cor;
				cor = nullptr;
			}
		}
		_size = 0;
	}
	bool find(T1 const &key) //Провкрка на существование элемента
	{
		if(up==nullptr)
		{
			return false;
		}
		elem<T1, T2>* cor;
		cor = up;
		while (true)
		{
			if (cor->get_key()<key)
			{
				if (cor->get_right() != nullptr)
				{
					cor = cor->get_right();
				}
				else
				{
					return false;
				}
			}
			else if (cor->get_key()>key)
			{
				if (cor->get_left() != nullptr)
				{
					cor = cor->get_left();
				}
				else
				{
					return false;
				}
			}
			else if (cor->get_key() == key)
			{
				return true;
			}
		}
	}
protected:
	unsigned int _size = 0; // Размер mapb
	elem<T1, T2> *up;
};
