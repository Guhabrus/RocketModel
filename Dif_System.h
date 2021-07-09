#pragma once
Tochka_pol Tochka_pol::dTochka_pol_dt(LA S)
{
	double H = h(r);               //мгновенная высота полёта
	double Q = plot(H)*(v*v) / 2;    //скоростной напор
	double Ft;
	double Fn;
	double Mr;
	double Pt;
	double Alfa;

	Mr		= S.Mr;
	Alfa	= alfa(*this, S);

	Pt		= P(H, S);  //тяга тякущая

	double Rx = Cx(*this, S)*Q*S.Smidle;   //лоб сопр
	double Ry = Cy(*this, S)*Q*S.Smidle;   //Подъемн сил


	Ft = Pt * cos(Alfa) - m * g(r)*sin(theta) - Rx;    //сила продольная
	Fn = Pt * sin(Alfa) - m * g(r)*cos(theta) + Ry;    //сила поперчная
			 //произвоные
	Tochka_pol b;
	b.t		= 1;
	b.r		= v * sin(theta);
	b.fi	= v * cos(theta) / r;
	b.v		= Ft / m;
	b.theta = b.fi + Fn / (m*v);
	b.m		= -Mr;
	return b;
}

