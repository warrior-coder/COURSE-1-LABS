#include <iostream>

using namespace std;

int main()
{
    int k,n;
    double a[30];
    cout << "Enter array size: ";
        cin >> k;
    cout << "Enter Array: ";
    for(int i = 0; i < k; i++)
        cin >> a[i];
    cout << "Enter n: ";
        cin >> n;

    for(int i = 0; i < n; i++)
    {
        double temp = a[k-1];
        for(int j = k-1; j > 0; j--)
            a[j] = a[j-1];
        a[0] = temp;
    }

    for(int i = 0; i < k; i++)
        cout << a[i];

    return 0;
}
