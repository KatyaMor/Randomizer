
#include "hist.h"

using namespace std;

void histogram(function<double()> &f, double &lower, double &higher, int &n)
{
	vector<int> count(n);
	unsigned int Nmax = 10000;
	double xn = 0;
	double sum = 0;

	for (unsigned int i = 0; i < Nmax; i++)
	{
		xn = f();
		for (int k = 0; k < n; k++)
		{
			if (xn >= lower + k*(higher - lower) / n && xn < lower + (k + 1)*(higher - lower) / n)
				++count[k];
		}
	}
	
	for (int k = 0; k < n; k++)
	{
		cout << setprecision(1) << fixed << "[" << lower + k*(higher - lower) / n << ", " << lower + (k + 1)*(higher - lower) / n << "]" << "  -  " << setprecision(4) << fixed << (double)count[k]/Nmax << endl;
		sum += (double)count[k] / Nmax;
	}
	cout << sum << endl;
}