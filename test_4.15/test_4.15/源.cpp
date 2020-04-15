//#define _CRT_SECURE_NO_WARNINGS
//#include <iostream>
//#include <vector>
//
//using namespace std;
//
//
//void FBnum(vector<unsigned long>& FB)
//{
//	FB.resize(80);
//	FB[0] = 1;
//	FB[1] = 1;
//	for (int i = 2; i < 80; i++)
//	{
//		FB[i] = FB[i - 1] + FB[i - 2];
//	}
//}
//
//unsigned long add(vector<unsigned long> FB, int from, int to)
//{
//	unsigned long sum = 0;
//	for (int i = from - 1; i < to; i++)
//	{
//		sum += FB[i];
//	}
//	return sum;
//}
//
//
//int main()
//{
//	vector<unsigned long> FB;
//	FBnum(FB);
//	int from, to;
//	while (cin >> from >> to)
//	{
//		cout << add(FB, from, to) << endl;
//	}
//	return 0;
//}
#include <iostream>
#include <string>

using namespace std;

int find(string s, string t)
{
	auto sbegin = s.begin();
	auto tbegin = t.begin();
	int count = 0;
	while (sbegin != s.end())
	{
		if (*sbegin == *tbegin)
		{
			auto tmpbegin = sbegin;
			while (tmpbegin != s.end() && tbegin != t.end())
			{
				if (*tmpbegin != *tbegin)
					break;
				tmpbegin++;
				tbegin++;
			}
			if (tbegin == t.end())
			{
				count++;
				tbegin = t.begin();
				sbegin = tmpbegin;
			}
			else
			{
				sbegin++;
				tbegin = t.begin();
			}
		}
		else
		{
			sbegin++;
		}
	}
	return count;
}

int main()
{
	string s;
	string t;
	while (cin >> s >> t)
	{
		cout << find(s, t) << endl;
	}
	return 0;
}