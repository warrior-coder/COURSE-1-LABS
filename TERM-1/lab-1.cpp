#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	double x,y,z,a,b,c,d,s;
    	cout << "Enter x y z:" << endl;
	cin >> x >> y >> z;

	a = 5 * atan(x);
	b = 1 / 4. * acos(x);
    	c = x + 3 * fabs(x-y) + x*x;
    	d = fabs(x-y) * z + x*x;

	s = a - b * c / d;

	cout << "Result s = " << s << endl;
	system("pause");
	return 0;
}

