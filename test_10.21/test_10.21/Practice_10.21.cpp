//#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include"Practice_10.21.h"
using  namespace std;

void junjun::Cin()
{
	cin >> junjun::a;
}

void junjun::Cout()
{
	cout << junjun::a;
}

int main()
{
	junjun kunkun;
	kunkun.Cin();
	kunkun.Cout();
	return 0;
}

//namespace N1
//{
//	int a;
//	int Add(int a, int b)
//	{
//		return a + b;
//	}
//}
//
//int testFun(int a, int b = 1, int c = 2)
//{
//	cout << a << b << c;
//	return 0;
//}
//
//double Add(double a, double b)
//{
//	return a + b;
//}
//
//inline int add(int a, int b)
//{
//	return a + b;
//}
//
//using N1::a;
//using N1::Add;
//int main()
//{
//	int arr[] = { 4, 5, 6, 7, 8 };
//	for (auto&e : arr)
//	{
//		e = e * 2;
//		cout << e;
//	}
//	int a = 1;
//	int& b = a;
//	//int *p = nullptr;
//	cout << a;
//	cin >> b;
//	cout << a;
//	////int b = 1;
//	////double c = 2;
//	////b = Add(1, 2);
//	////c = Add(1.2, 2.1);
//	////cout << b << endl<< c;
//	//////testFun(b);
//	//////cin >> a ,b ,c;
//	//////cout << Add(b, c) << endl;
//	return 0;
//}