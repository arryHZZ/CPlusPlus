#define _CRT_SECURE_NO_WARNINGS
#include<iostream>

using namespace std;

//int main()
//{
//	int a;
//	cin >> a;
//	a = a / 10;
//	switch (a)
//	{
//	case 10:
//	case 9:cout << "A"; break;
//	case 8:cout << "B"; break;
//	case 7:cout << "C"; break;
//	case 6:cout << "D"; break;
//	default:
//		cout << "E";
//		break;
//	}
//	return 0;
//}



//int main()
//{
//	int arr[3][3] = { 0 };
//	for (int i = 0; i < 3; i++)
//	{
//		for (int j = 0; j < 3; j++)
//		{
//			cin >> arr[i][j];
//		}
//	}
//	for (int i = 0; i < 3; i++)
//	{
//		for (int j = 0; j <= i; j++)
//		{
//			int tmp = arr[i][j];
//			arr[i][j] = arr[j][i];
//			arr[j][i] = tmp;
//		}
//	}
//	for (int i = 0; i < 3; i++)
//	{
//		for (int j = 0; j < 3; j++)
//		{
//			cout << arr[i][j] << " ";
//		}
//		cout << endl;
//	}
//	return 0;
//}


//#include<string>
//
//int main()
//{
//	string str;
//	getline(cin, str);
//	int count = 0;
//	auto begin = str.begin();
//	while (begin!=str.end())
//	{
//		if (*begin == '*')
//		{
//			count++;
//			str.erase(begin);
//		}
//		else if (*begin == ' ')
//		{
//			str.erase(begin);
//		}
//		else
//			begin++;
//	}
//	str.insert(str.begin(), count, '*');
//	cout << str;
//	return 0;
//}


#include<string>
int main()
{
	int n;
	cin >> n;
	int *arr = new int[n];
	int i = 0;
	int num = n;
	int p = 0;
	memset(arr,0,sizeof(int)*n);
	while (num)
	{
		if (arr[i] == 0)
		{
			p++;
		}
		if (p == 3)
		{
			arr[i] = 1;
			p = 0;
			num--;
		}
		i++;
		i = i % n;
	}
	cout << i;
	delete[] arr;
	return 0;
}