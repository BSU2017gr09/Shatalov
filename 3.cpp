#include <iostream>
using namespace std;

int** givememory(int N, int M)
{
	int* *tmp = new int*[N];
	for (int i = 0; i < N; i++)
		tmp[i] = new int[M];
	return tmp;
}

void printarray(int* *p, int N, int M)
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
			cout << p[i][j] << " ";
		cout << endl;
	}
}

void initarray(int* *p, int N, int M)
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
			p[i][j] = rand() % 100 - 50;
	}
}

void ifpos(int* *p, int N, int M)
{
	int* posnum;
	try
	{
		posnum = new int[N];
	}
	catch (...)
	{
		exit(1);
	}
	int count = 0;
	int i = 0;
	while (i < N)
	{
		for (int j = 0; j < M; j++)
		{
			if (p[i][j] > 0)
			{
				count++;
			}
		}
		posnum[i] = count;
		count = 0;
		i++;
	}
	for (int t = 0; t < N; t++)
	{
		cout << "COUNT: " << posnum[t] << endl;
	}
	int checker = 1;
	while (checker != 0)
	{
		checker = 0;
		for (int k = 0; k < N - 1; k++)
		{
			if (posnum[k] < posnum[k + 1])
			{
				swap(p[k], p[k + 1]);
				swap(posnum[k], posnum[k + 1]);
				checker++;
			}
		}

	}
}

int numofpos()
{
	int num = 0;
	return 0;
}

int main()
{
	int N, M;
	cin >> N >> M;
	int* *p = nullptr;
	p = givememory(N, M);
	initarray(p, N, M);
	printarray(p, N, M);
	cout << "-----------------------------" << endl;
	ifpos(p, N, M);
	printarray(p, N, M);
	system("pause");
}