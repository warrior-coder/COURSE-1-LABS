#include <iostream>
#include <stdlib.h>

using namespace std;

void In(int*, int);
void Out(int*, int);
bool Poisk(int* a, int n, int*, int&);

int main()
{
	int n, p, s;
	cout << "Enter array size: ";
		cin >> n;

	int* a = new int[n];

	In(a, n);
	Out(a, n);

	if (Poisk(a, n, &p, s))
	{
		cout << endl << "Proizv: " << p << endl;
		cout << "Sum: " << s << endl;
	}
	else
		cout << endl << "No elements" << endl;

	delete[] a;
	a = nullptr;

	return 0;
}

void In(int* a, int n)
{
	char chr;
	cout << "1 - Keybord, 2 - Random: ";
		cin >> chr;

	if (chr == '1')
	{
		cout << "Enter array: ";
		for (int i = 0; i < n; i++)
			cin >> *(a+i);
	}
	else
	{
		for (int i = 0; i < n; i++)
			*(a+i) = rand() % 21 - 10;
	}
}

void Out(int* a, int n)
{
	cout << endl << "Array:";
	for (int i = 0; i < n; i++)
	{
		cout << ' ' << *(a+i);
	}
}
bool Poisk(int* a, int n, int* p, int& s)
{
	int i1, i2;
	i1 = i2 = -1;

	for(int i = 0; i < n; i++)
		if (*(a+i) < 0)
		{
			i1 = i;
			break;
		}
	for (int i = n-1; i > -1; i--)
		if (*(a+i) < 0)
		{ i2 = i;
			break;
		}

	if(i2-i1 < 2)
	{
		return false;
	}
	else
	{
		*p = 1;
		s = 0;
		for(int i = i1+1; i < i2; i++)
		{
			*p *= *(a+i);
			s += *(a+i);
		}
		return true;
	}
}