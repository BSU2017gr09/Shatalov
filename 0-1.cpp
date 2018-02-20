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

int numofrepeat(int *array, int N)
{
	int i = 0;
	int num = 0;
	int count = 0;
	for (i = 0; i < N; i++)
	{
		for (int j = i + 1; j < N; j++)
		{
			if (*(i + array) == *(j + array))
				count++;
		}
		if (count >= 1)
			num++;
		if (count >= 2)
			num--;
		count = 0;
	}
	cout << endl;
	cout << "Number: " << num << endl;
	return num;
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
	numofrepeat(array, N);
	system("pause");
}