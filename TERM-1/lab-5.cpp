#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    int m,n;
    cout << "Enter sizes: ";
        cin >> m >> n;

    double **a;
    a = new double*[m];
    cout << "Enter matrix:" << endl;
    for(int i = 0; i < m; i++)
    {
        a[i] = new double[n];
        for(int j = 0; j < n; j++)
            cin >> a[i][j];
    }

    for(int i = 0; i < m-1; i++)
        for(int j = i+1; j < m; j++)
            if(a[i][0] > a[j][0])
            {
                double *utemp = a[i];
                a[i] = a[j];
                a[j] = utemp;
            }

    cout << endl;
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
            cout << setw(3) << a[i][j];
        cout << endl;
    }

    for(int i = 0; i < m; i++)
        delete []a[i];
    delete []a;
    a = NULL;

    return 0;
}
