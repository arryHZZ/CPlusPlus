#define _CRT_SECURE_NO_WARNINGS
#include<string>

using namespace std;

bool isPalindrome(string s) {
	int begin = 0;
	int end = s.size() - 1;
	for (int i = 0; i < s.size(); i++)
	{
		s[i] = toupper(s[i]);
	}
	//toUpper(s);
	while (begin <= end)
	{
		if (!((s[begin] >= 'A' && s[begin] <= 'Z') || (s[begin] >= '0' && s[begin] <= '9')))
		{
			begin++;
			continue;
		}
		if (!((s[end] >= 'A' && s[end] <= 'Z') ||( s[end] >= '0' && s[end] <= '9')))
		{
			end--;
			continue;
		}
		if (s[begin] != s[end])
		{
			return false;
		}
		else
		{
			begin++;
			end--;
		}
	}
	return true;
}



int main()
{
	string str("0P");
	isPalindrome(str);
	return 0;
}