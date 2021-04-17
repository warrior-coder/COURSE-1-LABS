#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

typedef double (*ufun)(double, double, int&);

void tabl(double, double, double, double, ufun);
double Y(double, double, int&);
double S(double, double, int&);

int main()
{
	double a, b, h, eps;
	/*a = -0.5;
	b = 0.5;
	h = 0.2;
	eps = 1e-5;*/

	cout << "Enter a: ";
		cin >> a;
	cout << "Enter b: ";
		cin >> b;
	cout << "Enter h: ";
		cin >> h;
	cout << "Enter eps: ";
		cin >> eps;
	cout << endl;

	cout << setw(8) << "x" << setw(15) << "Y(x)" << setw(10) << "k" << endl;
	tabl(a, b, h, eps, Y);
	cout << endl;

	cout << setw(8) << "x" << setw(15) << "S(x)" << setw(10) << "k" << endl;
	tabl(a, b, h, eps, S);
	cout << endl;

	return 0;
}

void tabl(double a, double b, double h, double eps, ufun fun)
{
	int k;
	double sum;

	for(double x = a; x < b + h/2; x+=h)
	{
		k = 1;
		sum = fun(x, eps, k);
		cout << setw(8) << x << setw(15) << sum << setw(10) << k << endl;
	}

	return;
}

double Y(double x, double eps, int& k)
{
	return log( (1+x) / (1-x) ) / 4 - atan(x) / 2;
}

double S(double x, double eps, int& k)
{
	double sum, p, c;

	p = pow(x, 3);
	c = p / 3;
	sum = c;
	while (fabs(c) > eps)
	{
		k++;
		p *= pow(x, 4);
		c = p / (4*k - 1);
		sum += c;
	}

	return sum;
}
