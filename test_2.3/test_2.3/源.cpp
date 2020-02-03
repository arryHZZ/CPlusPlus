#define _CRT_SECURE_NO_WARNINGS
#include<vector>
#include<iostream>

using namespace std;

int searchInsert(vector<int>& nums, int target) {
	int begin = 0;
	int end = nums.size() - 1;
	int mid = (begin + end) / 2;
	while (begin <= end)
	{
		mid = (begin + end) / 2;
		if (nums[mid] == target)
		{
			return mid;
		}
		else if (nums[mid] < target)
		{
			begin = mid + 1;
		}
		else if (nums[mid] > target)
		{
			end = mid - 1;
		}
	}
	if (begin == -1)
	{
		return 1;
	}
	if (end == nums.size())
	{
		return nums.size();
	}
	if (nums[mid] > target)
		return mid;
	else
		return mid + 1;
}

int main()
{
	vector<int> arr;
	arr.resize(5);
	for (int i = 0; i < 5; i++)
	{
		arr[i] = i;
	}
	int ret = searchInsert(arr, 2);
	cout << ret << endl;
	return 0;
}
