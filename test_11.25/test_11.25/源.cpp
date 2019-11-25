//#include<iostream>
//#include<vector>
//
//using namespace std;
//
//int main()
//{
//	int n = 0;
//	int i, j;
//	while (cin >> n)
//	{
//		vector<vector<int>> arr;
//		arr.resize(2*n - 1);
//		for (auto& e : arr)
//		{
//			e.resize(2*n - 1, 0);
//		}
//		for (i = 0; i < n; i++)
//		{
//			arr[i][0] = 1;
//			arr[i][2 * i] = 1;
//			for (j = 1; j < 2 * i; j++)
//			{
//				if ((i - 1)>=0 && (j - 1)>=0)
//					arr[i][j] += arr[i - 1][j - 1];
//				if ((i - 1)>=0 && (j>=0))
//					arr[i][j] += arr[i - 1][j];
//				if ((i - 1)>=0 && (j - 2)>=0)
//					arr[i][j] += arr[i - 1][j - 2];
//			}
//		}
//		for (i = 0; i < 2 * n; i++)
//		{
//			if (arr[n - 1][i] % 2 == 0)
//			{
//				cout << (i + 1) << endl;
//				break;
//			}
//		}
//		if (i == 2 * n)
//			cout << -1 << endl;
//	}
//	return 0;
//}


//#include<iostream>
//#include<string>
//
//using namespace std;
//
//int main()
//{
//	string str1;
//	string str2;
//	getline(cin, str1);
//	getline(cin, str2);
//	auto begin1 = str1.begin();
//	auto begin2 = str2.begin();
//	while (begin1 != str1.end() && begin2 != str2.end())
//	{
//		//如果字符不相同
//		if (*begin1 != *begin2)
//		{
//			//通配符为？
//			if (*begin1 == '?')
//			{
//				begin1++;
//				begin2++;
//			}
//			//如果通配符为*
//			else if (*begin1 == '*')
//			{
//				while (begin1 != str1.end() && begin2 != str2.end()
//					&& *begin1 != *begin2)
//				{
//					//是否在合理字符之内
//					if ((*begin2 >= 'a'&&*begin2 <= 'z') ||
//						(*begin2 >= 'A'&&*begin2 <= 'Z') ||
//						(*begin2 >= '0'&&*begin2 <= '9'))
//						begin2++;
//					//是否是最后一个*
//					else if (begin1+1 == str1.end())
//					{
//						cout << "false" << endl;  //如果是则不匹配
//						break;
//					}
//					//不是最后一个*
//					else
//						break;
//				}
//				begin1++;
//			}
//			else
//			{
//				cout << "false" << endl;
//				break;
//			}
//		}
//		else
//		{
//			begin1++;
//			begin2++;
//		}
//	}
//	if (begin1 != str1.end())
//	{
//		while (begin1 != str1.end())
//		{
//			if (*begin1 == '*' || *begin1 == '?')
//				begin1++;
//			else
//				break;
//		}
//	}
//	if (begin2 == str2.end() && begin1 == str1.end())
//		cout << "true" << endl;
//	else
//		cout << "false" << endl;
//	return 0;
//}

#include<iostream>
#include<string>

using namespace std;

int find(string& str1, string& str2)
{
	auto begin1 = str1.begin();
	auto begin2 = str2.begin();
	while (begin1 != str1.end() && begin2 != str2.end())
	{
		//如果字符不相同
		if (*begin1 != *begin2)
		{
			//通配符为？
			if (*begin1 == '?')
			{
				begin1++;
				begin2++;
			}
			//如果通配符为*
			else if (*begin1 == '*')
			{
				while (begin1 != str1.end() && begin2 != str2.end()
					&& *begin1 != *begin2)
				{
					//是否在合理字符之内
					if ((*begin2 >= 'a'&&*begin2 <= 'z') ||
						(*begin2 >= 'A'&&*begin2 <= 'Z') ||
						(*begin2 >= '0'&&*begin2 <= '9'))
						begin2++;
					//是否是最后一个*
					else if (begin1 + 1 == str1.end())
					{
						return 0;  //如果是则不匹配
						break;
					}
					//不是最后一个*
					else
						break;
				}
				begin1++;
			}
			else
			{
				return 0;
				break;
			}
		}
		else
		{
			begin1++;
			begin2++;
		}
	}
	if (begin1 != str1.end())
	{
		while (begin1 != str1.end())
		{
			if (*begin1 == '*' || *begin1 == '?')
				begin1++;
			else
				break;
		}
	}
	auto rbegin2 = str2.rbegin();
	auto rbegin1 = str1.rbegin();

	if (begin2 == str2.end() && begin1 == str1.end())
		return 1;
	else
		return 0;
}

int main()
{
	string str1;
	string str2;
	while (cin >> str1 >> str2)
	{
		int ret = find(str1, str2);
		if (ret == 1)
			cout << "true" << endl;
		else
			cout << "false" << endl;
	}
	return 0;
}