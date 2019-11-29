#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<vector>
#include<iomanip>

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

	//赋值运算符重载
	Time& operator=(Time& time)
	{
		Time tmp(time);
		swap(time, *this);
		return *this;
	}

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
	cout << "时间:";
	_cin >> time._hour;
	_cin >> time._minute;
	return _cin;
}

ostream& operator<<(ostream& _cout, const Time time)
{
	cout << setiosflags(ios::right);
	_cout << setw(2) << time._hour << ':' << setw(2) << time._minute;
	return _cout;
}

class Process
{
public:
	Process()
	{}
	Process(Time entertime, size_t servicetime, Time begintime, Time finishtime,
		size_t rtime = 0, double powertime = 0, int name = 0)
		:_EnterTime(entertime),
		_ServiceTime(servicetime),
		_BeginTime(begintime),
		_FinishTime(finishtime),
		_rTime(rtime)
	{
		_PowerTime = powertime;
		_rTime = rtime;
		_name = name;
	}
	~Process()
	{}
	//输入重载
	friend istream& operator>>(istream& _cin, Process& process);
	//输出重载
	friend ostream& operator<<(ostream& _cout, const Process process);
	static Time _LineTime;  //时间线
	static size_t _TimePiece; //时间片
	int _name; //进程编号
	Time _EnterTime;  // 进入时间
	size_t _ServiceTime; //服务时间
	Time _BeginTime;  //开始时间
	Time _FinishTime;  //完成时间
	size_t _rTime;  //周转时间
	double _PowerTime;  //带权周转时间

};

size_t Process::_TimePiece = 0;
Time Process::_LineTime;

istream& operator>>(istream& _cin, Process& process)
{
	cout << "进程编号:";
	_cin >> process._name;
	cout << "进入";
	_cin >> process._EnterTime;
	cout << "服务时间:";
	_cin >> process._ServiceTime;
	return _cin;
}


ostream& operator<<(ostream& _cout, const Process process)
{
	cout << setiosflags(ios::right);
	_cout <<"   "<< process._name << "       " << process._EnterTime << "     " << process._BeginTime << "       " <<
		process._ServiceTime << "       " << process._FinishTime << "    " <<setw(8)<< process._rTime << "  "<<setw(12) << process._PowerTime;
	return _cout ;
}

//void testTime()
//{
//	Time t1(2,10);
//	Time t2(1,50);
//	//cout << (t1 > t2)<<endl;
//	//cout << (t1 >= t2) << endl;
//	//cout << (t1 < t2) << endl;
//	//cout << (t1 <= t2) << endl;
//	//cout << (t1 == t2) << endl;
//	//cout << (t1 != t2) << endl;
//	cin >> t1;
//	cout << (t1 - t2)<<endl;
//	cout << t1;
//}



//void testProcess()
//{
//	Process p;
//	cout << "时间片";
//	cin >> Process::_TimePiece;
//	cout << "线";
//	cin >> Process::_LineTime;
//	cin >> p;
//	cin >> p._rTime;
//	cin >> p._PowerTime;
//	cout << p;
//}

void InPut(vector<Process>& process)
{
	cout << "添加几条进程:";
	int n;
	cin >> n;
	process.resize(n);
	for (auto& e : process)
	{
		cin >> e;
	}
}

void OutPut(const vector<Process>& process)
{
	cout << "进程编号  " << "进入时间  " << "开始时间  " 
		<< "服务时间  " << "完成时间  " << "周转时间  " << "带权周转时间" << endl;
	for (auto e : process)
	{
		cout << e << endl;
	}
}

int compare(const void * a, const void * b)
{
	Process* p = (Process*)a;
	Process* q = (Process*)b;
	if (p->_EnterTime < q->_EnterTime)
		return -1;
	if (p->_EnterTime > q->_EnterTime)
		return 1;
	if (p->_EnterTime == q->_EnterTime)
		return 0;
}

void FCFS(vector<Process>& process)
{
	qsort(&process, process.size(), sizeof(Process), compare);
}

void menu()
{
	vector<Process> process;
	int input = 0;
	do
	{
		cout << "1.输入进程信息" << endl;
		cout << "2.先来先服务" << endl;
		cout << "3.短进程优先" << endl;
		cout << "4.高优先级优先" << endl;
		cout << "5.时间片轮转" << endl;
		cout << "6.打印进程信息" << endl;
		cout << "请输出你的选择>>";
		cin >> input;
		switch (input)
		{
		case 1: InPut(process);
			break;
		case 2:FCFS(process);
			break;
		case 3:
			break;
		case 4:
			break;
		case 5:
			break;
		case 6: OutPut(process);
			break;
		default:
			break;
		}
	} while (input);
}

int main()
{
	menu();
	//Process p1, p2;
	//cin >> p1 >> p2;
	//compare(&p1, &p2);
	return 0;
}