#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
using namespace std;

int main()
{
	int n;
	cin >> n;
	int max = 0;
	int add = 0;
	vector<int> arr;
	while (n--)
	{
		int tmp;
		cin >> tmp;
		arr.push_back(tmp);
	}
	auto begin = arr.begin();
	max = *begin;
	while (begin!=arr.end())
	{
		add += *begin;
		if (add < *begin)
		{
			add = *begin;
		}
		if (add > max)
		{
			max = add;
		}
		begin++;
	}
	cout << max << endl;
	return 0;
}
