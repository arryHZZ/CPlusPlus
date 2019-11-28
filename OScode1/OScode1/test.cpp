#define _CRT_SECURE_NO_WARNINGS
#include<iostream>

using namespace std;
//ʱ����
class Time
{
public:
	Time(int hour = 0, int minute = 0)
		:_hour(hour),
		_minute(minute)
	{}

	~Time(){}
	//��������
	friend istream& operator>>(istream& _cin, Time& time);
	//�������
	friend ostream& operator<<(ostream& _cout, const Time time);
	//�����ֵ�����ط���
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
	////�����ֵ�����ط���
	//int operator+(const Time& time)
	//{
	//	int hour = this->_hour + time._hour;
	//	int minute = this->_minute + time._minute;
	//	return minute + 
	//}
	//�߼���������
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
	cout << "������ʱ��:";
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
	Time EnterTime;  // ����ʱ��
	Time ServiceTime; //����ʱ��
	Time BeginTime;  //��ʼʱ��
	Time FinishTime;  //���ʱ��
	size_t rTime;  //��תʱ��
	double PowerTime;  //��Ȩ��תʱ��
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