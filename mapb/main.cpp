#include "mapb.h"
#include <iostream>
#include <map>
#include "gtest/gtest.h"
#include <vector>

using namespace std;





TEST(mapb)
{

	mapb<int, int> mpb;
	ASSERT_EQ(mpb.size(), 0);
	ASSERT_EQ(mpb.find(10), false);
	mpb[10] = 30;
	ASSERT_EQ(mpb.find(10), true);
	ASSERT_EQ(mpb[10], 30);
	ASSERT_EQ(mpb.find(11), false);
	ASSERT_EQ(mpb.size(), 1);
}
TEST(elem)
{
	elem<int, int> el(1);
	ASSERT_EQ(el.get_right(), nullptr);
	ASSERT_EQ(el.get_left(), nullptr);
	ASSERT_EQ(el.get_key(), 1);
	ASSERT_EQ(el.get_val(), 0);
	el.set(5);
	ASSERT_EQ(el.get_key(), 5);
	el.set_val(5);
	ASSERT_EQ(el.get_val(), 5);
	el.set_left(10);
	ASSERT_THROW(el.set_left(10), char*);
	ASSERT_EQ(el.get_left()->get_key(), 10);
	el.set_right(1);
	ASSERT_THROW(el.set_right(1), char*);

	
}

int main(int argc, char* argv[])
{


	/*
	vector<int> vc;
	map<int, int> mp;
	
	cout << mp[1];
	cout << mp[2];
	mp[10]=10;
	cout << mp[-1];
	cout << mp[10];
	cout << mp.size();
	
	cout << "Hw";
	
	
	mapb<int, int> mpb;
	mpb[0];
	cout <<endl <<mpb[0];
	mpb[0] = 1;
	mpb[1] = 2;
	mpb[10] = 20;
	cout << endl << mpb[0] << endl << mpb.size() << endl << mpb[3];
	
	mpb.clear();


	//*/

	::testing::InitGoogleTest(&argc, argv);
	RUN_ALL_TESTS();

	cin.get();

}