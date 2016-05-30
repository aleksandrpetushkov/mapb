#include "elem.h"
#include <vector>

template<class T1, class T2> class mapb //класс мапы
{
public:
	mapb<T1, T2>() //конструктор по умолчанию
	{
		
	}
	
	unsigned int size() //метод получения размера мапы.
	{
		return _size;
	}
	T2& operator[](const T1 key) //перегрузка оператора [] для доступа к элементам через ключ, принимает ключ
	{

		if(_size==0) //если размер 0 создается верхний элемент и возвращается значение по умолчанию
		{
			up = new elem<T1, T2>(key);
			++_size;
			return up->get_val();
		}
		else//иначе поиск элемента с указанным ключом
		{
			return get_set(key);
		}
	}
	
	T2& get_set(const T1 &key) //поиск элемента с указанным ключом и возврат ссылки на значение по ключу.
	{
		elem<T1,T2>* cor; //каретка для перемещения по элементам в дереве
		cor = up; 
		while(true)
		{
			if(cor->get_key()<key) //если ключ каретки меньше указанного ключа, элемент находится справа
			{
				if(cor->get_right() != nullptr) //если правый элемент не нулевой, установка указателя каретка на указатель правого элемента
				{
					cor = cor->get_right();
				}
				else //иначе элемента в мапе нет, создание элемента с полученным ключом и значением по умолчанию, возврат значения
				{
					
					cor->set_right(key);
					++_size;
					return cor->get_right()->get_val();
				}
			}
			else if(cor->get_key()>key)//если ключ каретки больше полученного ключа, элемент находится слева
			{
				if(cor->get_left() != nullptr)//если левый элемент не нулевой установка указателя каретки на указатель элемента слева
				{
					cor = cor->get_left();
				}
				else//иначе элемента в мапе нет, создание элемента с полученным ключом и значением по умолчанию, возврат значения
				{
					cor->set_left(key);
					++_size;
					return cor->get_left()->get_val();
				}
			}
			else if(cor->get_key()==key)//если ключ каретка равен полученному ключу - элемент найден возврат значения.
			{
				return cor->get_val();
			}
		}
	}
	void clear()//очистка мапы
	{
		std::vector<elem<T1, T2>*> vec;
		elem<T1, T2>* cor, *cor_t;
		cor = up;
		while(cor!=nullptr)//пока карета не очищена, выполняется цикл
		{
			if(cor->get_left()!=nullptr) //если левый элемент не пуст
			{
				if(cor->get_right()!=nullptr) // если правый элемент не пуст
				{
					vec.push_back(cor->get_right());//отправляем правы узел в коллекцию
				}
				cor_t = cor->get_left(); //левый указатель сохраняется во временную переменную
				delete cor; //удаление элемента под кареткой
				cor = cor_t;//установка каретки указателем левого элемента из временной переменной
			}
			else if(cor->get_right()!=nullptr) //иначе если правый не пуст, очистка текущего элемента и установка каретки в значение правого элемента
			{
				cor_t = cor->get_right();
				delete cor;
				cor = cor_t;
			}
			else if(!vec.empty())//иначе если не существует ни правого ни левого элемента, достигнут низ дерева, получение элемента из коллекции если не пуста, и очистка текущего
			{
				delete cor; 
				cor = vec.back();
				vec.pop_back();
			}
			else //иначе если коллекция пуста и нет правых/левых элементов - текущий элемент последний удаление.
			{
				delete cor;
				cor = nullptr;
			}
		}
		_size = 0;
	}
	bool find(T1 const &key) //Провкрка на существование элемента по принципу в методе get_set
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
	elem<T1, T2> *up; //верхний элемент дерева.
};
