#include <iostream>
using namespace std;
//类的定义
class X;
class Y
{
public:
	void g(X*p);
};
class X
{
public:
	X(int _a);
	friend void Y::g(X*p);
	friend void h(X*p);
	friend class Z;
	int getI() { return i; }
private:
	int i;
};
class Z
{
public:
	void f(X*p);
};
void h(X*p);
//实现类函数
X::X(int a)
:i(a)
{
}
void Y::g(X*p)
{
	p->i += 1;

}
void h(X*p)
{
	p->i += 10;
}


void Z::f(X*p)
{
	p->i += 5;
}
//主函数
int main()
{
	X x(3);
	Y y;
	Z z;
	cout << x.getI() << endl;
	y.g(&x);
	cout << x.getI() << endl;
	z.f(&x);
	cout << x.getI() << endl;
	h(&x);
	cout << x.getI() << endl;
	return 0;

}