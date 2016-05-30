#include "mapb.h"
#include <iostream>
#include <map>
#include "gtest/gtest.h"
#include <vector>

using namespace std;





TEST(mapb)
{

	mapb<int, int> mpb; 
	ASSERT_EQ(mpb.size(), 0); // Проверка на размер мапы, изначальна должна быть нуль.
	ASSERT_EQ(mpb.find(10), false); //Проверка на наличие элемента с ключом 10, должен отсутствовать
	mpb[10] = 30;//добавление элемента с ключом 10 и значением 30
	ASSERT_EQ(mpb.find(10), true); //проверка на наличие элемента с ключом 10, должен присутствовать.
	ASSERT_EQ(mpb[10], 30); //проверка элемента с ключом 10, должно быть 30
	ASSERT_EQ(mpb.find(11), false); //проверка на наличие элемента с ключом 11, должен отсутствовать
	ASSERT_EQ(mpb.size(), 1);//проверка размера мапы, должна быть 1.

}
TEST(elem)
{
	elem<int, int> el(1);
	ASSERT_EQ(el.get_right(), nullptr); //проверка указателя на правый элемент, должен быть nullptr
	ASSERT_EQ(el.get_left(), nullptr); //проверка указателя на левый элемент, должен быть nullptr
	ASSERT_EQ(el.get_key(), 1); // проверка ключа элемента, должен быть 1
	ASSERT_EQ(el.get_val(), 0);//проверка значения ключа, должно быть 0
	el.set(5);//установка ключа 5
	ASSERT_EQ(el.get_key(), 5); //проверка ключа, должно быть 5
	el.set_val(5); //установка значения в 5
	ASSERT_EQ(el.get_val(), 5); //проверка значения
	el.set_left(10); //установка левого  элемента в 10
	ASSERT_THROW(el.set_left(10), char*); //проверка на повторное создание левого элемента, должно быть получено исключение
	ASSERT_EQ(el.get_left()->get_key(), 10); //проверка ключа левого элемента
	el.set_right(1);//установка правого элемента
	ASSERT_THROW(el.set_right(1), char*); //проверка на повторное создание правого элемента, должно быть получено исключение

	
}

int main(int argc, char* argv[])
{


		::testing::InitGoogleTest(&argc, argv);
	RUN_ALL_TESTS();

	cin.get();

}