#include "mapb.h"
#include <iostream>
#include <map>
#include <vector>

using namespace std;

unsigned int main()
{
	vector<int> vc;
	map<int, int> mp;
	
	cout << mp[1];
	cout << mp[2];
	mp[10]=10;
	cout << mp[-1];
	cout << mp[10];
	cout << mp.size();
	
	cout << "Hw";
	
	
	//*
	mapb<int, int> mpb;
	mpb[0];
	cout <<endl <<mpb[0];
	mpb[0] = 1;
	mpb[1] = 2;
	mpb[10] = 20;
	cout << endl << mpb[0] << endl << mpb.size() << endl << mpb[3];
	if(mpb.find(10))
	{
		cout << "Exist\n";
	}
	else
	{
		cout << "Not exist\n";
	}
	mpb.clear();


	//*/

	cin.get();

}