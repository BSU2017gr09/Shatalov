//Массив чисел размера N проинициализировать случайными числами из промежутка от -N до N. Написать функцию циклического сдвига элементов массива вправо на k элементов.

#include <iostream>
using namespace std;

void initarray(int *array, int N)
{
	for (int i = 0; i < N; i++)
	{
		*(i + array) = rand() %(2*N) - N;
	}
}

void printarray(int *array, int N)
{
	for (int i = 0; i < N; i++)
		cout << *(i + array) << " ";
}

void elemmove(int *array, int N, int k)
{
	int *a = array;
	int n = 0;
	int *b = array + N - 1;
	while (n < N / 2)
	{
		swap(*b, *a);
		n++;
		a++;
		b--;
	}
	b = array + k - 1;
	a = array;
	n = 0;
	while (n < k / 2)
	{
		swap(*b, *a);
		n++;
		a++;
		b--;
	}
	b = array + N - 1;
	a = array + k;
	n = 0;
	while (n < (N - k) / 2)
	{
		swap(*b, *a);
		n++;
		a++;
		b--;
	}
}

int main()
{
	int N;
	cout << "Enter the number of elements in array:" << endl;
	cin >> N;
	int *array;
	try
	{
		array = new int[N];
	}
	catch (...)
	{
		cout << "Error!" << endl;
		return 1;
	}
	initarray(array, N);
	printarray(array, N);
	int k;
	cout << "Number of move: " << endl;
	cin >> k;
	elemmove(array, N, k);
	printarray(array, N);
	delete []array;
	system("pause");
}