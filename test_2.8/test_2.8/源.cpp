#define _CRT_SECURE_NO_WARNINGS
#include<string>

using namespace std;

string addBinary(string a, string b) {
	auto aBegin = a.rbegin();
	auto bBegin = b.rbegin();
	int prev = 0;
	while (aBegin != a.rend() && bBegin != b.rend())
	{
		*aBegin = *bBegin + *aBegin + prev;
		prev = *aBegin / 2;
		*aBegin %= 2;
		aBegin++;
		bBegin++;
	}
	return a;
}

int main()
{
	string a("11");
	string b("1");
	addBinary(a, b);
	return 0;
}