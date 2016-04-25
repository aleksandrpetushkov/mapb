#include "mapb.h"
#include <iostream>
#include <map>
#include <vector>

using namespace std;

unsigned int main()
{
	vector<int> vk;
	map<int, int> mp;
	
	cout << mp[1];
	cout << mp[2];
	mp[10]=10;
	cout << mp[-1];
	cout << mp.size();
	
	cout << "Hw";
	


	mapb<int, int> mpb;
	mpb[0];
	cout <<endl <<mpb[0];
	mpb[0] = 1;

	cin.get();
}