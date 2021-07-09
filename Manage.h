#pragma once
double alfa(Tochka_pol b, LA e)
{
	if (e.first_stage)
	{
		double M = b.v / Vsound;
		if (M < 0.2) return (M_PI / 2) - b.theta;
		//if (M<0.5) return e.alfa_min*(M-0.2)/0.3;
		if (M < 0.8) return e.alfa_min*(0.8 - M) / 0.6;
		return 0;
	}

	double Tangag = atan(e.C0 + e.C1*b.t);
	return Tangag - b.theta;
}


