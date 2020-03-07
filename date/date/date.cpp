#include<iostream>
using namespace std;

class Date
{
public:
	//输入输出重载
	friend ostream& operator<<(ostream& _cout, const Date& d)
	{
		_cout << d._year << "-" << d._month << "-" << d._day;
		return _cout;
	}

	friend ostream& operator>>(ostream& _cin, const Date& d);
	//构造
	Date(int year = 1900, int month = 1, int day = 1)
	{
		if (year <= 0 || month <= 0 || month > 12 || day <= 0 || day > GetMounthDay(year, month))
		{
			this->_year = 1;
			this->_month = 1;
			this->_day = 1;
			cout << "日期非法" << endl;
		}
		else
		{
			this->_year = year;
			this->_month = month;
			this->_day = day;
		}
	}

	Date(const Date& d)
	{
		this->_year = d._year;
		this->_month = d._month;
		this->_day = d._day;
	}

	Date& operator=(const Date& d)
	{
		this->_year = d._year;
		this->_month = d._month;
		this->_day = d._day;
		return *this;
	}

	int GetMounthDay(int year, int month)
	{
		int Month[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
		if ((((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0))
			&& (month == 2))
			return Month[month - 1] + 1;
		else
			return Month[month - 1];

	}

	Date operator+=(int days)
	{
		if (days < 0)
			return *this -= (-days);
		this->_day += days;
		while (this->_day > GetMounthDay(this->_year, this->_month))
		{
			this->_day -= GetMounthDay(this->_year, this->_month);
			++this->_month;
			if (this->_month == 13)
			{
				this->_month = 1;
				++this->_year;
			}
		}
		return *this;
	}

	Date operator-=(int days)
	{
		if (days < 0)
			return *this += (-days);
		this->_day -= days;
		while (this->_day <= 0)
		{
			--this->_month;
			if (this->_month == 0)
			{
				_month = 12;
				--this->_year;
			}
			this->_day += GetMounthDay(this->_year, this->_month);
		}
		return *this;
	}

	Date operator+(int days)
	{
		Date tmp(*this);
		if (days < 0)
			tmp -= (-days);
		else
			tmp += days;
		return tmp;

	}

	Date operator-(int days)
	{
		Date tmp(*this);
		if (days < 0)
			tmp += (-days);
		else
			tmp -= days;
		return tmp;
	}

	int operator-(const Date& d)
	{
		int count = 0;
		int flag;
		Date max, min;
		if (*this < d)
		{
			min = *this;
			max = d;
			flag = -1;
		}
		else
		{
			min = d;
			max = *this;
			flag = 1;
		}
		while (min!=max)
		{
			min++;
			count++;
		}
		return count*flag;
	}

	Date& operator++()
	{
		return *this += 1;
	}

	Date operator++(int)
	{
		Date tmp(*this);
		*this += 1;
		return tmp;
	}

	Date& operator--()
	{
		return *this -= 1;
	}

	Date operator--(int)
	{
		Date tmp(*this);
		*this -= 1;
		return tmp;
	}

	bool operator>(const Date& d)const
	{
		if (this->_year > d._year)
			return true;
		else if (this->_month > d._month)
			return true;
		else if (this->_day > d._day)
			return true;
		return false;
	}

	bool operator>=(const Date& d)const
	{
		return *this > d || *this == d;
	}

	bool operator<(const Date& d)const
	{
		return !(*this >= d);
	}

	bool operator<=(const Date& d)const
	{
		return !(*this>d);
	}

	bool operator==(const Date& d)const
	{
		if (this->_year == d._year && this->_month == d._month && this->_day == d._day)
			return true;
		else
			return false;
	}

	bool operator!=(const Date& d)const
	{
		return !(*this == d);
	}
private:
	int _year;
	int _month;
	int _day;
};

int main()
{
	Date d(2019, 10, 1);
	Date c(2019, 11, 1);
	int a = d - c;
	cout << a << endl;
	/*c = d + (-30);
	cout << d << endl;
	cout << c << endl;
	cout << (c > d) << endl;
	cout << (c >= d) << endl;
	cout << (c < d) << endl;
	cout << (c <= d) << endl;
	cout << (c == d) << endl;
	cout << (c != d) << endl;*/
	return 0;
}