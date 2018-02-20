//В массиве размера N, заполненного случ.числами от 0 до 10, определить максимальную длину последовательности равных элементов.

#include <iostream>
using namespace std;

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


int numinsequence(int *array, int N)
{
	int num = 0;
	int maxnum = 1;
	for (int *a = array; a < array + N; a++)
	{	
		if (*a == *(a + 1))
			num++;
		else
		{
			if (num > maxnum)
			{
				maxnum = num + 1;
				num = 0;
				break;
			}		}
	}
	cout << "Maximum number: " << maxnum << endl;
	return maxnum;
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
	numinsequence(array, N);
	system("pause");
}