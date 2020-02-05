#define _CRT_SECURE_NO_WARNINGS
#include<string>
#include<vector>
#include<iostream>

using namespace std;

bool canConstruct(string ransomNote, string magazine) {
	int ascll1[256] = { 0 };
	int ascll2[256] = { 0 };
	auto begin = ransomNote.begin();
	while (begin != ransomNote.end())
	{
		ascll1[*begin]++;
		begin++;
	}
	begin = magazine.begin();
	while (begin != magazine.end())
	{
		ascll2[*begin]++;
		begin++;
	}
	begin = ransomNote.end();
	while (begin != ransomNote.end())
	{
		if (ascll1[*begin]>ascll2[*begin])
			return false;
		else
			begin++;
	}
	return true;
}

int lengthOfLastWord(string s) {
	int len = 0;
	auto begin = s.rbegin();
	while (begin != s.rend())
	{
		if (*begin == ' ')
			break;
		len++;
		begin++;
	}
	return len;
}

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
	int end = m + n - 1;
	int num1 = m - 1;
	int num2 = n - 1;
	if (m == 0)
	{
		nums1.swap(nums2);
		return;
	}
	while (end != num1 && num1 >= 0 && num2 >= 0)
	{
		if (nums1[num1] > nums2[num2])
		{
			nums1[end] = nums1[num1];
			num1--;
			end--;
		}
		else
		{
			nums1[end] = nums2[num2];
			num2--;
			end--;
		}
	}
	if (num2 >= 0)
	{
		while (end >= 0)
		{
			nums1[end] = nums2[num2];
			end--;
			num2--;
		}
	}
}

int main()
{
	string ran("a");
	string mag("ab");
	//canConstruct(ran, mag);
	//lengthOfLastWord(ran);
	vector<int> nums1;
	vector<int> nums2;
	nums1.resize(8);
	nums2.resize(4);
	int x = 0;
	int y = 0;
	nums1.resize(2);
	nums2.resize(1);
	for (auto &e : nums1)
	{
		cin >> e;
	}
	for (auto &e : nums2)
	{
		cin >> e;
	}
	merge(nums1, 1,nums2,1);
	return 0;
}