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
	cout << "1. ��ʼ����Ϣ" << endl;
	cout << "2. ���м��㷨" << endl;  //����  �Է���
	cout << "3. ��ȫ�Լ��" << endl;   //¼��max ����
	cout << "4. ��ӡϵͳ����״̬" << endl;
	cout << "0. �˳�" << endl;
}

void MenuForInit()  //��Դ  ����
{
	//system("CLS");
	cout << "1. �趨��Դ����" << endl;
	cout << "2. ������Ϣ��ʶ��" << endl;
	cout << "3. ��ӡϵͳ����״̬" << endl;
	cout << "0. �˳�" << endl;
}

//��ӡ������Ϣ
void OutPut(Process process)
{
	cout << "av����:";
	for (int i = 0; i < process.av.size(); i++)
	{
		cout << setiosflags(ios::right);
		cout << " "<<setw(2) << process.av[i]<<" ";
	}
	cout << endl;
	cout << "----------------------------------" << endl;
	cout <<"���̱��|" <<" Max����    |" << " need����       |" << " allocation����" << endl;
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
	//cout << "      need����       " << endl;
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
	//cout << "    allocation����" << endl;
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
	cout << "1. ��Դ�������" << endl;
	cout << "2. ��ȫ�Լ��" << endl;
	cout << "3. ��ӡϵͳ����״̬" << endl;
	cout << "0. �˳�" << endl;
}

//��ʼ����Դ��Ϣ
void InitSource(Process& process)
{
	cout << "��������Դ����>>";
	int number = 0;
	cin >> number;
	process.av.resize(number);
	process.source.resize(number);
	cout << "����ÿ����Դ��������" << endl;
	for (int i = 0; i < number; i++)
	{
		cin >> process.source[i];
		process.av[i] = process.source[i];
	}
	cout << "����ɹ�" << endl;
	Sleep(1000);
}

//��ʶ��������Ϣ
void InitProcess(Process& process)
{
	if (process.source.size() == 0)
	{
		cout << "    error !!!   ���ȳ�ʶ����Դ��Ϣ" << endl;
		Sleep(1500);
		return;
	}
	cout << "�������������>>";
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
	cout << "������ÿ������������Դ��Max����" << endl;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < process.source.size(); j++)
		{
			cin >> process.max[i][j];
		}
	}
	cout << "����ÿ�������ѷ������Դ����" << endl;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < process.source.size(); j++)
		{
			cin >> process.allocation[i][j];
		}
	}
	//����need����
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < process.source.size(); j++)
		{
			process.av[j] -= process.allocation[i][j];
			process.need[i][j] = process.max[i][j] - process.allocation[i][j];
		}
	}
	cout << "����ɹ�" << endl;
	Sleep(1000);
}

//������Դ����
void ProcessAskSource(Process& process)
{
	cout << "ProcessAskSource()" << endl;
	Sleep(1000);
}

//��ȫ�Լ��
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
		cout << "���������ѡ��>> ";
		cin >> input1;
		switch (input1)
		{
		case 1:{
				  system("CLS");
				  int input2 = 0;
				  do
				  {
					  MenuForInit();
					  cout << "���������ѡ��>> ";
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
					   cout << "���������ѡ��>> ";
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
