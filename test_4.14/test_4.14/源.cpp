#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

bool IsPrime(int n)
{
	if (n == 1)
		return false;
	for (int i = 2; i < n; i++)
	{
		if (n % i == 0)
			return false;
	}
	return true;
}


int month[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

int LastDay(int y,int m)
{
	if ((y % 4 == 0 && y % 100 != 0) || (y % 400 == 0) && (m == 2))
	{
		return month[m] + 1;
	}
	else
	{
		return month[m];
	}
}

bool IsTure(int yearF, int monthF, int yearT, int monthT)
{
	if (yearF == yearT && monthF <= monthT)
		return true;
	else if (yearF < yearT)
		return true;
	else
		return false;
}

int Mmoney(int yearF, int monthF, int dayF, int yearT, int monthT, int dayT)
{
	int money = 0;
	int idx = yearT - yearF;
	if (dayF != 1)
	{
		if (!IsPrime(monthF))
		{

			money += (month[monthF] - dayF + 1) * 2;
			if (monthF == 2 && ((yearF % 4 == 0 && yearF % 100 != 0) || (yearF % 400 == 0)))
			{
				money += 2;
			}
		}
		else
		{
			money += month[monthF] - dayF + 1;
		}
		monthF++;
		dayF = 1;
		if (monthF == 13)
		{
			yearF++;
			monthF == 1;
		}

	}
	if (dayT != LastDay(yearT, monthT))
	{
		if (!IsPrime(monthT))
		{
			money += dayT * 2;
		}
		else
		{
			money += dayT;
		}
		monthT--;
		if (monthT == 0)
		{
			monthT = 12;
			yearT--;
		}
		dayT = LastDay(yearT, monthT);
	}

	while (IsTure(yearF, monthF, yearT, monthT))
	{
		if (!IsPrime(monthF))
		{
			money += month[monthF] * 2;
			if (monthF == 2 && ((yearF % 4 == 0 && yearF % 100 != 0) || (yearF % 400 == 0)))
			{
				money += 2;
			}
		}
		else
		{
			money += month[monthF];
			if (monthF == 2 && ((yearF % 4 == 0 && yearF % 100 != 0) || (yearF % 400 == 0)))
			{
				money++;
			}
		}
		monthF++;
		if (monthF == 13)
		{
			yearF++;
			monthF = 1;
		}
	}
	return money;
}


int main()
{
	int yearF, monthF, dayF, yearT, monthT, dayT;
	//2000 1 1 2000 1 31
	while (cin >> yearF >> monthF >> dayF >> yearT >> monthT >> dayT)
	{
		if (yearF == yearT && monthF == monthT)
		{
				if (dayF == dayT)
				{
					if (!IsPrime(monthF))
						cout << 2 << endl;
					else
						cout << 1 << endl;
				}
				else
				{
					if (!IsPrime(monthF))
						cout << 2*(dayT - dayF + 1) << endl;
					else
						cout << dayT - dayF + 1 << endl;
				}
		}
		else
		{
			int money = Mmoney(yearF, monthF, dayF, yearT, monthT, dayT);

			cout << money << endl;
		}

	}
		return 0;
}