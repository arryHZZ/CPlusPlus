#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>

using namespace std;

int main()
{
	string str;
	(getline(cin, str));
		int folg = 1;
	int count = 0;
	auto begin = str.begin();
	while (begin != str.end())
	{
		if (folg == 1 && *begin == ' ')
		{
			count++;
		}
		else if (*begin == '"')
		{
			folg *= -1;
		}
		begin++;
	}
	folg = 1;
	cout << count << endl;
	begin = str.begin();
	while (begin != str.end())
	{
		if (folg == 1 && *begin == ' ')
		{
			cout << endl;

		}
		else if (*begin == '"')
		{
			folg *= -1;
		}
		else
		{
			cout << *begin;
		}
		begin++;
	}
	return 0;
}