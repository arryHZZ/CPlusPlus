//#define _CRT_SECURE_NO_WARNINGS
//#include<iostream>
//
//using namespace std;
//
//int main()
//{
//	int a;
//	cin >> a;
//	int max = 0;
//	int count = 0;
//	int i = 0;
//	for (i; i < 8; i++)
//	{
//		if (((a >> i) & 1) == 0)
//			count = 0;
//		if (((a >> i) & 1) == 1)
//			count++;
//		if (count > max)
//			max = count;
//	}
//	cout << max;
//	return 0;
//}



#include<iostream>
#include<math.h>

using namespace std;

int is_prime(int n)
{
	int i = 0;
	if (n <= 2)
		return 0;
	for (i = 2; i <= sqrt(n); i++)
	{
		if (n%i == 0)
			return 0;
	}
	return 1;
}

int main()
{
	int a;
	cin >> a;
	int del = 0;
	int num1, num2;
	num1 = num2 = a / 2;
	while (1)
	{
		if (is_prime(num1) && is_prime(num2))
		{
			cout << num1 << endl;
			cout << num2 << endl;
			break;
		}
		num1--;
		num2++;
	}
	return 0;
}