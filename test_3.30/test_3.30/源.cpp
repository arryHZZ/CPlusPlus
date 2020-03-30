#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>

using namespace std;

//int SeeFront(vector<int>& arr, int n)
//{
//	//向前看
//	int more;
//	int CanSee = 0;
//	if (n > 0)
//	{
//		CanSee = 1;
//		more = arr[n - 1];
//		for (int i = n; i > 0; i--)
//		{
//			if (arr[i - 1] > more)
//			{
//				CanSee++;
//				more = arr[i - 1];
//			}
//		}
//	}
//	int CanSee1 = 0;
//	//向后看
//	if (n < (arr.size() - 1))
//	{
//		CanSee1 = 1;
//		more = arr[n + 1];
//		for (int i = n; i < arr.size() - 1; i++)
//		{
//			if (arr[i + 1] > more)
//			{
//				CanSee1++;
//				more = arr[i + 1];
//			}
//		}
//	}
//
//
//
//	return CanSee + CanSee1;
//}
//
//int SeeBehind(vector<int>& arr, int n)
//{
//	if (n == (int)(arr.size() - 1))
//		return 0;
//	int more = arr[n + 1];
//	int CanSee = 1;
//	for (int i = n; i < arr.size() - 1; i++)
//	{
//		if (arr[i + 1] > more)
//		{
//			CanSee++;
//			more = arr[i + 1];
//		}
//	}
//	return CanSee;
//}
//
//int main()
//{
//	vector<int> build;
//	vector<int> see;
//	int n;
//	cin >> n;
//	build.resize(n);
//	see.resize(n);
//	for (auto& e : build)
//	{
//		cin >> e;
//	}
//
//	for (int i = 0; i < n; i++)
//	{
//		see[i] = 1 + SeeFront(build, i);
//	}
//	for (auto& e : see)
//	{
//		cout << e << " ";
//	}
//	return 0;
//}


void ChangeArr(vector<int>& arr, int n)
{
	for (int i = 0; i < arr.size(); i += n)
	{
		int left = i;
		int right = i + n - 1;
		while (right > left)
		{
			int tmp = arr[right];
			arr[right] = arr[left];
			arr[left] = tmp;
			right--;
			left++;
		}
	}
}

int Fun(vector<int>& arr)
{
	int n = 0;
	for (int i = 0; i < arr.size(); i++)
	{
		for (int j = i + 1; j < arr.size(); j++)
		{
			if (arr[j] < arr[i])
				n++;
		}
	}
	return n; 
}

int main()
{
	int n;
	int m;
	cin >> n;
	vector<int> num;
	num.resize(pow(2, n));
	for (auto& e : num)
	{
		cin >> e;
	}
	cin >> m;
	vector<int> M;
	M.resize(m);
	for (auto& e : M)
	{
		cin >> e;
	}
	vector<int> RetPrint;
	RetPrint.resize(m);
	for (int i = 0; i < m; i++)
	{
		ChangeArr(num, pow(2, M[i]));
		RetPrint[i] = Fun(num);
	}
	for (auto e : RetPrint)
	{
		cout << e << endl;
	}
	return 0;
}