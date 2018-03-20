//Определить, сколько в строке 4-символьных слов. Вывести такие слова на экран. Заменить последнее такое слово на заданную подстроку.

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

const int N = 4;

void initmemory(char *&string, int n)
{

	try
	{
		string = new char[n];
	}
	catch (...)
	{
		exit(1);
	}
}

void deletememory(char* string)
{
	delete[]string;
}

void printstring(char* s)
{
	cout << s << endl;
}

void initstring(char* s)
{
	//int n;
	//cout << "Insert the number of letters:" << endl;
	//cin >> n;
	cin.getline(s, 255);
}


void strchange(char* s, char* str)
{
	char *a = s;
	int wordcount = 0;
	int n = 0, count = 0, strnum = 0;
	while (s[n] != '\0')
	{
		if ((count == N) && (s[n] == 32))
		{
			wordcount++;
			a = &s[n - N];
			count = 0;
			cout << "Word with " << N << " letters:" << endl;
			for (int j = n - N; j < n; j++)
			{
				cout << s[j];
			}
			cout << endl;
			strnum++;
		}
		count++;
		if (s[n] == 32)
			count = 0;
		n++;
	}
	strcpy(a, str);
	cout << "Number of words:" << wordcount << endl;
}

int main()
{
	int M = 1000;	
	char *s = nullptr;
	initmemory(s, M);
	char *str = nullptr;
	initmemory(str, M);
	initstring(s);
	initstring(str);
	strchange(s, str);
	printstring(s);
	system("pause");
}