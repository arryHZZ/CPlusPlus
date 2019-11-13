#include<vector>
#include<iostream>

using namespace std;

int main()
{
	vector<vector<int>> arr;
	int W, H;
	int count = 0;
	cin >> W >> H;
	arr.resize(W);

	for (auto& e : arr)
	{
		e.resize(H, 1);
	}
	for (int i = 0; i < W; i++)
	{
		for (int j = 0; j < H; j++)
		{
			if (arr[i][j] == 1)
			{
				count++;
				if ((i + 2)<W)
					arr[i + 2][j] = 0;
				if ((j + 2) < H)
					arr[i][j + 2] = 0;
			}
		}
	}
	cout << count << endl;
	return 0;
}