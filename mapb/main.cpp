#include "mapb.h"
#include <iostream>
#include <map>
#include "gtest/gtest.h"
#include <vector>

using namespace std;





TEST(mapb)
{

	mapb<int, int> mpb; 
	ASSERT_EQ(mpb.size(), 0); // �������� �� ������ ����, ���������� ������ ���� ����.
	ASSERT_EQ(mpb.find(10), false); //�������� �� ������� �������� � ������ 10, ������ �������������
	mpb[10] = 30;//���������� �������� � ������ 10 � ��������� 30
	ASSERT_EQ(mpb.find(10), true); //�������� �� ������� �������� � ������ 10, ������ ��������������.
	ASSERT_EQ(mpb[10], 30); //�������� �������� � ������ 10, ������ ���� 30
	ASSERT_EQ(mpb.find(11), false); //�������� �� ������� �������� � ������ 11, ������ �������������
	ASSERT_EQ(mpb.size(), 1);//�������� ������� ����, ������ ���� 1.

}
TEST(elem)
{
	elem<int, int> el(1);
	ASSERT_EQ(el.get_right(), nullptr); //�������� ��������� �� ������ �������, ������ ���� nullptr
	ASSERT_EQ(el.get_left(), nullptr); //�������� ��������� �� ����� �������, ������ ���� nullptr
	ASSERT_EQ(el.get_key(), 1); // �������� ����� ��������, ������ ���� 1
	ASSERT_EQ(el.get_val(), 0);//�������� �������� �����, ������ ���� 0
	el.set(5);//��������� ����� 5
	ASSERT_EQ(el.get_key(), 5); //�������� �����, ������ ���� 5
	el.set_val(5); //��������� �������� � 5
	ASSERT_EQ(el.get_val(), 5); //�������� ��������
	el.set_left(10); //��������� ������  �������� � 10
	ASSERT_THROW(el.set_left(10), char*); //�������� �� ��������� �������� ������ ��������, ������ ���� �������� ����������
	ASSERT_EQ(el.get_left()->get_key(), 10); //�������� ����� ������ ��������
	el.set_right(1);//��������� ������� ��������
	ASSERT_THROW(el.set_right(1), char*); //�������� �� ��������� �������� ������� ��������, ������ ���� �������� ����������

	
}

int main(int argc, char* argv[])
{


		::testing::InitGoogleTest(&argc, argv);
	RUN_ALL_TESTS();

	cin.get();

}