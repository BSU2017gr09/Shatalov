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

void sortArray(int *array, int N)
{
	int t = 1;
	while (t)
	{
		t = 0;
		for (int *i = array; i < array + N; i++)
		{
			if (isPrime(*i))
			{
				for (int *j = i; j < array + N - 1; j++)
				{
					if (isPrime(*(j + 1)))
					{
						if (*i > *(j + 1))
							swap(*i, *(j + 1));
					}
				}
			}
		}
	}
	t = 1;
	while (t)
	{
		t = 0;
		for (int n = 0; n < N; n++)
		{
			if (*(array + n) < *(array + n + 1) && (isPrime(*(array + n) != 1) && (isPrime(*(array + n + 1)) != 1)))
			{
				swap(*(array + n), *(array + n + 1));
				t++;
			}
		}
	}
	for (int n = 0; n < N; n++)
	{
		if ((*(array + n) == 0) && (*(array + n + 1) == 1))
			swap(*(array + n), *(array + n + 1));
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
	//sortArray(array, N);
	int t = 1;
	while (t)
	{
		t = 0;
		for (int *i = array; i < array + N; i++)
		{
			if (isPrime(*i))
			{
				for (int *j = i; j < array + N - 1; j++)
				{
					if (isPrime(*(j + 1)))
					{
						if (*i > *(j + 1))
							swap(*i, *(j + 1));
						printarray(array, N);
						cout << endl;
					}
				}
			}
		}
	}
	t = 1;
	while (t)
	{
		t = 0;
		for (int n = 0; n < N; n++)
		{
			if (*(array + n) < *(array + n + 1) && (isPrime(*(array + n) != 1) && (isPrime(*(array + n + 1)) != 1)))
			{
				swap(*(array + n), *(array + n + 1));
				printarray(array, N);
				cout << endl;
				t++;
			}
		}
	}
	for (int n = 0; n < N; n++)
	{
		if ((*(array + n) == 0) && (*(array + n + 1) == 1))
			swap(*(array + n), *(array + n + 1));
	}
	cout << endl;
	printarray(array, N);
	arrDel(array, N);
	system("pause");
}