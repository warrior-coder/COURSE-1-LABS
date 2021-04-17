#include <iostream>
#include <stdio.h>
#include <io.h>

using namespace std;

FILE* fl;

struct dinfo
{
	int code;
	int amount;
	int month;
} detail, * DETAILS;

int n = 0;
char flname[30];
bool no_fl_name = true;

int menu();				// MENU
void fl_add();			// Enter data to file
void fl_read();			// Read data from file
void search_con();		// Search details in console
void search_fl();		// Search details in file
int search();			// Search menu
void sort_quick();		// Quick Sort
int search_linear(int); // Linear Search
int search_binary(int); // Binary Search

int main()
{
	while (true)
	{
		switch (menu())
		{
		case 1: fl_add(); break;
		case 2: fl_read(); break;
		case 3: search_con(); break;
		case 4: search_fl(); break;
		case 5: return 0; break;
		default: cout << "Enter correct!" << endl;
		}

		cout << endl;
		system("pause");
		system("cls");
	}
}

int menu()
{
	cout << "1. Enter data to file" << endl;
	cout << "2. Read data from file" << endl;
	cout << "3. Search details in console" << endl;
	cout << "4. Search details in file" << endl;
	cout << "5. Exit" << endl;
	cout << "--------------------------" << endl;

	int k;
	cin >> k;
	cout << endl;

	return k;
}

char* fl_name_get()
{
	if (no_fl_name)
	{
		cout << "Enter file name: ";
		cin >> flname;
		no_fl_name = false;
	}

	return flname;
}

void fl_add()
{
	fopen_s(&fl, fl_name_get(), "ab");
	if (fl == NULL)
	{
		fopen_s(&fl, fl_name_get(), "wb");
		if (fl == NULL)
		{
			cout << "FILE CREATE ERROR" << endl;
			return;
		}
	}

	char chr;

	do {
		cout << "Enter detail code: "; cin >> detail.code;
		cout << "Enter detail amount: "; cin >> detail.amount;
		cout << "Enter detail month: "; cin >> detail.month;

		fwrite(&detail, sizeof(dinfo), 1, fl);

		cout << endl << "Enter more? (y/n) "; cin >> chr;
	} while (chr == 'y');

	fclose(fl);
}

void fl_read()
{
	fopen_s(&fl, fl_name_get(), "rb");
	if (fl == NULL)
	{
		cout << "FILE READ ERROR" << endl;
		return;
	}

	n = _filelength(_fileno(fl)) / sizeof(dinfo);
	DETAILS = new dinfo[n];
	fread(DETAILS, sizeof(dinfo), n, fl);

	for (int i = 0; i < n; i++)
	{
		cout << "Code - " << DETAILS[i].code << " Amount - " << DETAILS[i].amount << " Month - " << DETAILS[i].month << endl;
	}

	fclose(fl);
}

void search_con()
{
	fopen_s(&fl, fl_name_get(), "rb");
	if (fl == NULL)
	{
		cout << "FILE READ ERROR" << endl;
		return;
	}

	n = _filelength(_fileno(fl)) / sizeof(dinfo);
	DETAILS = new dinfo[n];
	fread(DETAILS, sizeof(dinfo), n, fl);

	int i = search();

	if (i != -1)
		cout << "Code - " << DETAILS[i].code << " Amount - " << DETAILS[i].amount << " Month - " << DETAILS[i].month << endl;
	else
		cout << "Detail not found!" << endl;

	fclose(fl);
}

void search_fl()
{
	fopen_s(&fl, fl_name_get(), "rb");
	if (fl == NULL)
	{
		cout << "FILE OPEN ERROR" << endl;
		return;
	}

	char flname2[20];
	cout << "Enter result file name: ";
	cin >> flname2;

	FILE* fl2;
	fopen_s(&fl2, flname2, "wt");
	if (fl2 == NULL)
	{
		cout << "FILE CREATE ERROR" << endl;
		return;
	}

	n = _filelength(_fileno(fl)) / sizeof(dinfo);
	DETAILS = new dinfo[n];
	fread(DETAILS, sizeof(dinfo), n, fl);

	int i = search();

	if (i != -1)
		fprintf(fl2, "%s%d %s%d %s%d\n", "Code - ", DETAILS[i].code, "Amount - ", DETAILS[i].amount, "Month - ", DETAILS[i].month);
	else
		fprintf(fl2, "%s", "Detail no found!");

	cout << "Done" << endl;

	_fcloseall();
}

int search()
{
	sort_quick();

	int x;
	cout << "Enter detail code: "; cin >> x;

	cout << "1 - Linear Search" << endl;
	cout << "2 - Binary Search" << endl;
	cout << "-----------------" << endl;

	int k;
	while (true)
	{
		cin >> k;
		switch (k)
		{
		case 1:
			return search_linear(x);
			break;
		case 2:
			return search_binary(x);
			break;
		default:
			cout << "Enter correct!" << endl;
			break;
		}
	}
}

void sort_quick()
{
	struct St
	{
		int L;
		int R;
		int k;
	} stack[10];


	int i, j, left, right, k;
	dinfo temp, x;

	k = 0;
	stack[k].L = 0;
	stack[k].R = n - 1;

	while (k != -1)
	{
		left = stack[k].L;
		right = stack[k].R;
		k--;

		while (left < right)
		{
			i = left;
			j = right;
			x = DETAILS[(i + j) / 2];

			while (i <= j)
			{
				while (DETAILS[i].code < x.code) i++;
				while (DETAILS[j].code > x.code) j--;

				if (i <= j)
				{
					temp = DETAILS[i];
					DETAILS[i] = DETAILS[j];
					DETAILS[j] = temp;
					i++;
					j--;
				}
			}

			if ((j - left) < (right - i))
			{
				if (i < right)
				{
					k++;
					stack[k].L = i;
					stack[k].R = right;
				}
				right = j;
			}
			else
			{
				if (left < j)
				{
					k++;
					stack[k].L = left;
					stack[k].R = j;
				}
				left = i;
			}
		}
	}
}

int search_linear(int x)
{
	for (int i = 0; i < n; i++)
		if (DETAILS[i].code == x) return i;

	return -1;
}

int search_binary(int x)
{
	int i = 0, j = n - 1, m;

	while (i < j)
	{
		m = (i + j) / 2;
		if (x > DETAILS[m].code) i = m + 1;
		else j = m;
	}

	if (DETAILS[i].code == x) return i;
	else return -1;
}