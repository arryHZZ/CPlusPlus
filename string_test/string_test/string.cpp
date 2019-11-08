#define _CRT_SECURE_NO_WARNINGS
#include<string>
#include<iostream>
using namespace std;

int main()
{
	string s;
	string NewString;

	getline(cin, s);
	int first = 1;

	auto begin = s.begin();
	auto begin1 = s.begin();

	while (begin != s.end())
	{
		if (*begin>'0'&&*begin<'9'&&first)
		{
			begin1 = begin;
			auto per = begin;
			while (begin != s.end())
			{
				
				if (begin != s.end() && *begin>='0'&&*begin<='9' && ((*begin - *per) == 1 || *begin == *per))
				{
					per = begin;
					begin++;
				}
				else
					break;
			}
			if ((begin - begin1)>NewString.size())
			{
				NewString = s.substr(begin1-s.begin(), begin-begin1);
			}
			if (begin == s.end())
				break;
			else
			{
				continue;
			}
		}
		++begin;
	}
	cout << NewString;
	return 0;
}