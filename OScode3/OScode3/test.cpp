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
	cout << "----------------------------------" << endl;
	cout << "av����:";
	for (int i = 0; i < process.av.size(); i++)
	{
		cout << setiosflags(ios::right);
		cout << " "<<setw(2) << process.av[i]<<" ";
	}
	cout << endl;
	cout << "----------------------------------" << endl;
	cout <<"���̱�� |" <<" Max����    |" << " need����   |" << " allocation����" << endl;
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

//��ȫ�Լ��
int Testing(Process process)
{
	vector<int> list;	

	list.resize(process.max.size());
	vector<int> tmp(process.av);
	//ѭ���������̱�
	int count = 0;
	int num = 0;
	while (count < process.max.size())
	{
		//�ӱ���ѡ����������Ľ���
		for (int i = 0; i < process.max.size(); i++)
		{
			//����δִ��
			if (process.finish[i] == 0)
			{
				int j = 0;
				//�жϽ��̵�need�����Ƿ��ܹ�����
				for (j = 0; j < process.source.size(); j++)
				{
					if (process.need[i][j] > tmp[j])
						break;
				}
				//����������������������Դ
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
			cout << "*****�ް�ȫ����******" << endl;
			cout << "*********************" << endl;
			return 1;
		}
		count++;
	}
	cout << "----------------------------------" << endl;
	cout << "���̱��|" << " Max����    |" << " need����       |" << " allocation����   |" << " work����   " << endl;
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


//������Դ����
void ProcessAskSource(Process& process)
{
	//�����������������ڿ��á�
	vector<int> requet;
	int num = 0;
	requet.resize(process.source.size());
	cout << "��������Ҫ������Դ�Ľ��̱��>>";
	cin >> num;
	if (num >= process.max.size() || num < 0)
	{
		cout << "********ERROR*********" << endl;
		cout << "*****���̲�����******" << endl;
		cout << "*********************" << endl;
		return;
	}
	cout << "������request����:";
	for (auto& e : requet)
	{
		cin >> e;
	}
	//�ж������Ƿ��������
	for (int i = 0; i < process.source.size(); i++)
	{
		if (requet[i] > process.need[num][i])
		{
			cout << "********ERROR**********" << endl;
			cout << "*****�����������******" << endl;
			cout << "**********************" << endl;
			return;
		}
	}
	//�ж������Ƿ���ڿ���
	for (int i = 0; i < process.source.size(); i++)
	{
		if (requet[i] > process.av[i])
		{
			cout << "********ERROR**********" << endl;
			cout << "*****������ڿ���******" << endl;
			cout << "**********************" << endl;
			return;
		}
	}
	//�Է���
	for (int i = 0; i < process.source.size(); i++)
	{
		process.av[i] -= requet[i];
		process.allocation[num][i] += requet[i];
		process.need[num][i] -= requet[i];
	}
	//����ɹ�
	if (Testing(process) == 0)
	{
		cout << "**********************" << endl;
		cout << "*****�������ɹ�*****" << endl;
		cout << "**********************" << endl;
	}
	else
	{
		//��ԭ֮ǰ��Դ��Ϣ
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
