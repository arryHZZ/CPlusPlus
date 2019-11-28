#define _CRT_SECURE_NO_WARNINGS
#include<iostream>

using namespace std;
//时间类
class Time
{
public:
	Time(int hour = 0, int minute = 0)
		:_hour(hour),
		_minute(minute)
	{}

	~Time(){}
	//输入重载
	friend istream& operator>>(istream& _cin, Time& time);
	//输出重载
	friend ostream& operator<<(ostream& _cout, const Time time);
	//计算差值，返回分钟
	int operator-(const Time& time)
	{
		Time max = *this;
		Time min = time;
		int flag = 1;
		if (max < min)
		{
			Time tmp = min;
			min = max;
			max = tmp;
			flag = -1;
		}
		int hour = max._hour - min._hour;
		int minute = max._minute - min._minute;
		if (minute < 0)
		{
			--hour;
			minute += 60;
		}
		return (minute + hour * 60)*flag;
	}
	////计算和值，返回分钟
	//int operator+(const Time& time)
	//{
	//	int hour = this->_hour + time._hour;
	//	int minute = this->_minute + time._minute;
	//	return minute + 
	//}
	//逻辑运算重载
	bool operator>(const Time& time)
	{
		if (this->_hour > time._hour)
			return true;
		else
		{
			if (this->_hour == time._hour && this->_minute > time._minute)
				return true;
			else return false;
		}
	}
	
	bool operator==(const Time& time)
	{
		return this->_hour == time._hour &&
				this->_minute == time._minute;
	}

	bool operator!=(const Time& time)
	{
		return !(*this == time);
	}

	bool operator>=(const Time& time)
	{
		return *this > time || *this == time;
	}

	bool operator<(const Time& time)
	{
		return !(*this >= time);
	}

	bool operator<=(const Time& time)
	{
		return *this < time || *this == time;
	}
	
private:
	int _hour;
	int _minute;
};

istream& operator>>(istream& _cin, Time& time)
{
	cout << "请输入时间:";
	_cin >> time._hour;
	_cin >> time._minute;
	return _cin;
}

ostream& operator<<(ostream& _cout, const Time time)
{
	_cout << time._hour << ':' << time._minute;
	return _cout;
}

class Process
{
public:
	Process()
	{

	}
private:
	Time EnterTime;  // 进入时间
	Time ServiceTime; //服务时间
	Time BeginTime;  //开始时间
	Time FinishTime;  //完成时间
	size_t rTime;  //周转时间
	double PowerTime;  //带权周转时间
};

void testTime()
{
	Time t1(2,10);
	Time t2(1,50);
	//cout << (t1 > t2)<<endl;
	//cout << (t1 >= t2) << endl;
	//cout << (t1 < t2) << endl;
	//cout << (t1 <= t2) << endl;
	//cout << (t1 == t2) << endl;
	//cout << (t1 != t2) << endl;
	cin >> t1;
	cout << (t1 - t2)<<endl;
	cout << t1;
}

int main()
{
	testTime();
	return 0;
}