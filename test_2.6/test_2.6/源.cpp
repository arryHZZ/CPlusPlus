#define _CRT_SECURE_NO_WARNINGS
#include<vector>
#include<iostream>

using namespace std;

vector<int> sortedSquares(vector<int>& A) {
	vector<int> tmp;
	int i = 0;
	//找出负数部分
	for (i = 0; i < A.size(); i++)
	{
		if (A[i] >= 0)
			break;
	}
	int folg = i;
	tmp.resize(i);
	//负数部分平方
	for (int z = 0; z < i; z++)
	{
		tmp[z] = A[z] * A[z];
	}
	//整数部分平方
	for (i ; i < A.size(); i++)
	{
		A[i] *= A[i];
	}
	i = folg;
	auto Abegin = A.begin();
	auto TmpBegin = tmp.rbegin();
	while (Abegin != A.end() && i != A.size() && TmpBegin != tmp.rend())
	{
		if (A[i] < *TmpBegin)
		{
			*Abegin = A[i];
			Abegin++;
			i++;
		}
		else
		{
			*Abegin = *TmpBegin;
			Abegin++;
			TmpBegin++;
		}
	}
	if (i != A.size())
	{
		while (Abegin != A.end() && i != A.size())
		{
			*Abegin = A[i];
			Abegin++;
			i++;
		}
	}
	if (TmpBegin != tmp.rend())
	{
		while (Abegin != A.end() && TmpBegin != tmp.rend())
		{
			*Abegin = *TmpBegin;
			Abegin++;
			TmpBegin++;
		}
	}
	return A;
}

int main()
{
	vector<int> A;
	A.resize(5);
	for (auto &e : A)
	{
		cin >> e;
	}
	sortedSquares(A);
	return 0;
}