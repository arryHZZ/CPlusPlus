#define _CRT_SECURE_NO_WARNINGS
//#include<iostream>
//#include<string>
//
//using namespace std;
//
//int main()
//{
//	int a;
//	cin>>a;
//	string p = to_string(a);
//	auto begin = p.begin();
//	for (int i = 0; i < 3; i++)
//	{
//		cout << *begin << " ";
//		begin++;
//	}
//	cout << *begin;
//	return 0;
//}
//
//#include<iostream>
//
//using namespace std;
//
//int qcout(int n)
//{
//	int count = 0;
//	for (int i = 1; i <= n/2; i++)
//	{
//		if (n%i == 0)
//			count++;
//	}
//	return count*2;
//}
//
//int main(){
//	int a, b, c, i;
//	while (cin>>a>>b)
//	{
//		if (a > b)
//			c = b;
//		else
//			c = a;
//		for (i = c; i >= 1; i--)
//		{
//			if (a%i == 0 && b%i == 0)
//			{
//				break;
//			}
//		}
//		int ret = qcout(i);
//		printf("%d\n", ret);
//	}
//	return 0;
//}


//#include <cstdio>  
//#include <iostream>  
//
//using namespace std;
//#define max 35  
//
//int main()
//{
//	int A[max][max];
//	int res[max][max];
//	int n, m;
//	cin >> n >> m;
//
//	for (int i = 0; i < n; ++i)
//	for (int j = 0; j < n; ++j){
//		cin >> A[i][j];
//		res[i][j] = A[i][j];
//	}
//	int i;
//	int t;
//	for (t = 0; t < m - 1; ++t){
//		for (i = 0; i < n; ++i)
//		for (int j = 0; j < n; ++j){
//			res[i][j] = 0;
//			for (int k = 0; k < n; ++k)
//				res[i][j] += A[i][k] * A[k][j];
//		}
//		for (i = 0; i < n; ++i)
//		for (int j = 0; j < n; ++j)
//			A[i][j] = res[i][j];
//	}
//
//	for (i = 0; i < n; ++i){
//		for (int j = 0; j < n; ++j)
//		{
//			cout << (m == 0 ? (i == j ? 1 : 0) : res[i][j]);
//			if (j != n - 1)
//				cout << " ";
//		}
//		if (i != n-1)
//			cout << endl;
//	}
//	return 0;

//
//
//#include <stdio.h>
//
//struct Student{
//	int num;
//	int score;
//	struct Student *next;
//};
//void input(Student *stu, int n);
//Student *merge(Student *stu1, Student *stu2, int m);
//void print(Student *stu);
//int main()
//{
//	Student a[3], b[2];
//	input(a, 3);
//	input(b, 2);
//	print(merge(a, b, 3));
//
//	return 0;
//}
//
//void input(Student *stu, int n)
//{
//	int i;
//	Student *p;
//	for (p = stu, i = 0; p<stu + n; p++, i++){
//		//printf("Please enter No.%d student info; ", i + 1);
//		scanf("%d %d", &p->num, &p->score);
//		i == n - 1 ? p->next = NULL : p->next = &stu[i + 1];
//	}
//}
//Student *merge(Student *stu1, Student *stu2, int m)
//{
//	stu1[m - 1].next = stu2;
//	Student *p, *q, temp;
//	for (p = stu1; p != NULL; p = p->next)
//	for (q = p->next; q != NULL; q = q->next)
//	if (p->num>q->num){
//		temp.num = p->num;
//		p->num = q->num;
//		q->num = temp.num;
//		temp.score = p->score;
//		p->score = q->score;
//		q->score = temp.score;
//	}
//	return stu1;
//}
//
//void print(Student *stu)
//{
//	Student *p;
//	for (p = stu; p != NULL; p = p->next)
//		printf("%d %d\n", p->num, p->score);
//}


#include<iostream>
#include<vector>

using namespace std;

class stu
{
public:
	stu()
	{}
	~stu(){}
	friend istream& operator>>(istream& _cin, stu& a);
	friend ostream& operator<<(ostream& _cout, stu& a);
	stu& operator=(stu& a)
	{
		this->num = a.num;
		this->seor = a.seor;
		return *this;
	}
	int num;
	int seor;
};

istream& operator>>(istream& _cin, stu& a)
{
	_cin >> a.num >> a.seor;
	return _cin;
}

ostream& operator<<(ostream& _cout, stu& a)
{
	_cout << a.num <<" "<< a.seor;
	return _cout;
}

void swap1(stu& a, stu& b)
{
	stu tmp = a;
	a = b;
	b = tmp;
}

int main()
{
	int n, m;
	cin >> n >> m;
	vector<stu> arr;
	arr.resize(n + m);
	for (auto& e : arr)
	{
		cin >> e;
	}
	for (int i = 0; i < m + n - 1; i++)
	{
		for (int j = 0; j < m + n - i - 1; j++)
		{
			if (arr[j].num > arr[j + 1].num)
				swap1(arr[j], arr[j + 1]);
		}
	}
	for (auto e : arr)
	{
		cout << e << endl;
	}
	return 0;
}