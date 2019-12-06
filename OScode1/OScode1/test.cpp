#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<vector>
#include<iomanip>
#include<queue>

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

	Time& operator+(const int n)
	{
		int min = n + this->_minute;
		this->_hour += min / 60;
		this->_minute = min % 60;
		return *this;
	}

	Time& operator+=(const int n)
	{
		*this = *this + n;
		return *this;
	}

	//赋值运算符重载
	Time& operator=(Time& time)
	{
		this->_hour = time._hour;
		this->_minute = time._minute;
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

//进程类
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
	//引用重载
	Process& operator&()
	{
		return *this;
	}
	//赋值重载
	Process& operator=(Process& a)
	{
		this->_BeginTime = a._BeginTime;
		this->_EnterTime = a._EnterTime;
		this->_FinishTime = a._FinishTime;
		this->_name = a._name;
		this->_PowerTime = a._PowerTime;
		this->_rTime = a._rTime;
		this->_ServiceTime = a._ServiceTime;
		this->_RemainSeviceTime = a._RemainSeviceTime;
		this->_First = a._First;
		return *this;
	}
	static Time _LineTime;  //时间线
	int _name; //进程编号
	Time _EnterTime;  // 进入时间
	size_t _ServiceTime; //服务时间
	Time _BeginTime;  //开始时间
	Time _FinishTime;  //完成时间
	size_t _rTime;  //周转时间
	double _PowerTime;  //带权周转时间
	double _First;  //优先级
	int _RemainSeviceTime;  //剩余时间

};

Time Process::_LineTime;

istream& operator>>(istream& _cin, Process& process)
{
	cout << "进程编号:";
	_cin >> process._name;
	cout << "进入";
	_cin >> process._EnterTime;
	cout << "服务时间:";
	_cin >> process._ServiceTime;
	process._RemainSeviceTime = process._ServiceTime;
	return _cin;
}

ostream& operator<<(ostream& _cout, const Process process)
{
	cout << setiosflags(ios::right);
	_cout << "   " << process._name << "       " << process._EnterTime << "     " << process._BeginTime << "       " <<
		process._ServiceTime << "       " << process._FinishTime;
	cout << setiosflags(ios::right);
	_cout<< setw(8) << process._rTime << "" << setw(12) << process._PowerTime;
	return _cout ;
}

//输入
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

//输出
void OutPut(const vector<Process>& process)
{
	cout << "进程编号  " << "进入时间  " << "开始时间  " 
		<< "服务时间  " << "完成时间  " << "周转时间  " << "带权周转时间" << endl;
	for (auto e : process)
	{
		cout << e << endl;
	}
}

//交换
void Swap(Process& a, Process& b)
{
	Process tmp = a;
	a = b;
	b = tmp;
}

//按照进入时间进行排序
void EnterTimeSort(vector<Process>& process)
{
	if (process.size() == 0)
		return;
	for (int i = 0; i < process.size() - 1; i++)
	{
		for (int j = 0; j < process.size() - i - 1; j++)
		{
			if (process[j]._EnterTime > process[j + 1]._EnterTime)
				Swap(process[j], process[j + 1]);
		}
	}
}

//依次执行进程
void RunProcess(vector<Process>& process)
{
	if (process.size() == 0)
		return;
	for (int i = 0; i < process.size(); i++)
	{
		//如果进程进入时间小于等于时间线的时间
		if (process[i]._LineTime <= process[i]._EnterTime)
		{
			//则该开始时间就应为该进程的进入时间
			process[i]._BeginTime = process[i]._EnterTime;
			process[i]._LineTime = process[i]._EnterTime;  //将时间线的时间调整至进程进入时间
			process[i]._LineTime += process[i]._ServiceTime;  //将时间线增加一个该进程的服务时间
			process[i]._FinishTime = process[i]._LineTime;  //将进程结束时间修改为当前时间线时间
		}
		else  //进程进入时间大于时间线时间，则证明该进程一直在等待状态
		{
			process[i]._BeginTime = process[i]._LineTime;  //将进程开始时间赋值为当前时间线时间
			process[i]._LineTime += process[i]._ServiceTime;  //将时间线增加一个该进程时间
			process[i]._FinishTime = process[i]._LineTime;  //将进程结束时间修改为当前时间线时间
		}
		process[i]._rTime = process[i]._FinishTime - process[i]._EnterTime;   //计算该进程的周转时间
		process[i]._PowerTime = process[i]._rTime / process[i]._ServiceTime;  //计算该进程的带权周转时间
	}
}

//单步执行进程
void TmpOfPrccess(Process& process, int n)
{
	//如果服务时间等于剩余服务时间，则证明该进程第一次被调度
	if (process._ServiceTime == process._RemainSeviceTime)
	{
		//设定开始时间
		process._BeginTime = process._LineTime;
	}
	//如果剩余服务时间大于等于一个时间片的时间
	if (process._RemainSeviceTime >= n)
	{
		//剩余时间减少一个时间片的时间
		process._RemainSeviceTime -= n;
		//时间线向后移动一个时间片
		process._LineTime += n;
	}
	else  //如果剩余时间小于一个时间时间片的时间
	{
		//时间线向后移动一个该进程的剩余时间
		process._LineTime += process._RemainSeviceTime;
		process._RemainSeviceTime = 0;  //将剩余时间置为0
	}
	if (process._RemainSeviceTime == 0)  //如果剩余时间为0，则证明该进程结束调度
	{
		process._FinishTime = process._LineTime;  // 设定结束时间，计算周转时间，带权周转时间
		process._rTime = process._FinishTime - process._EnterTime;
		process._PowerTime = (double)process._rTime / process._ServiceTime;
	}
}

//先来先服务
void FCFS(vector<Process> process)
{
	if (process.size() == 0)
		return;
	EnterTimeSort(process);  //按照进入时间排序
	process[0]._LineTime = process[0]._EnterTime;   //将最早进入内存的是进程时间设置为时间线的起点
	RunProcess(process);  //依次执行所有进程
	OutPut(process);
}

//按照运行时间排序
void ServiceTimeSort(vector<Process>& process)
{
	if (process.size() == 0)
		return;
	for (int i = 0; i < process.size() - 1; i++)
	{
		for (int j = 0; j < process.size() - i - 1; j++)
		{
			if (process[j]._ServiceTime > process[j + 1]._ServiceTime)
				Swap(process[j], process[j + 1]);
		}
	}
}

//短进程优先
void SJF(vector<Process> process)
{
	if (process.size() == 0)
		return;
	vector<Process> q;  //创建进程结束信息记录表
	EnterTimeSort(process);   //根据进入时间排序
	process[0]._LineTime = process[0]._EnterTime;   //设定时间线起始时间
	vector<Process> tmp;   //创建缓冲池
	while (!process.empty() || !tmp.empty())   //当缓冲池和进程信息表时间同时为空循环结束
	{
		auto begin = process.begin();   
		while (begin != process.end())   //判断当前时间线，有哪些进程已经到达
		{
			if (begin->_EnterTime <= begin->_LineTime)     //如果进程进入时间小于时间线时间，证明进程已经到达
			{
				tmp.push_back(*begin);                //存入缓冲队中
				begin = process.erase(process.begin());  //从进程信息表中删除入队信息
			}
			else
				begin++;
		}
		if (tmp.size() != 0)
		{ 
			ServiceTimeSort(tmp);    //将缓冲池中的进程信息根据进程服务时间排序
			auto Tbegin = tmp.begin();
			TmpOfPrccess(*Tbegin, Tbegin->_RemainSeviceTime);   //将服务时间最短的进行单步执行
			q.push_back(*Tbegin);   //将该进程信息存入结束信息记录表
			tmp.erase(tmp.begin());  //从缓冲池中删除该进程信息
		}
		//当缓冲池中没有进程时，但进程信息表不为空，切时间线时间不满足下一个进程到达，修改时间线时间
		if (tmp.size() == 0 && !process.empty() && process[0]._EnterTime > process[0]._LineTime)
		{
			process[0]._LineTime = process[0]._EnterTime;
		}
	}
	//打印结束表
	OutPut(q);
}

//计算响应比
void CalculateFirst(vector<Process>& process)
{
	if (process.size() == 0)
		return;
	for (auto&e : process)
	{
		e._First = (double)(e._LineTime - e._EnterTime) / e._ServiceTime + 1;
	}
}

//根据响应比排序
void FirstSort(vector<Process>& process)
{
	if (process.size() == 0)
		return;
	for (int i = 0; i < process.size() - 1; i++)
	{
		for (int j = 0; j < process.size() - i - 1; j++)
		{
			if (process[j]._First < process[j + 1]._First)
				Swap(process[j], process[j + 1]);
		}
	}
}

//高响应比优先
void HRRN(vector<Process> process)
{
	if (process.size() == 0)
		return;
	EnterTimeSort(process);
	vector<Process> q;   //结束信息表
	vector<Process> tmp;  //缓冲池
	process[0]._LineTime = process[0]._EnterTime;  //设置时间线起始时间
	while (!process.empty() || !tmp.empty())   //都不为空
	{
		auto begin = process.begin();
		while (begin != process.end())  //判断当前时间下有些进程到达
		{
			if (begin->_EnterTime <= begin->_LineTime)
			{ 
				tmp.push_back(*begin);   //进程到达放入缓冲池中
				begin = process.erase(process.begin());
			}
			else
				begin++;
		}
		//计算响应比
		CalculateFirst(tmp);
		//根据响应比排序
		FirstSort(tmp);
		if (tmp.size() != 0)
		{
			auto begin = tmp.begin();
			//单步执行进程
			TmpOfPrccess(*begin, begin->_ServiceTime);
			q.push_back(*begin);
			tmp.erase(tmp.begin());
		}
		//当调度池中没有进程时，且时间线的时间不足以使下一个进程进入到调度池中，修改时间线
		if (!process.empty() && tmp.size() == 0 && process[0]._LineTime < process[0]._EnterTime)
		{
			process[0]._LineTime = process[0]._EnterTime;
		}
	}
	OutPut(q);
}

//时间片轮转
void RR(vector<Process> process)
{
	if (process.size() == 0)
		return;
	vector<Process> Print;
	queue<Process> Queue;  //缓冲队
	EnterTimeSort(process);
	int q = 0;  //时间片长度，以分钟为单位
	cout << "请输入时间片的长度:";
	cin >> q;
	process[0]._LineTime = process[0]._EnterTime;
	process[0]._BeginTime = process[0]._LineTime;
	Queue.push(process[0]);
	process.erase(process.begin());
	while (Queue.size() != 0)
	{
		//将队头的进程执行一个时间片
		cout<<Queue.front()._name;
		TmpOfPrccess(Queue.front(), q);
		//查看进程信息中有哪些进程到达,如果到达则存入队中等待执行
		if (process.size() != 0)
		{
			auto begin = process.begin();
			while (begin != process.end())
			{
				if (begin->_EnterTime <= begin->_LineTime)
				{
					Queue.push(*begin);
					begin = process.erase(process.begin());
				}
				else
				{
					begin++;
				}
			}
		}
		//判断对头元素是否已经执行结束
		Process tmp = Queue.front();
		Queue.pop();  //出队

		if (tmp._RemainSeviceTime != 0)
		{
			Queue.push(tmp);
		}
		else
		{
			Print.push_back(tmp);  //保存到信息表中

		}
		//当调度池中没有进程时，且时间线的时间不足以使下一个进程进入到调度池中，修改时间线
		if (process.size() != 0 && Queue.size() == 0 && process[0]._LineTime <= process[0]._EnterTime)
		{
			process[0]._LineTime = process[0]._EnterTime;
		}
	}
	cout << endl;
	OutPut(Print);
}

void menu()
{
	vector<Process> process;  //进程信息表
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
		case 3:SJF(process);
			break;
		case 4:HRRN(process);
			break;
		case 5:RR(process);
			break;
		case 6: OutPut(process);
			break;
		default:
			break;
		}
	} while (input);
}

void testProcess()
{
	menu();
}

int main()
{
	testProcess();
	return 0;
}