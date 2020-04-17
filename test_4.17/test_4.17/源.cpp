#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include <vector>
#include <iostream>

using namespace std;

//int main()
//{
//	int n;
//	vector<string> name;
//	while (cin >> n)
//	{
//		name.resize(n);
//		getchar();
//		for (auto& e : name)
//		{
//			getline(cin, e);
//		}
//		int tmp = 0;
//		auto begin = name.begin();
//		while (begin != name.end())
//		{
//			tmp = 0;
//			for (auto str : *begin)
//			{
//				if (str == ',' || str == ' ')
//				{
//					cout << "\"" << *begin << "\"";
//					tmp = 1;
//					break;
//
//				}
//			}
//			if (tmp == 0)
//			{
//				cout << *begin;
//			}
//			begin++;
//			if (begin != name.end())
//			{
//				cout << ", ";
//			}
//			else
//			{
//				cout << endl;
//			}
//		}
//	}
//	return 0;
//}

//int main()
//{
//	int n;
//	while (cin >> n)
//	{
//		unsigned long long rabit = 1;
//		unsigned long long young = 0;
//		unsigned long long grow = 0;
//		for (int i = 1; i < n; i++)
//		{
//			rabit += grow;
//			int tmp = young;
//			young = rabit;
//			grow = tmp;
//		}
//		cout << rabit + young + grow << endl;
//	}
//	return 0;
//}

int main()
{
	long n;
	while (cin>>n)
	{
		unsigned long num1 = 0;
		unsigned long num2 = 1;
		unsigned long ra = 0;
		for (int i = 0; i < n; i++)
		{
			ra = num1 + num2;
			num1 = num2;
			num2 = ra;
		}
		cout << ra << endl;
	}
}