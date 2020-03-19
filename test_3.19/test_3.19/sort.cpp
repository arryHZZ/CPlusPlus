#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int count = 0;

void InsertSort(int *arr, int len)
{
	int i = 0;
	for (i; i < len; i++)
	{
		for (int end = i; end >= 1; end--)
		{
			if (arr[end] < arr[end - 1])
			{
				int tmp = arr[end];
				arr[end] = arr[end - 1];
				arr[end - 1] = tmp;
			}
			else
			{
				break;
			}
		}
	}

}

void Print(int *arr, int len)
{
	for (int i = 0; i < len; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}

void ShellSort(int *arr, int len)
{
	int tap = len / 2;
	int i = 0;
	int end = 0;
	while (tap)
	{
		for (i = tap; i < len; i++)
		{
			for (end = i; end >= tap; end -= tap)
			{
				if (arr[end] < arr[end - tap])
				{
					int tmp = arr[end];
					arr[end] = arr[end - 1];
					arr[end - 1] = tmp;
				}
				else
				{
					break;
				}
			}

		}
		tap /= 2;
	}
}

void swap(int* a, int* b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

int PartOfQSort(int *arr, int left, int right)
{
	int tmp = arr[left];
	int key = left;
	//int tmp = 0;
	while (left < right)
	{
		while (left < right && arr[right] >= tmp)
		{
			right--;
		}
		while (left < right && arr[left] <= tmp)
		{
			left++;
		}
		swap(&arr[left], &arr[right]);
	}
	swap(&arr[key], &arr[left]);
	count++;
	//Print(arr, 1000);
	return left;
}

void ChangeMid(int *arr, int left, int right)
{
	int mid = (right + left) / 2;
	if (arr[left] > arr[right])
	{
		if (arr[right] < arr[mid])
			swap(&arr[right], &arr[mid]);
	}
	else
	{
		if (arr[left] < arr[mid])
			swap(&arr[left], &arr[mid]);
	}
}

void QSort(int *arr, int left, int right)
{
	//ChangeMid(arr, left, right);
	int mid = PartOfQSort(arr, left, right);
	if (right > mid + 1)
		QSort(arr, mid + 1, right);
	if (left < mid - 1)
		QSort(arr, left, mid - 1);
}

int main()
{
	int arr[1000] = { 9,8,7,6,5,4,3,2,1 };
	for (int i = 0; i < 1000; i++)
	{
		arr[i] = 1000 - i;
	}
	int len = sizeof(arr) / sizeof(arr[0]);
	//InsertSort(arr, sizeof(arr) / sizeof(arr[0]));
	//ShellSort(arr,len);
	QSort(arr, 0, len - 1);
	printf("%d", count);
	//Print(arr, sizeof(arr) / sizeof(arr[0]));
	return 0;
}