#pragma once


double I(double h, LA S)                           //�������
{
	double Dotn = davl(h) / Davl0;
	return S.Ia + (S.Ip - S.Ia)*(1 - Dotn);
}

double P(double h, LA S)                     //����
{
	return S.Mr*I(h, S);
}
