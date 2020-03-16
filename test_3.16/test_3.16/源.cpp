#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

class person{

public: 
	virtual ~person()
	{
		cout << "person" << endl;
	}
	virtual void Print()
	{
		cout << "person" << endl;
	}
};

class boy : public person
{
public:
	virtual ~boy()
	{
		cout << "boy" << endl;
	}
	virtual void Print()
	{
		cout << "boy" << endl;
	}
};

class girl : public person
{
public:
	virtual void Print()
	{
		cout << "girl" << endl;
	}
};

int main()
{
	boy b;
	//p->Print();
	//p->~person();
	//p = new girl;
	//p->Print();
	return 0;
}