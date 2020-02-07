#define _CRT_SECURE_NO_WARNINGS
#include<vector>
#include<iostream>

using namespace std;

int pivotIndex(vector<int>& nums) {
	int mid = nums.size() / 2;
	int left = 0;
	int right = nums.size() - 1;
	int AddLeft = 0;
	int AddRight = 0;
	for (int i = 0; i < mid; i++)
	{
		AddLeft += nums[i];
	}
	for (int i = right; i > mid; i--)
	{
		AddRight += nums[i];
	}
	if (AddRight == AddLeft)
	{
		return mid;
	}
	else if (AddLeft > AddRight)
	{
		while (mid > 0)
		{
			AddLeft -= nums[--mid];
			AddRight += nums[mid + 1];
			if (AddLeft == AddRight)
			{
				break;
			}
			else if (AddLeft < AddRight)
			{
				mid = -1;
				break;
			}
		}
	}
	else
	{
		while (mid < nums.size())
		{
			AddLeft += nums[mid++];
			AddRight -= nums[mid];
			if (AddLeft == AddRight)
			{
				break;
			}
			else if (AddLeft > AddRight)
			{
				mid = -1;
				break;
			}
		}

	}
	return mid;
}


vector<int> plusOne(vector<int>& digits) 
{
	auto begin = digits.rbegin();
	int add = 0;
	int prev = 1;
	while (begin != digits.rend())
	{
		*begin += prev;
		if (*begin >= 10)
		{
			prev = *begin / 10;
			*begin %= 10;
		}
		else
		{
			prev = 0;
			break;
		}
		begin++;
	}
	if (digits[0] >= 10)
	{
		prev = digits[0] / 10;
		*begin %= 10;
		digits.insert(digits.begin(), prev);
	}

	return digits;
}

int main()
{
	vector<int> nums;
	nums.resize(3);
	for (auto &e : nums)
	{
		cin >> e;
	}
	plusOne(nums);
//	nums.insert(nums.begin(), 0);
//	pivotIndex(nums);
	return 0;
}