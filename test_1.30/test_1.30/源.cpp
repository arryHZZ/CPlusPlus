#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>

using namespace std;

void swap(std::vector<int>::iterator& num1, std::vector<int>::iterator& num2)
{
	int tmp = *num1;
	*num1 = *num2;
	*num2 = tmp;
}

void rotate(vector<int>& nums, int k) {
	
	int len = nums.size();
	k %= len;
	std::vector<int>::iterator Begin;
	std::vector<int>::iterator End;
	Begin = nums.begin();
	End = nums.end();
	auto begin = Begin;
	auto end = End - 1;

	while (k--)
	{
		swap(begin, end);
		begin++;
		end--;
	}
	auto begin1 = Begin;
	auto end1 = begin - 1;
	auto begin2 = begin;
	auto end2 = End - 1;
	while (begin < end)
	{
		swap(begin, end);
		begin++;
		end--;
	}
	while (begin1 < end1)
	{
		swap(begin1, end1);
		begin1++;
		end1--;
	}
	while (begin2<end2)
	{
		swap(begin2, end2);
		begin2++;
		end2--;
	}
}

int main()
{
	vector<int> arr;
	arr.resize(7);
	for (int i = 0; i < 7; i++)
	{
		arr[i] = i;
	}
	arr.erase(arr.begin());
	rotate(arr, 6);
	return 0;
}