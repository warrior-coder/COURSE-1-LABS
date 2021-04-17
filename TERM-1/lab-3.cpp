#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main()
{
    double a,b,h, x,y, s,p;
    int n;
    a = 0.1;
    b = 1;
    n = 120;
    h = (b - a) / 10;
    x = a;
    cout << setw(5) << 'x' << setw(12) << 'y' << setw(15) << 's' << endl;
    while(x < b + h/2)
    {
        s = p = x*x*x / 3;

        for(int i = 2; i <=n; i++)
        {
            p *= -x*x * (2*(i-1) - 1) / (2*i + 1);
            s += p;
        }
        y = ((1 + x*x) * atan(x) - x) / 2;
        cout << setw(6) << x << setw(15) << y << setw(15) << s << endl;
        x += h;
    }
    return 0;
}






