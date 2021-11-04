//Lab_06_4_Rec.cpp
// Вольвенко Іван
// Лабораторна робота № 6.4
// Опрацювання та впорядкування одновимірних динамічних масивів
// Варіант 13

#include <iostream>
#include <cmath>
#include <time.h>

using namespace std;

void Create(int mas[], const int n, const int Low, const int High, int i)
{
	mas[i] = Low + rand() % (High - Low + 1);
	if (i < n - 1)
		Create(mas, n, Low, High, i + 1);
}

void Print(int mas[], const int n, int i)
{
	cout << mas[i] << " ";
	if (i < n - 1)
		Print(mas, n, i + 1);
}

int Kil(int mas[], const int n, const int A, const int B, int i)
{
	if (mas[i] >= A && mas[i] <= B)
	{
		if (i < n)
			return 1 + Kil(mas, n, A, B, i + 1);
		else
			return 0;
	}
	else
		return Kil(mas, n, A, B, i + 1);
}

int MaxInd(int mas[], const int n, int i, int max, int Maxind)
{
	if (mas[i] > max)
	{
		max = mas[i];
		Maxind = i;
	}
	if (i < n - 1)
		return MaxInd(mas, n, i + 1, max, Maxind);
	else
		return Maxind;
}

int Sum(int mas[], const int n, int i)
{
	if (i > MaxInd(mas, n, 1, mas[0], 0))
	{
		if (i < n)
			return mas[i] + Sum(mas, n, i + 1);
		else
			return 0;
	}
	else
		return Sum(mas, n, i + 1);
}

void Sort(int mas[], const int n, int i, int j, int &k)
{
	if (abs(mas[j]) < abs(mas[j + 1]))
	{
		int tmp = mas[j];
		mas[j] = mas[j + 1];
		mas[j + 1] = tmp;
		k = 1;
	}
	if (j < n - i - 1)
		Sort(mas, n, i, j + 1, k);
	if (k == 0)
		return;
	if (i < n - 1)
	{
		k = 0;
		Sort(mas, n, i + 1, 0, k);
	}
}

int main()
{
	srand((unsigned)time(NULL));

	int n, A, B;

	cout << "n = "; cin >> n;

	int* a = new int[n];
	int k = 0;
	int Low = -5;
	int High = 5;

	cout << "A = "; cin >> A;
	cout << "B = "; cin >> B;

	Create(a, n, Low, High, 0);

	cout << "a[ ";
	Print(a, n, 0);
	cout << "]" << endl;

	cout << "k = " << Kil(a, n, A, B, 0) << endl;
	cout << "Sum = " << Sum(a, n, 0) << endl;
	
	Sort(a, n, 1, 0, k);

	cout << "a[ ";
	Print(a, n, 0);
	cout << "]" << endl;

	return 0;
}