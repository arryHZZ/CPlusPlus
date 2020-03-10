#define _CRT_SECURE_NO_WARNINGS
#include <vector>
#include <set>

using namespace std;

int getValue(vector<int> gifts, int n) {
	// write code here
	multiset<int> muset;
	for (int i = 0; i < n; i++)
	{
		muset.insert(gifts[i]);
		if (muset.count(gifts[i]) >(n / 2))
		{
			return gifts[i];
		}
	}
	return 0;
}

int main()
{
	vector<int> arr = { 1, 2, 2, 3, 4, 1, 2, 2, 2 };
	int ret = getValue(arr, arr.size());
	return 0;
}