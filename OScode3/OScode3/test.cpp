#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<stdlib.h>
#include<Windows.h>
#include<iomanip>

using namespace std;

class Process
{
public:
	vector<int> source;
	vector<vector<int>> max;
	vector<vector<int>> allocation;
	vector<vector<int>> need;
	vector<vector<int>> work;
	vector<int> av;
	vector<int> finish;
};


void menu()
{
	cout << "1. 初始化信息" << endl;
	cout << "2. 银行家算法" << endl;  //请求  试分配
	cout << "3. 安全性检测" << endl;   //录入max 分配
	cout << "4. 打印系统分配状态" << endl;
	cout << "0. 退出" << endl;
}

void MenuForInit()  //资源  进程
{
	//system("CLS");
	cout << "1. 设定资源总量" << endl;
	cout << "2. 进程信息初识化" << endl;
	cout << "3. 打印系统分配状态" << endl;
	cout << "0. 退出" << endl;
}

//打印进程信息
void OutPut(Process process)
{
	cout << "----------------------------------" << endl;
	cout << "av矩形:";
	for (int i = 0; i < process.av.size(); i++)
	{
		cout << setiosflags(ios::right);
		cout << " "<<setw(2) << process.av[i]<<" ";
	}
	cout << endl;
	cout << "----------------------------------" << endl;
	cout <<"进程编号 |" <<" Max矩阵    |" << " need矩阵   |" << " allocation矩阵" << endl;
	for (int i = 0; i < process.max.size(); i++)
	{
		cout << "    " << i << "   |";
		for (int j = 0; j < process.max[i].size(); j++)
		{
			cout << setiosflags(ios::right);
			cout << " "<<setw(2) << process.max[i][j] << " ";
		}
		cout << "|";

		for (int j = 0; j < process.need[i].size(); j++)
		{
			cout << setiosflags(ios::right);
			cout << " " << setw(2) << process.need[i][j] << " ";
		}
		cout << "|";
		for (int j = 0; j < process.allocation[i].size(); j++)
		{
			cout << setiosflags(ios::right);
			cout << " " << setw(2) << process.allocation[i][j] << " ";
		}
		cout << endl;
	}
	Sleep(1000);
}



//初始化资源信息
void InitSource(Process& process)
{
	cout << "请输入资源个数>>";
	int number = 0;
	cin >> number;
	process.av.resize(number);
	process.source.resize(number);
	cout << "输入每个资源的最大个数" << endl;
	for (int i = 0; i < number; i++)
	{
		cin >> process.source[i];
		process.av[i] = process.source[i];
	}
	cout << "输入成功" << endl;
	Sleep(1000);
}

//初识化进程信息
void InitProcess(Process& process)
{
	if (process.source.size() == 0)
	{
		cout << "    error !!!   请先初识化资源信息" << endl;
		Sleep(1500);
		return;
	}
	cout << "请输入进程总数>>";
	int n = 0;
	cin >> n;
	process.max.resize(n);
	process.finish.resize(n, 0);
	process.need.resize(n);
	process.allocation.resize(n);
	process.work.resize(n);
	for (int i = 0; i < n; i++)
	{
		process.max[i].resize(process.source.size());
		process.allocation[i].resize(process.source.size());
		process.need[i].resize(process.source.size());
		process.work[i].resize(process.source.size());
	}
	cout << "请输入每个进程所需资源的Max矩阵" << endl;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < process.source.size(); j++)
		{
			cin >> process.max[i][j];
		}
	}
	cout << "输入每个进程已分配的资源矩阵" << endl;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < process.source.size(); j++)
		{
			cin >> process.allocation[i][j];
		}
	}
	//计算need矩阵
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < process.source.size(); j++)
		{
			process.av[j] -= process.allocation[i][j];
			process.need[i][j] = process.max[i][j] - process.allocation[i][j];
		}
	}
	cout << "输入成功" << endl;
	Sleep(1000);
}

//安全性检测
int Testing(Process process)
{
	vector<int> list;	

	list.resize(process.max.size());
	vector<int> tmp(process.av);
	//循环整个进程表
	int count = 0;
	int num = 0;
	while (count < process.max.size())
	{
		//从表中选择符合条件的进程
		for (int i = 0; i < process.max.size(); i++)
		{
			//进程未执行
			if (process.finish[i] == 0)
			{
				int j = 0;
				//判断进程的need矩阵是否能够满足
				for (j = 0; j < process.source.size(); j++)
				{
					if (process.need[i][j] > tmp[j])
						break;
				}
				//满足分配条件，分配可用资源
				if (j == process.source.size())
				{
					list[num++] = i;
					process.finish[i] = 1;
					for (j = 0; j < process.source.size(); j++)
					{
						process.work[i][j] = tmp[j];
						tmp[j] += process.allocation[i][j];
					}
					break;
				}
			}
		}
		if (num == count || num == 0)
		{
			cout << "*********************" << endl;
			cout << "*****无安全序列******" << endl;
			cout << "*********************" << endl;
			return 1;
		}
		count++;
	}
	cout << "----------------------------------" << endl;
	cout << "进程编号|" << " Max矩阵    |" << " need矩阵       |" << " allocation矩阵   |" << " work矩阵   " << endl;
	for (int i = 0; i < list.size(); i++)
	{

		cout << "    " << list[i] << "   |";
		for (int j = 0; j < process.max[i].size(); j++)
		{
			cout << setiosflags(ios::right);
			cout << " " << setw(2) << process.max[list[i]][j] << " ";
		}
		cout << "|";

		for (int j = 0; j < process.need[list[i]].size(); j++)
		{
			cout << setiosflags(ios::right);
			cout << " " << setw(2) << process.need[list[i]][j] << " ";
		}
		cout << "|";
		for (int j = 0; j < process.allocation[i].size(); j++)
		{
			cout << setiosflags(ios::right);
			cout << " " << setw(2) << process.allocation[list[i]][j] << " ";
		}
		cout << "|";
		for (int j = 0; j < process.work[i].size(); j++)
		{
			cout << setiosflags(ios::right);
			cout << " " << setw(2) << process.work[list[i]][j] << " ";
		}
		cout << endl;
	}
	return 0;
	//cout << "Testing()" << endl;
	Sleep(1000);
}


//请求资源分配
void ProcessAskSource(Process& process)
{
	//请求大于需求、请求大于可用。
	vector<int> requet;
	int num = 0;
	requet.resize(process.source.size());
	cout << "请输入需要请求资源的进程编号>>";
	cin >> num;
	if (num >= process.max.size() || num < 0)
	{
		cout << "********ERROR*********" << endl;
		cout << "*****进程不存在******" << endl;
		cout << "*********************" << endl;
		return;
	}
	cout << "请输入request矩阵:";
	for (auto& e : requet)
	{
		cin >> e;
	}
	//判断请求是否大于需求
	for (int i = 0; i < process.source.size(); i++)
	{
		if (requet[i] > process.need[num][i])
		{
			cout << "********ERROR**********" << endl;
			cout << "*****请求大于需求******" << endl;
			cout << "**********************" << endl;
			return;
		}
	}
	//判断请求是否大于可用
	for (int i = 0; i < process.source.size(); i++)
	{
		if (requet[i] > process.av[i])
		{
			cout << "********ERROR**********" << endl;
			cout << "*****请求大于可用******" << endl;
			cout << "**********************" << endl;
			return;
		}
	}
	//试分配
	for (int i = 0; i < process.source.size(); i++)
	{
		process.av[i] -= requet[i];
		process.allocation[num][i] += requet[i];
		process.need[num][i] -= requet[i];
	}
	//分配成功
	if (Testing(process) == 0)
	{
		cout << "**********************" << endl;
		cout << "*****请求分配成功*****" << endl;
		cout << "**********************" << endl;
	}
	else
	{
		//复原之前资源信息
		for (int i = 0; i < process.source.size(); i++)
		{
			process.av[i] += requet[i];
			process.allocation[num][i] -= requet[i];
			process.need[num][i] += requet[i];
		}
		Sleep(1000);
	}
}



void test()
{
	Process process;
	int input1 = 0;
	do
	{
		menu();
		cout << "请输入你的选择>> ";
		cin >> input1;
		switch (input1)
		{
		case 1:{
				  system("CLS");
				  int input2 = 0;
				  do
				  {
					  MenuForInit();
					  cout << "请输入你的选择>> ";
					  cin >> input2;
					  switch (input2)
					  {
					  case 1:InitSource(process);
						  system("CLS");
						  break;
					  case 2:InitProcess(process);
						  break;
					  case 3:OutPut(process);
						  break;
					  default:
						  break;
					  }
				  } while (input2);
				  system("CLS");
		}
			break;
		case 2:{
				   ProcessAskSource(process);
		}
			break;
		case 3:Testing(process);
			break;
		case 4: OutPut(process);
			break;
		default:
			break;
		}
	} while (input1);
}

int main()
{
	test();
	return 0;
}
