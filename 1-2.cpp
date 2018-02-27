//Даны точки плоскости своими координатами в виде двух одномерных массивов. Точки плоскости рассортировать по возрастанию расстояния до прямой ax + by + c = 0.

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
		*(i + array) = rand() % 200 - 100;
	}
}

void printarray(int *array, int N)
{
	for (int i = 0; i < N; i++)
		cout << *(i + array) << " ";
}

void sortArray(int* array, int N)
{
	int i = N - 1;
	int n = 0;
	int t = 1;
	while (t)
	{
		t = 0;
		for (i = N - 1; i > 0; i--)
		{
			if (*(array + i - 1) >= 0 && *(array + i) <= 0)
			{
				swap(*(array + i - 1), *(array + i));
				t++;
			}
		}
	}
	for (int m = 0; m < N - 1; m++)
	{
		if (*(array + m) < 0)
			n++;
	}
	t = 1;
	while (t)
	{
		t = 0;
		for (int k = 0; k < n - 1; k++)
		{
			if (*(array + k) < *(array + k + 1))
			{
				swap(*(array + k), *(array + k + 1));
				t++;
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
	cout << endl;
	sortArray(array, N);
	printarray(array, N);
	arrDel(array, N);
	system("pause");
}