#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<vector>
#include<iomanip>
#include<queue>

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

	//��ֵ���������
	Time& operator=(Time& time)
	{
		this->_hour = time._hour;
		this->_minute = time._minute;
		return *this;
	}

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
	cout << "ʱ��:";
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

//������
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
	//��������
	friend istream& operator>>(istream& _cin, Process& process);
	//�������
	friend ostream& operator<<(ostream& _cout, const Process process);
	//��������
	Process& operator&()
	{
		return *this;
	}
	//��ֵ����
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
	static Time _LineTime;  //ʱ����
	int _name; //���̱��
	Time _EnterTime;  // ����ʱ��
	size_t _ServiceTime; //����ʱ��
	Time _BeginTime;  //��ʼʱ��
	Time _FinishTime;  //���ʱ��
	size_t _rTime;  //��תʱ��
	double _PowerTime;  //��Ȩ��תʱ��
	double _First;  //���ȼ�
	int _RemainSeviceTime;  //ʣ��ʱ��

};

Time Process::_LineTime;

istream& operator>>(istream& _cin, Process& process)
{
	cout << "���̱��:";
	_cin >> process._name;
	cout << "����";
	_cin >> process._EnterTime;
	cout << "����ʱ��:";
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

//����
void InPut(vector<Process>& process)
{
	cout << "��Ӽ�������:";
	int n;
	cin >> n;
	process.resize(n);
	for (auto& e : process)
	{
		cin >> e;
	}
}

//���
void OutPut(const vector<Process>& process)
{
	cout << "���̱��  " << "����ʱ��  " << "��ʼʱ��  " 
		<< "����ʱ��  " << "���ʱ��  " << "��תʱ��  " << "��Ȩ��תʱ��" << endl;
	for (auto e : process)
	{
		cout << e << endl;
	}
}

//����
void Swap(Process& a, Process& b)
{
	Process tmp = a;
	a = b;
	b = tmp;
}

//���ս���ʱ���������
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

//����ִ�н���
void RunProcess(vector<Process>& process)
{
	if (process.size() == 0)
		return;
	for (int i = 0; i < process.size(); i++)
	{
		//������̽���ʱ��С�ڵ���ʱ���ߵ�ʱ��
		if (process[i]._LineTime <= process[i]._EnterTime)
		{
			//��ÿ�ʼʱ���ӦΪ�ý��̵Ľ���ʱ��
			process[i]._BeginTime = process[i]._EnterTime;
			process[i]._LineTime = process[i]._EnterTime;  //��ʱ���ߵ�ʱ����������̽���ʱ��
			process[i]._LineTime += process[i]._ServiceTime;  //��ʱ��������һ���ý��̵ķ���ʱ��
			process[i]._FinishTime = process[i]._LineTime;  //�����̽���ʱ���޸�Ϊ��ǰʱ����ʱ��
		}
		else  //���̽���ʱ�����ʱ����ʱ�䣬��֤���ý���һֱ�ڵȴ�״̬
		{
			process[i]._BeginTime = process[i]._LineTime;  //�����̿�ʼʱ�丳ֵΪ��ǰʱ����ʱ��
			process[i]._LineTime += process[i]._ServiceTime;  //��ʱ��������һ���ý���ʱ��
			process[i]._FinishTime = process[i]._LineTime;  //�����̽���ʱ���޸�Ϊ��ǰʱ����ʱ��
		}
		process[i]._rTime = process[i]._FinishTime - process[i]._EnterTime;   //����ý��̵���תʱ��
		process[i]._PowerTime = process[i]._rTime / process[i]._ServiceTime;  //����ý��̵Ĵ�Ȩ��תʱ��
	}
}

//����ִ�н���
void TmpOfPrccess(Process& process, int n)
{
	//�������ʱ�����ʣ�����ʱ�䣬��֤���ý��̵�һ�α�����
	if (process._ServiceTime == process._RemainSeviceTime)
	{
		//�趨��ʼʱ��
		process._BeginTime = process._LineTime;
	}
	//���ʣ�����ʱ����ڵ���һ��ʱ��Ƭ��ʱ��
	if (process._RemainSeviceTime >= n)
	{
		//ʣ��ʱ�����һ��ʱ��Ƭ��ʱ��
		process._RemainSeviceTime -= n;
		//ʱ��������ƶ�һ��ʱ��Ƭ
		process._LineTime += n;
	}
	else  //���ʣ��ʱ��С��һ��ʱ��ʱ��Ƭ��ʱ��
	{
		//ʱ��������ƶ�һ���ý��̵�ʣ��ʱ��
		process._LineTime += process._RemainSeviceTime;
		process._RemainSeviceTime = 0;  //��ʣ��ʱ����Ϊ0
	}
	if (process._RemainSeviceTime == 0)  //���ʣ��ʱ��Ϊ0����֤���ý��̽�������
	{
		process._FinishTime = process._LineTime;  // �趨����ʱ�䣬������תʱ�䣬��Ȩ��תʱ��
		process._rTime = process._FinishTime - process._EnterTime;
		process._PowerTime = (double)process._rTime / process._ServiceTime;
	}
}

//�����ȷ���
void FCFS(vector<Process> process)
{
	if (process.size() == 0)
		return;
	EnterTimeSort(process);  //���ս���ʱ������
	process[0]._LineTime = process[0]._EnterTime;   //����������ڴ���ǽ���ʱ������Ϊʱ���ߵ����
	RunProcess(process);  //����ִ�����н���
	OutPut(process);
}

//��������ʱ������
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

//�̽�������
void SJF(vector<Process> process)
{
	if (process.size() == 0)
		return;
	vector<Process> q;  //�������̽�����Ϣ��¼��
	EnterTimeSort(process);   //���ݽ���ʱ������
	process[0]._LineTime = process[0]._EnterTime;   //�趨ʱ������ʼʱ��
	vector<Process> tmp;   //���������
	while (!process.empty() || !tmp.empty())   //������غͽ�����Ϣ��ʱ��ͬʱΪ��ѭ������
	{
		auto begin = process.begin();   
		while (begin != process.end())   //�жϵ�ǰʱ���ߣ�����Щ�����Ѿ�����
		{
			if (begin->_EnterTime <= begin->_LineTime)     //������̽���ʱ��С��ʱ����ʱ�䣬֤�������Ѿ�����
			{
				tmp.push_back(*begin);                //���뻺�����
				begin = process.erase(process.begin());  //�ӽ�����Ϣ����ɾ�������Ϣ
			}
			else
				begin++;
		}
		if (tmp.size() != 0)
		{ 
			ServiceTimeSort(tmp);    //��������еĽ�����Ϣ���ݽ��̷���ʱ������
			auto Tbegin = tmp.begin();
			TmpOfPrccess(*Tbegin, Tbegin->_RemainSeviceTime);   //������ʱ����̵Ľ��е���ִ��
			q.push_back(*Tbegin);   //���ý�����Ϣ���������Ϣ��¼��
			tmp.erase(tmp.begin());  //�ӻ������ɾ���ý�����Ϣ
		}
		//���������û�н���ʱ����������Ϣ��Ϊ�գ���ʱ����ʱ�䲻������һ�����̵���޸�ʱ����ʱ��
		if (tmp.size() == 0 && !process.empty() && process[0]._EnterTime > process[0]._LineTime)
		{
			process[0]._LineTime = process[0]._EnterTime;
		}
	}
	//��ӡ������
	OutPut(q);
}

//������Ӧ��
void CalculateFirst(vector<Process>& process)
{
	if (process.size() == 0)
		return;
	for (auto&e : process)
	{
		e._First = (double)(e._LineTime - e._EnterTime) / e._ServiceTime + 1;
	}
}

//������Ӧ������
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

//����Ӧ������
void HRRN(vector<Process> process)
{
	if (process.size() == 0)
		return;
	EnterTimeSort(process);
	vector<Process> q;   //������Ϣ��
	vector<Process> tmp;  //�����
	process[0]._LineTime = process[0]._EnterTime;  //����ʱ������ʼʱ��
	while (!process.empty() || !tmp.empty())   //����Ϊ��
	{
		auto begin = process.begin();
		while (begin != process.end())  //�жϵ�ǰʱ������Щ���̵���
		{
			if (begin->_EnterTime <= begin->_LineTime)
			{ 
				tmp.push_back(*begin);   //���̵�����뻺�����
				begin = process.erase(process.begin());
			}
			else
				begin++;
		}
		//������Ӧ��
		CalculateFirst(tmp);
		//������Ӧ������
		FirstSort(tmp);
		if (tmp.size() != 0)
		{
			auto begin = tmp.begin();
			//����ִ�н���
			TmpOfPrccess(*begin, begin->_ServiceTime);
			q.push_back(*begin);
			tmp.erase(tmp.begin());
		}
		//�����ȳ���û�н���ʱ����ʱ���ߵ�ʱ�䲻����ʹ��һ�����̽��뵽���ȳ��У��޸�ʱ����
		if (!process.empty() && tmp.size() == 0 && process[0]._LineTime < process[0]._EnterTime)
		{
			process[0]._LineTime = process[0]._EnterTime;
		}
	}
	OutPut(q);
}

//ʱ��Ƭ��ת
void RR(vector<Process> process)
{
	if (process.size() == 0)
		return;
	vector<Process> Print;
	queue<Process> Queue;  //�����
	EnterTimeSort(process);
	int q = 0;  //ʱ��Ƭ���ȣ��Է���Ϊ��λ
	cout << "������ʱ��Ƭ�ĳ���:";
	cin >> q;
	process[0]._LineTime = process[0]._EnterTime;
	process[0]._BeginTime = process[0]._LineTime;
	Queue.push(process[0]);
	process.erase(process.begin());
	while (Queue.size() != 0)
	{
		//����ͷ�Ľ���ִ��һ��ʱ��Ƭ
		cout<<Queue.front()._name;
		TmpOfPrccess(Queue.front(), q);
		//�鿴������Ϣ������Щ���̵���,��������������еȴ�ִ��
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
		//�ж϶�ͷԪ���Ƿ��Ѿ�ִ�н���
		Process tmp = Queue.front();
		Queue.pop();  //����

		if (tmp._RemainSeviceTime != 0)
		{
			Queue.push(tmp);
		}
		else
		{
			Print.push_back(tmp);  //���浽��Ϣ����

		}
		//�����ȳ���û�н���ʱ����ʱ���ߵ�ʱ�䲻����ʹ��һ�����̽��뵽���ȳ��У��޸�ʱ����
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
	vector<Process> process;  //������Ϣ��
	int input = 0;
	do
	{
		cout << "1.���������Ϣ" << endl;
		cout << "2.�����ȷ���" << endl;
		cout << "3.�̽�������" << endl;
		cout << "4.�����ȼ�����" << endl;
		cout << "5.ʱ��Ƭ��ת" << endl;
		cout << "6.��ӡ������Ϣ" << endl;
		cout << "��������ѡ��>>";
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