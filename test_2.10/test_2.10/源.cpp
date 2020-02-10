#define _CRT_SECURE_NO_WARNINGS
#include<unordered_map>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
	unordered_map<int, int> mp1;
	unordered_map<int, int> mp2;
	for (auto& e : nums1)
	{
		++mp1[e];
	}
	for (auto& e : nums2)
	{
		++mp2[e];
	}
	vector<int> ret;
	for (auto& mp : mp1)
	{
		auto it = mp2.find(mp.first);
		if (it != mp2.end())
		{
			for (int i = 0; i < min(it->second, mp.second); i++)
			{
				ret.push_back(mp.first);
			}
		}
	}
	return ret;
}

vector<string> uncommonFromSentences(string A, string B) {
	unordered_map<string, int> mp1;
	//unordered_map<string, int> mp2;
	auto Abegin = A.begin();
	while (Abegin != A.end())
	{
		string tmp;
		if (*Abegin == ' ')
			Abegin++;
		while (Abegin != A.end() && *Abegin != ' ')
		{
			tmp += *Abegin;
			Abegin++;
		}
		++mp1[tmp];
	}
	auto Bbegin = B.begin();
	while (Bbegin != B.end())
	{
		string tmp;
		if (*Bbegin == ' ')
			Bbegin++;
		while (Bbegin != B.end() && *Bbegin != ' ')
		{
			tmp += *Bbegin;
			Bbegin++;
		}
		++mp1[tmp];
	}
	vector<string> ret;
	for (auto& mp : mp1)
	{
		if (mp.second == 1)
		{
			ret.push_back(mp.first);
		}
	}
	return ret;
}

int main()
{
	string str1("this apple is sweet");
	string str2("this apple is sour");
	uncommonFromSentences(str1, str2);
	//vector<int> num1;
	//vector<int> num2;
	//num1.resize(5);
	//num2.resize(5);
	//for (int i = 0; i < 5; i++)
	//{
	//	num1[i] = i;
	//	num2[i] = i;
	//}
	//intersect(num1, num2);
	return 0;
}