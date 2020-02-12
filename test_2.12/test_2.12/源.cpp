#define _CRT_SECURE_NO_WARNINGS
#include<string>
#include<iostream>
#include<vector>
using namespace std;

string test(unsigned int n)
{
	string num = "0123456789abcedf";
	string strNum;
	string tmp = "00";
	for (int i = 0; i < 8; i++)
	{
		tmp[1] = num[(n >> (i++ * 4)) & 0x0f];
		tmp[0] = num[(n >> (i * 4)) & 0x0f];
		strNum += tmp;
	}
	return strNum;
}

string& test(string& str1, string& str2)
{
	auto begin1 = str1.begin();
	int ascll[256] = { 0 };
	for (auto e : str2)
	{
		ascll[e] = 1;
	}
	while (begin1 != str1.end())
	{
		if (ascll[*begin1] == 1)
			begin1 = str1.erase(begin1);
		else
			++begin1;
	}
	return str1;
}

int add(vector<int>& arr)
{
	int max = arr[0];
	int add = 0;
	for (auto e : arr)
	{
		add += e;
		if (add > max)
			max = add;
		if (max < e)
		{
			max = e;
			add = e;
		}
		//add += e;

	}
	return max;
}

bool isTrue(double a, double b, double c, double d)
{
	int x;
	if ((a + b)*(c + b) == 24 ||
		(a + b)*(c - b) == 24 ||
		(a - b)*(c - b) == 24 ||
		(a*b - c) / d == 24 ||
		(a*b + c) / d == 24 ||
		(a*b*c) / d == 24 ||
		(a*b) / (c*d) == 24 ||
		(a*b) / (c - d) == 24 ||
		(a*b) / (c + d) == 24 ||
		a + b + c + d == 24 ||
		a + b + c - d == 24 ||
		a*b + c + d == 24 ||
		a*b - c - d == 24 ||
		a*b + c - d == 24 ||
		a*b*c - d == 24 ||
		a*b*c + d == 24 ||
		(a*b -c)*d == 24 ||
		(a*b+c)*d == 24)
		return true;
	else
		return false;
}



int main()
{
	double a, b, c, d;
	int folg = 0;
	while (cin >> a >> b >> c >> d)
	{
		folg = 0;
		double arr[4] = { 0 };
		arr[0] = a;
		arr[1] = b;
		arr[2] = c;
		arr[3] = d;
		for (int m = 0; m < 4; m++)
		{
			for (int n = 0; n < 4; n++)
			{
				for (int p = 0; p < 4; p++)
				{
					for (int q = 0; q < 4; q++)
					{
						if (m != n&&m != p&&m != q&& n != p &&n != q&&p != q)
						{
							if (isTrue(arr[m], arr[n], arr[p], arr[q]) == true)
							{
								cout << "true" << endl;
								folg = 1;
								break;
							}
						}
					}
					if (folg == 1)
						break;
				}
				if (folg == 1)
					break;
			}v
			if (folg == 1)
				break;
		}
		if (folg != 1)
			cout << "false" << endl;
	}
	return 0;
}


//int main()
//{
//	//string str1;
//	//string str2;
//	//while (true)
//	//{
//	//	getline(cin, str1);
//	//	getline(cin, str2);
//	//	cout << test(str1, str2) << endl;
//	//}
//	//cout << test(str1, str2) << endl;
//	//int n;
//	//cin >> n;
//	//vector<int> arr;
//	//arr.resize(n);
//	//for (auto& e : arr)
//	//{
//	//	cin >> e;
//	//}
//	//cout << add(arr) << endl;
//	int arr[4] = { 7, 2, 1, 10 };
//	for (int m = 0; m < 4; m++)
//	{
//		for (int n = 0; n < 4; n++)
//		{
//			for (int p = 0; p < 4; p++)
//			{
//				for (int q = 0; q < 4; q++)
//				{
//					if (m != n&&m != p&&m != q&& n != p &&n != q&&p != q)
//					{
//						cout << isTrue(arr[m], arr[n], arr[p], arr[q]) << endl;
//						return 0;
//					}
//				}
//			}
//		}
//	}
//	return 0;
//}