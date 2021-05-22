#include <iostream>
#include <stdio.h>

using namespace std;

struct Flight_Info
{
    char dest[20];
    int number;
    char time[10];
} *flights;
int n = 0;

struct Hash_Table_Double
{
    Flight_Info** table = nullptr;
    int size = 0;

    void create(int m)
    {
        table = new Flight_Info*[m];
        for (int i = 0; i < m; i++) table[i] = nullptr;
        size = m;
    }

    void add(Flight_Info* flight)
    {
        int i = flight->number % size;
        int attempt = 0; // check

        if (table[i])
        {
            int j = (size-1) - (flight->number % (size-1));

            while (table[i])
            {
                i -= j;
                if (i < 0) i += size;
                attempt++; if (attempt > size) return; // if all elements checked
            }
        }
        table[i] = flight;
    }

    Flight_Info* search(int number)
    {
        int i = number % size;
        if (table[i] && table[i]->number == number) return table[i];

        int attempt = 0; // check
        int j = (size-1) - (number % (size-1));
        while (table[i])
        {
            if (table[i]->number == number) return table[i];
            i -= j;
            if (i < 0) i += size;
            attempt++; if (attempt > size) return nullptr; // if all elements checked
        }
        return nullptr;
    }

    void show()
    {
        for (int i = 0; i < size; i++)
        {
            if (table[i]) cout << "[" << i << "] " << table[i]->number << endl;
            else cout << "[" << i << "]" << endl;
        }
    }

    void clear()
    {
        if (table)
        {
            delete[] table;
            table = nullptr;
        }
    }
} H;

void read_data_from_file();
void print_data();
void create_hash_table();
void print_hash_table();
void search_in_hash_table();

int main()
{
    while (true)
    {
        cout << "+--------------------------+" << endl;
        cout << "| 1 - Read data from file  |" << endl;
        cout << "| 2 - Print data           |" << endl;
        cout << "| 3 - Create hash table    |" << endl;
        cout << "| 4 - Print hash table     |" << endl;
        cout << "| 5 - Search in hash table |" << endl;
        cout << "| 7 - Exit                 |" << endl;
        cout << "+--------------------------+" << endl;

        int menu; cin >> menu;
        cout << endl;

        switch (menu)
        {
            case 1: read_data_from_file(); break;
            case 2: print_data(); break; 
            case 3: create_hash_table(); break;
            case 4: print_hash_table(); break;
            case 5: search_in_hash_table(); break;
            default: H.clear(); return 0;
        }

        cout << endl;
        system("pause");
        system("cls");
    }
}

void read_data_from_file()
{
    if (n > 0)
    {
        cout << "Data already exists." << endl;
        return;
    }

    char fl_name[20];
    cout << "Enter file name: "; cin >> fl_name;
    FILE* fl;
    fopen_s(&fl, fl_name, "r");

    if (fl)
    {
        fscanf_s(fl, "%d", &n);
        flights = new Flight_Info[n];

        for (int i = 0; i < n; i++)
        {
            fscanf_s(fl, "%s", flights[i].dest, 20);
            fscanf_s(fl, "%d", &flights[i].number);
            fscanf_s(fl, "%s", flights[i].time, 10);
        }

        cout << "Data readed." << endl;
    }
    else cout << "File open error." << endl;
}

void print_data()
{
    if (n > 0)
    {
        for (int i = 0; i < n; i++)
        {
            cout << "Number: " << flights[i].number << ", Dest: " << flights[i].dest << ", Time: " << flights[i].time << endl;
        }
    }
    else cout << "No data." << endl;
}

void create_hash_table()
{
    if (H.size > 0)
    {
        cout << "Hash table already exists" << endl;
        return;
    }

    int m;
    cout << "Enter table size: "; cin >> m;

    if (m > 0 && m >= n)
    {
        H.create(m);
        for (int i = 0; i < n; i++) H.add(&flights[i]);
        cout << "Hash table created." << endl;
    }
    else cout << "Create eror." << endl;
}

void print_hash_table()
{
    if (H.size == 0)
    {
        cout << "Hash table not exist." << endl;
        return;
    }
    
    cout << "Hash table:" << endl;
    H.show();
}


void search_in_hash_table()
{
    if (H.size == 0)
    {
        cout << "Hash table not exist." << endl;
        return;
    }
    
    int number;
    cout << "Enter flight number: "; cin >> number;

    Flight_Info* ptr = H.search(number);
    if (ptr) cout << "Number: " << ptr->number << ", Dest: " << ptr->dest << ", Time: " << ptr->time << endl;
    else cout << "Flight not found." << endl;
}

/* DATA TO READ
8
Los-Angeles
12
12:00

New-York
43
09:45

Horky
32
20:47

Tokyo
17
23:15

Minsk
77
21:09

Moscow
109
17:00

Kiev
41
02:00

Paris
117
06:30
*/