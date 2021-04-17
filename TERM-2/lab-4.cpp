#include <iostream>

using namespace std;

double totalGeese(int);
double totalGeese_NOREC(int);

int main()
{
    int rest_number;
    char chr = 'y';
    
    while (chr == 'y')
    {
        cout << "Enter number of restorasnts: ";
            cin >> rest_number;
        
        cout << "1 - recursion, 2 - without: ";
            cin >> chr;
    
        if (chr == '1') cout << "Total number: " << totalGeese(rest_number) << endl;
        else cout << "Total number: " << totalGeese_NOREC(rest_number) << endl;
	    
	    cout << "Restart? y/n ";
	        cin >> chr;
	    
    }
    
	return 0;
}

double totalGeese(int r)
{
    if (r <= 0) return 0;
    else return (totalGeese(r-1) + 0.5) * 2;
}

double totalGeese_NOREC(int r)
{
    double g = 0;
    while (r > 0)
    {
        g = (g + 0.5) * 2;
        r--;
    }
    return g;
}