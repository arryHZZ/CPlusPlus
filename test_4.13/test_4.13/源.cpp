#define _CRT_SECURE_NO_WARNINGS
// write your code here cpp
#include <iostream>
#include <vector>
#include <string>
using namespace std;


int arr[7] = { 7, 1, 2, 3, 4, 5, 6 };
int mouth[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

// 2000��һ��һ������6
void FindHoliday(int year)
{
	int idx = year - 2000;
	int idxday = idx * 365 + idx / 4 - idx / 100 + idx / 400;
	int folg = 0;
	if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
	{
		//������
		folg = 1;
	}
	if (folg == 0)
	{
		idxday++;
	}
	//�õ�ÿ���һ�������ڼ���ÿ���µ�һ�������ڼ�
	int FastDay = arr[(arr[idxday % 7] + 6) % 7];
	//cout << FastDay << endl;
	//Ԫ��w
	cout << year << "-01-01" << endl;
	//һ�µ���������һ
	//����2������
	int day = 1;
	day += 14;
	for (int i = 0; i < 7; i++)
	{
		if (arr[(arr[(day + i) % 7] + FastDay - 1) % 7] == 1)
		{
			cout << year << "-01-" ;
			if ((day + 1) < 10)
			{
				cout << "0";
			}
			cout << day + i << endl;
			//�����һ����һ�������ڼ�
			FastDay = arr[(arr[mouth[0] % 7] + FastDay) % 7];
			day = 1;
			break;
		}
	}
	//2�µ���������һ
	//����2������
	day += 14;
	for (int i = 0; i <= 7; i++)
	{
		if (arr[(arr[(day + i) % 7] + FastDay - 1) % 7] == 1)
		{
			cout << year << "-02-";
			if ((day + 1) < 10)
			{
				cout << "0";
			}
			cout << day + i << endl;
			//��������һ�����ڼ�
			FastDay = arr[(arr[(mouth[1] + mouth[2] + mouth[3] + mouth[4]) % 7] + FastDay) % 7];
			//FastDay = arr[(arr[(mouth[1] + mouth[2] + mouth[3] + mouth[4]) % 7] + FastDay) % 7];
			day = 1;
			break;
		}
	}
	//�жϽ����Ƿ�������
	if (folg == 1)
	{
		if (FastDay == 7)
			FastDay = 1;
		else
			FastDay++;
	}
	//�������һ������һ
	if (FastDay == 1)
	{
		cout << year << "-05-" << 25 << endl;
	}
	else
	{
		cout << year << "-05-" << (31 - FastDay + 2) << endl;
	}
	//6��
	//7��
	cout << year << "-07-04" << endl;
	//����
	//���µ�һ������һ
	//�������һ�����ڼ�
	//FastDay = arr[(day + mouth[5] + mouth[6] + mouth[7] + FastDay) % 7];
	FastDay = arr[(arr[(mouth[5] + mouth[6] + mouth[7]) % 7] + FastDay) % 7];
	for (int i = 0; i < 7; i++)
	{
		if (arr[(arr[(day + i) % 7] + FastDay - 1) % 7] == 1)
		{
			cout << year << "-09-";
			if ((day + 1) < 10)
			{
				cout << "0";
			}
			cout << day + i << endl;
			FastDay = arr[(arr[(mouth[8] + mouth[9]) % 7] + FastDay) % 7];
			day = 1;
			break;
		}
	}
	day += 21;
	for (int i = 0; i < 7; i++)
	{
		if (arr[(arr[(day + i) % 7] + FastDay - 1) % 7] == 4)
		{
			cout << year << "-11-";
			if ((day + 1) < 10)
			{
				cout << "0";
			}
			cout << day + i << endl;
			day = 1;
			break;
		}
	}
	cout << year << "-12-25" << endl <<endl;

}

int main()
{
	int year;
	while (cin >> year)
	{
		FindHoliday(year);
	}
	return 0;
}