#define _CRT_SECURE_NO_WARNINGS
#include <vector>
#include <set>
#include <map>
#include <iostream>
using namespace std;

//void coinscount(vector<int>& coins, int amount, int& count ,int& falg)
//{
//	auto begin = coins.rbegin();
//	if (amount > 0)
//	{
//	//	auto begin = coins.rbegin();
//		while (begin != coins.rend())
//		{
//			count++;
//
//			coinscount(coins, amount - *begin, count, falg);
//			if (falg == 1)
//				break;
//			begin++;
//		}
//	}
//	else if (amount == 0)
//	{
//		falg = 1;
//		return;
//	}
//	else if (amount < 0)
//	{
//		count--;
//		return;
//	}
//	if (begin == coins.rend())
//		count = -1;
//}
//
//int coinChange(vector<int>& coins, int amount) {
//	int count = 0;
//	int falg = 0;
//	coinscount(coins, amount, count, falg);
//	return count;
//}
//
//int main()
//{
//	vector<int> coins = { 2 , 4};
//	int amount = 11;
//	int ret = coinChange(coins, amount);
//	return 0;
//}

//int f(int n, set<int>& st)
//{
//	if (n == 0)
//		return 0;
//	if (st.find(n) != st.end())
//	{
//		return 1;
//	}
//}

int minf(vector<int>& coins, int amount, map<int, int> mp)
{
	int min = INT_MAX - 1;
	int tmp;
	int falg = 0;
	for (auto e : coins)
	{
		int m = amount - e;
		if (mp.find(m) == mp.end())
		{
			continue;
		}
		if (m == 0)
		{
			min = 0;
			falg = 1;
		}
		else if (m > 0)
		{
			tmp = mp[m];
			if (tmp < min)
			{
				min = tmp;
			}
			falg = 1;
		}
	}
	if (falg == 0)
		return - 1;
	else 
		return min;
}

int coinChange(vector<int>& coins, int amount) {
	map<int, int> mp;
	mp[0] = 0;
	for (auto e : coins)
	{
		mp[e] = 1;
	}
	int i = 1;
	for (i = 1; i <= amount; i++)
	{
		if (mp.find(i) == mp.end())
		{
			int ret = minf(coins, i, mp);
			if (ret != -1)
				mp[i] = minf(coins, i, mp) + 1;
		}
	}
	return mp[--i];
}

int main()
{
	//[186,419,83,408]
	vector<int> coins = { 2, 4 };
	int amount = 1000;
	int ret = coinChange(coins, amount);
	cout << ret << endl;
	return 0;
}