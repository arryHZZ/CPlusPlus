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
	cout << "av矩形:";
	for (int i = 0; i < process.av.size(); i++)
	{
		cout << setiosflags(ios::right);
		cout << " "<<setw(2) << process.av[i]<<" ";
	}
	cout << endl;
	cout << "----------------------------------" << endl;
	cout <<"进程编号|" <<" Max矩阵    |" << " need矩阵       |" << " allocation矩阵" << endl;
	for (int i = 0; i < process.max.size(); i++)
	{
		cout << "  " << i << "  |";
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
	//cout << "----------------------------------" << endl;
	//cout << "      need矩阵       " << endl;
	//for (int i = 0; i < process.need.size(); i++)
	//{
	//	for (int j = 0; j < process.need[i].size(); j++)
	//	{
	//		cout << setiosflags(ios::right);
	//		cout << " " << setw(2) << process.need[i][j] << " ";
	//	}
	//	cout << endl;
	//}
	//cout << "----------------------------------" << endl;
	//cout << "    allocation矩阵" << endl;
	//for (int i = 0; i < process.allocation.size(); i++)
	//{
	//	for (int j = 0; j < process.allocation[i].size(); j++)
	//	{
	//		cout << setiosflags(ios::right);
	//		cout << " " << setw(2) << process.allocation[i][j] << " ";
	//	}
	//	cout << endl;
	//}
	//cout << "OutPut" << endl;
	Sleep(1000);
}

void MenuForBankers()
{
	//system("CLS");
	cout << "1. 资源请求分配" << endl;
	cout << "2. 安全性检测" << endl;
	cout << "3. 打印系统分配状态" << endl;
	cout << "0. 退出" << endl;
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

//请求资源分配
void ProcessAskSource(Process& process)
{
	cout << "ProcessAskSource()" << endl;
	Sleep(1000);
}

//安全性检测
void Testing(Process process)
{
	vector<int> list;
	int num;
	list.resize(process.max.size());
	int cnt = 0;
	int folg = 0;
	while (cnt < process.max.size())
	{
		folg = 0;
		for (int i = 0; i < process.max.size(); i++)
		{
			if (process.finish[i] != 1)
			{
				for (num = 0; num < process.source.size(); num++)
				{
					if (process.need[i][num] > process.av[i])
						break;
				}
				if (num == process.source.size())
				{
					folg = 1;
					list[cnt++] = i;
					process.finish[i] = 1;
					for (num = 0; num < process.source.size(); num)
					{
						process.work[i][num] = process.av[num];
						process.work[i][num] += process.need[i][num];
					}
				}
			}
		}
	}
	cout << "Testing()" << endl;
	Sleep(1000);
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
						  system("CLS");
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
				   system("CLS");
				   int input3 = 0;
				   do
				   {
					   
					   MenuForBankers();
					   cout << "请输入你的选择>> ";
					   cin >> input3;
					   switch (input3)
					   {
					   case 1:ProcessAskSource(process);		
						      system("CLS");
						   break;
					   case 2:Testing(process);		
						      system("CLS");
						   break;
					   case 3:OutPut(process);
						   break;
					   default:
						   break;
					   }
				   } while (input3);
				   system("CLS");
		}
			break;
		case 3:Testing(process);
			   system("CLS");
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
