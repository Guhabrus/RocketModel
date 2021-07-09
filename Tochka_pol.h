#pragma once
#include <fstream>
#define M_PI 3.14159265358979
using namespace std;

class Tochka_pol
{
public:
	double t, r, fi, v, theta, m;
	void vivod(ofstream *f);
	Tochka_pol dTochka_pol_dt(LA);
	void print(ofstream *fv, ofstream *ft );



};



Tochka_pol operator*(Tochka_pol a, double b)
{
	Tochka_pol c;
	c.t = a.t*b;
	c.r = a.r*b;
	c.fi = a.fi*b;
	c.v = a.v*b;
	c.theta = a.theta*b;
	c.m = a.m*b;
	return c;
}

Tochka_pol operator+(Tochka_pol a, Tochka_pol b)
{
	Tochka_pol c;
	c.t = a.t + b.t;
	c.r = a.r + b.r;
	c.fi = a.fi + b.fi;
	c.v = a.v + b.v;
	c.theta = a.theta + b.theta;
	c.m = a.m + b.m;
	return c;
}

void Tochka_pol::vivod(ofstream *f)
{
	*f << "T =" << t << " H=" << h(r) << " L=" << fi * Rp << " v=" << v << " theta=" << theta * 180 / M_PI << " m=" << m << " fi = " << fi << endl;
	return;
}

void Tochka_pol::print(ofstream *fv, ofstream *ft )
{

		*fv <<theta*180.0/M_PI<< ","; *ft << t << ","; }
