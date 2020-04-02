
#include<iostream>
using namespace std;
class X
{
	X(int _i)
	:i(_i)
	{
	}
	friend Z;
	friend void h(X* p);
	friend void Y::g(X* p);
	friend void h(X* p);
private:
	int i;
};

class Y
{
	void g(X* p);
};


class Z
{
public:
	void f(X* p);
};

void h(X* p)
{
	p->i += 10;
}

void Y::g(X* p)
{
	p->i++;
}




