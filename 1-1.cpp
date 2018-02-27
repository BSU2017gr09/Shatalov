#include <iostream>
using namespace std;

int* arrMem(int N)
{
	int* array;
	try
	{
		array = new int[N];
	}
	catch (...)
	{
		cout << "Error!" << endl;
		return 0;
	}
}

void initarray(int *array, int N)
{
	for (int i = 0; i < N; i++)
	{
		*(i + array) = rand() % 11;
	}
}

void printarray(int *array, int N)
{
	for (int i = 0; i < N; i++)
		cout << *(i + array) << " ";
}

void arrInc(int* array, int N, int k)
{
	for (int i = 0; i < N - 1; i++)
	{
		if (*array > *(array + 1))
		{
			for (int j = i; j > k; j--)
				if (*(array - k) > *(array - k + 1))
				{
					swap(*(array - k), *(array - k + 1));
				}
		}

	}
}

void arrDel(int *a, int N)
{
	delete[N] a;
}

int main()
{
	int N;
	cout << "Enter the number of elements in array:" << endl;
	cin >> N;
	int* array = arrMem(N);
	initarray(array, N);
	printarray(array, N);
	int k;
	cout << "Enter the number of position: " << endl;
	cin >> k;
	int l = k - 1;
	int i = N - 1;
	while (i > l)
	{
		for (int j = l; j < N - 1; j++)
		{
			if (*(array + j) > *(array + j + 1))
				swap(*(array + j), *(array + j + 1));
		}
		i--;
	}
	printarray(array, N);
	arrDel(array, N);
	system("pause");
}