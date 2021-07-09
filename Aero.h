#pragma once
double Cy(Tochka_pol z, LA bo)
{
	return 0;
}

double Cx(Tochka_pol z, LA bo)
{                                       //коэф лоб сопр в зависимости от скорсти
	double M = z.v / Vsound;
	if (M < 0.8) return bo.Cx0_0;
	if (M < 1) return bo.Cx0_0 + (bo.Cx0_1 - bo.Cx0_0)*(M - 0.8) / 0.2;
	if (M < 5) return bo.Cx0_1 + (bo.Cx0_5 - bo.Cx0_1)*(M - 1) / (5 - 1);
	return bo.Cx0_5;
}
