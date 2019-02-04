#include "rand.h"
#include <vector>
#include <algorithm>

static int next1 = 0;
static int next2 = 0;
static int next3 = 0, next3_0 = 7, next3_1 = 4;
static int next4 = 1;

///////////////////////////////////////////////
int generate1()
{
	const long long a = 65539, c = 12345;
	next1 = (a*next1 + c) % RAND_MAX;
	return next1;
}

double rand1()
{
	return (double)generate1() / RAND_MAX;
}

//////////////////////////////////////////////

int generate2()
{
	const long long a = 65533, c = 12345, d = 65539;
	next2 = (d*next2*next2 + a*next2 + c) % RAND_MAX;
	return next2;
}

double rand2()
{
	return (double)generate2() / RAND_MAX;
}

//////////////////////////////////////////

int generate3()
{
	next3 = (next3_1 + next3_0) % RAND_MAX;
	next3_0 = next3_1;
	next3_1 = next3;
	return next3;
}

double rand3()
{
	return (double)generate3() / RAND_MAX;
}

//////////////////////////////////////////

int generate4()
{
	const long long a = 1, c = 6, p = 32777;
	int i;
	for (i = 0; i < p; ++i)
	{
		if (((i * next4) % p) == 1) break;
	}
	next4 = (i*a + c) % RAND_MAX;
	return next4;
}

double rand4()
{
	return (double)generate4() / RAND_MAX;
}

/////////////////////////////////////////

double rand5()
{
	double z = 0, x = rand2(), y = rand3();
	z = x - y;
	while (z < 0) z++;
	return z;
}

/////////////////////////////////////////

double rand6()
{
	double sum = 0, x = 0;
	for (int i = 0; i < 12; ++i)
	{
		sum += rand5();
	}
	int m = 0, s = 1;

	x = m + (sum - 6)*s;

	return x;
}

////////////////////////////////////////

double rand7()
{
	double u1 = 0, u2 = 0, v1 = 0, v2 = 0, s = 0, x1 = 0, x2 = 0;
	while (1)
	{
		u1 = rand5(); u2 = rand5();
		v1 = 2 * u1 - 1;
		v2 = 2 * u2 - 1;
		s = v1*v1 + v2*v2;
		if (s < 1)
		{
			x1 = v1*sqrt((-2)*log(s) / s);
			x2 = v2*sqrt((-2)*log(s) / s);
			if (rand1() > 0.5) return x1;
			return x2;
		}
	}
}

///////////////////////////////////////////

double rand8()
{
	double x = 0, u = 0, v = 0;
	while (1)
	{
		while (u == 0) u = rand5();
		v = rand5();
		x = sqrt(8 / exp(1))*(v - 0.5) / u;
		if (x*x <= (5 - 4 * exp(1 / 4)*u)) return x;
		if (x*x < (4 * exp(-1.35) / u + 1.4))
		{
			if (x*x <= (-4 * log(u))) return x;
		}
	}
}

//////////////////////////////////////////

double rand9()
{
	double u = 0, x = 0, M=-43;
	u = rand5();
	x = M*log(u);
	return x;
}

/////////////////////////////////////////

double rand10()
{
	double u = 0, x = 0, y = 0, v = 0, pi= 3.14159265358979323846;
	const long long a = 37;
	while (1)
	{
		u = rand5();
		y = tan(pi*u);
		x = sqrt(2 * a - 1)*y + a - 1;
		if (x > 0)
		{
			v = rand5();
			if (v > ((1 + y*y)*exp((a - 1)*log(x / (a - 1)) - sqrt(2 * a - 1)*y))) return x;
		}
	}
}