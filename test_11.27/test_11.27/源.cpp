#define _CRT_SECURE_NO_WARNINGS
//#include<iostream>
//#include<string>
//
//using namespace std;
//
//int NumDreak(int n)
//{
//	int num = n;
//	int dreak = 0;
//	int newB = 0;
//	while (num >= 3)
//	{
//		newB = num / 3;
//		dreak += newB;
//		num = num - newB * 2;
//	}
//	if (num == 2)
//		dreak++;
//	return dreak;
//}
//
//int main()
//{
//
//	int botter = 0;
//	while (cin >> botter)
//	{
//		int ret = NumDreak(botter);
//		cout << ret << endl;
//	}
//	return 0;
//
//}


#include<iostream>
#include<string>

using namespace std;

int main()
{
	string str1;  // ¶Ì
	string str2;   //³¤

	while (cin >> str1 >> str2)
	{
		if (str1.size() > str2.size())
		{
			string tmp = str1;
			str1 = str2;
			str2 = tmp;
		}
		string max = str1;
		char* p = new char[str1.size()];
		//p.clear();
		max.clear();
		int i = 0;
		int j = 0;
		memset(p, 0, str1.size());
		for (i = 0; i < str1.size(); i++)
		{
			for (j = 0; j < str1.size(); j++)
			{
				int tmp = str1.copy(p, str1.size() - j, i);
				p[tmp] = '\0';
				if (strstr(str2.c_str(),p) != NULL)
				{
					if (strlen(p) > max.size())
					{
						strcpy(max, p);
					}
				}
			}
		}
		cout << q << endl;
	}
	return 0;
}