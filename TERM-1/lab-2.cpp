#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	double x,y,a,f,s;
	int k;
	cout << "Enter x y:" << endl;
	cin >> x >> y;
	cout << "Enter f: 1 - sh(x),  2 - x^2,  3 - exp(x)" << endl;
	cin >> k;

	switch(k)
	{
	case 1 :
		f = sinh(x);
	break;
	case 2 :
		f = x*x;
	break;
	case 3 :
		f = exp(x);
	break;
	default :
		cout << "f not selected!" << endl;
		system("pause");
        return 1;
	}

	a = x * y;
	if(a > 1 && a < 10)
	{
		s = exp(f);
	}
	else if(a > 12 && a < 40)
	{
		s = cbrt(fabs(f + 4*y));
	}
	else
	{
		s = y * f*f;
	}
	cout << "Result s = " << s << endl;

	system("pause");
	return 0;
}
