//Элементы целочисленного массива А(N), значения которых оказались простыми числами, расположить в порядке возрастания, не нарушая порядка следования других элементов.

#include <iostream>
using namespace std;

bool isPrime(int num)
{
	for (int i = 2; i <= (sqrt(num)); ++i)
	{
		if (num % i == 0)
			return false;
	}
	return true;
}

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

void arrDel(int *a, int N)
{
	delete[N] a;
}

void initarray(int *array, int N)
{
	for (int i = 0; i < N; i++)
	{
		*(i + array) = 9 - i;
	}
}

void printarray(int *array, int N)
{
	for (int i = 0; i < N; i++)
		cout << *(i + array) << " ";
}

int distCount(int x, int y, int a, int b, int c)
{
	int dist;
	dist = abs(a*x + b * y + c) / sqrt(a*a + b * b);
	return dist;
}

void sortDist(int *array, int *arr, int N, int a, int b, int c)
{
	for (int *w = array, *v = arr; w < array + N; w++, v++)
	{
		for (int *p = w, *q = v; p < array + N; p++, q++)
		{
			if (distCount(*w, *v, a, b, c) > distCount(*p, *q, a, b, c))
			{
				swap(*p, *w);
				swap(*q, *v);
			}
		}
	}
}

int main()
{
	int N;
	cout << "Enter the number of elements in array:" << endl;
	cin >> N;
	int a, b, c;
	cin >> a;
	cin >> b;
	cin >> c;
	int* array = arrMem(N);
	int* arr = arrMem(N);
	initarray(array, N);
	initarray(arr, N);
	sortDist(array, arr, N, a, b, c);
	arrDel(array, N);
	arrDel(arr, N);
	system("pause");
}