#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>

using namespace std;

void N_count(vector<int> arr, int& count, int n)
{
	int add = 0;
	int sum = 1;
	for (int i = 0; i < arr.size(); i++)
	{
		add += arr[i];
		sum *= arr[i];
	}
	if (add > sum)
		count++;
	for (int i = 0; i < n; i++)
	{
		vector<int> tmp = arr;
		for (int j = i; j < tmp.size(); j++)
		{
			tmp.erase(tmp.begin() + j);
			{
				for (int z = 0; z < arr.size(); z++)
				{
					add += arr[z];
					sum *= arr[z];
				}
				if (add > sum)
					count++;
			}
		}
		vector<int> tmp1 = arr;
		tmp1.erase(tmp1.begin() + i);
		N_count(tmp1, count, n - 1);
	}
}

int main()
{
	int n;
	vector<int> arr;
	cin >> n;
	int count = 0;
	for (int i = 0; i < n; i++)
	{
		int num = 0;
		cin >> num;
		arr.push_back(num);
	}
	N_count(arr, count, n);
	cout << count;
	return 0;
}