#include <iostream>

using namespace std;

struct winfo
{
	char surname[20];
	int birth_year;
	int apply_year;
};

void In(winfo*, int);
void Out(winfo*, int);
void Poisk(winfo*, int, int, int);

int main()
{
	int n;
	cout << "Enter number of workers: ";
	cin >> n;

	winfo *worker = new winfo[n];

	In(worker, n);
	Out(worker, n);

	int year, cur_year;
	cout << endl << "Enter year: ";
	cin >> year;
	cout << "Enter current year: ";
	cin >> cur_year;

	Poisk(worker, n, year, cur_year);

	return 0;
}

void In(winfo* worker, int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << endl << "Enter surname: "; cin >> (worker+i)->surname;
		cout << "Enter birth year: "; cin >> (worker+i)->birth_year;
		cout << "Enter apply year: "; cin >> (worker+i)->apply_year;
	}
}

void Out(winfo* worker, int n)
{
	cout << endl << "Workers:" << endl;
	for (int i = 0; i < n; i++)
		cout << (worker+i)->surname << ": " << "birth year - " << (worker+i)->birth_year << ", apply year - " << (worker+i)->apply_year << endl;
}

void Poisk(winfo* worker, int n, int year, int cur_year)
{
	int age = 0;

	for (int i = 0; i < n; i++)
	{
		if ((worker+i)->birth_year < year)
		{
			cout << (worker+i)->surname << ": " << "birth year - " << (worker+i)->birth_year << ", apply year - " << (worker+i)->apply_year << endl;
			age += cur_year - (worker+i)->birth_year;
		}
	}

	if (age)
		cout << "Middle age: " << age/n << endl;
	else
		cout << "No workers" << endl;
}
