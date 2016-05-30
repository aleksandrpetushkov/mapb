#include <cstddef>

template <class T1, class T2>class elem //клас эелмент дерева
{
public:
	

	elem(T1 const &key) //создание элемента по с ключом
	{
		_key = key;
	}
	void set(T1 const &key, T2 const &val) //установка значения и ключа
	{
		_key = key;
		_val = val;
	}
	void set(T1 const &key) //установка ключа
	{
		_key = key;
	}
	T2& get_val()//получение значения элемента
	{
		return _val;
	}
	T1 get_key() //получение ключа элемента
	{
		return _key;
	}
	elem *get_right() //получение указателя на правый элемент
	{
		return right;
	}
	void set_val(T1 const & val) // установка значения
	{
		_val = val;
	}
	void set_right(T2 const &key) //создание и установка правого элемента
	{
		if(right!=nullptr) // если элемент существует выброс сключения
		{
			throw "Error: create right elem, elem exist\n";
		}
		else //иначе - создание элемента
		{
			right = new elem<T1, T2>(key);
		}
	
	}

	elem *get_left() //получение указателя на левый элемент
	{
		return left;
	}
	void set_left(T1 const &key)//установка левого элемента
	{
		if(left!=nullptr)// если элемент существует - выброс исключения
		{
			throw "Error: create left elem, elem exist\n";
		}
		else //иначе создание элемента
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
