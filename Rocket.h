#pragma once
class LA;
class Tochka_pol;

#include <fstream>
#include <Math.h>
#include "earth.h"
#include "LA.h"
#include "Tochka_pol.h"
#include "Aero.h"
#include "DY.h"
#include "Manage.h"
#include "Dif_System.h"









Tochka_pol calc1(Tochka_pol p0, LA st)
{
	Tochka_pol  p1, p2, p3, k1, pk, k2, k3, k0, kk;

	double dt = 0.1;

	// расчёт r, t, fi, v, theta, m             //r- радиус полёта
												//t-время полёта
	ofstream b;  // fi-угол полёта

	ofstream time; time.open("Time.txt");
	ofstream Vs;	Vs.open("V.txt"); // fi-угол полёта
	time << fixed; time.precision(3);
	Vs << fixed; Vs.precision(3);
	b.open("work_first_stage12.txt");  
	Vs << " Time = [";// thata-угол тангажа
	pk = p0;                                                  //m-масса корабля
	while (pk.m > st.M0 - st.Mt)
	{
		pk.vivod(&b);
		p0 = pk;
		//pk.print(&Vs, &time);
		k0 = p0.dTochka_pol_dt(st);          //dt=h

		p1 = p0 + k0 * (dt / 2);
		k1 = p1.dTochka_pol_dt(st);

		p2 = p0 + k1 * (dt / 2);
		k2 = p2.dTochka_pol_dt(st);

		p3 = p0 + k2 * dt;
		k3 = p3.dTochka_pol_dt(st);

		kk = (k0 + k1 * 2 + k2 * 2 + k3)*(1.0 / 6.0);

		pk = p0 + kk * (dt);
		Vs << pk.t<<", ";// alfa(pk, st)*180.0 / M_PI << ",";


		// p0=pk;


	}

	double dtk = (st.M0 - st.Mt - p0.m) / kk.m;
	pk = p0 + kk * dtk;
	Vs << "];";

	pk.vivod(&b);

	b.close();
	return pk;
}





Tochka_pol calc2(Tochka_pol p0, LA st)
{
	Tochka_pol  p1, p2, p3, k1, pk, k2, k3, k0, kk;

	double dt = 0.1;

	// расчёт r, t, fi, v, theta, m             //r- радиус полёта
				
								//t-время полёта
	ofstream b;        
	
	ofstream time; time.open("Time2.txt");
	ofstream Vs;	Vs.open("V2.txt"); // fi-угол полёта
	b.open("work_first_stage2.txt");                         // thata-угол тангажа
	pk = p0;
	//m-масса корабля

	time << fixed; time.precision(3);
	Vs << fixed; Vs.precision(3);
	while (pk.v <= st.Vk2)
	{
		pk.vivod(&b);
		pk.print(&Vs, &time);
		p0 = pk;

		k0 = p0.dTochka_pol_dt(st);          //dt=h

		p1 = p0 + k0 * (dt / 2);
		k1 = p1.dTochka_pol_dt(st);

		p2 = p0 + k1 * (dt / 2);
		k2 = p2.dTochka_pol_dt(st);

		p3 = p0 + k2 * dt;
		k3 = p3.dTochka_pol_dt(st);

		kk = (k0 + k1 * 2 + k2 * 2 + k3)*(1.0 / 6.0);

		pk = p0 + kk * (dt);



		// p0=pk;


	}

	double dtk = (st.Vk2 - p0.v) / kk.v;
	pk = p0 + kk * dtk;


	pk.vivod(&b);

	b.close();
	return pk;
}









//задаём начальные параметры

void calc_roket()
{
	// stage2

	
	/*
	LA stage1;
	stage1.Ia = 253.0*g0;
	stage1.Ip = 315.0*g0;
	stage1.Mr = 103000.0/stage1.Ia;//массовый расход
	stage1.Cx0_0 = 0.13;
	stage1.Cx0_1 = 0.45;
	stage1.Cx0_5 = 0.35;
	stage1.Smidle = M_PI * 1.2*1.2 / 4;//площадь миделя
	stage1.M0 = 8100.0;
	stage1.Mt = 6500.0;
	stage1.theta_k1 = 20 * M_PI / 180;
	stage1.first_stage = true;





	LA stage2;
	stage2.Ip = 315 * g0;
	stage2.Ia = 315 * g0;
	stage2.Cx0_0 = 0.13;
	stage2.Cx0_1 = 0.45;
	stage2.Cx0_5 = 0.35;
	stage2.Smidle = M_PI * 1.2*1.2 / 4;
	stage2.M0 =  1000.0+100.0;
	stage2.Mr = 16000.0/stage2.Ia;
	stage2.Mt = 900.0;
	stage2.first_stage = false;
	stage2.theta_k2 = 0 * M_PI / 180;
	stage2.hk2 = 200000;
	stage2.Vk2 = sqrt(Gp / (stage2.hk2 + Rp));    //нужно ешё учесть вращение земли
	stage2.C0 = 0.244;
	stage2.C1 = 0;*/
	

	std::ofstream prinTT;	prinTT.open(" M(theta).txt");

	prinTT << "M = [";

	double theta_End = 21.0*M_PI / 180.0;

	//while (theta_End <= 25.0*M_PI / 180.0)
	//{
		LA stage1;
		stage1.Ia			= 303.0*g0;
		stage1.Ip			= 333.0*g0;
		stage1.Mr			= 7*9.0;// 192000.0 / stage1.Ia;//массовый расход
		stage1.Cx0_0		= 0.13;
		stage1.Cx0_1		= 0.45;
		stage1.Cx0_5		= 0.35;
		stage1.Smidle		= M_PI * 1.2*1.2 / 4;//площадь миделя
		stage1.M0			= 13000.0;
		stage1.Mt			= 9300.0;
		stage1.theta_k1		= theta_End;// 20 * M_PI / 180;
		stage1.first_stage  = true;





		LA stage2;
		stage2.Ip			= 333 * g0;
		stage2.Ia			= 333 * g0;
		stage2.Cx0_0		= 0.13;
		stage2.Cx0_1		= 0.45;
		stage2.Cx0_5		= 0.35;
		stage2.Smidle		= M_PI * 1.2*1.2 / 4;
		stage2.M0			= 2450.0 + 250.0;
		stage2.Mr			= 7.0;//23000.0 / stage2.Ia;
		stage2.Mt			= 2150.0;
		stage2.Mc			= 250.0;//масса сухой РН
		stage2.first_stage  = false;
		stage2.theta_k2		= 0 * M_PI / 180;
		stage2.hk2			= 200000;
		stage2.Vk2			= sqrt(Gp / (stage2.hk2 + Rp));    //нужно ешё учесть вращение земли
		stage2.C0			= 0.244;
		stage2.C1			= 0;
		//stage1








		//нач парметр для класса Tochka_pol
		Tochka_pol p0_1, pk_1, p0_2, pk_2, pk_2_stepC0, pk_2_stepC1;


		/*
		p0_2.t=pk_1.t;
		p0_2.r=pk_1.r;
		p0_2.fi=pk_1.fi;
		p0_2.v=pk_1.v;
		p0_2.theta=pk_1.theta;   //  stage2.theta_k2
		p0_2.m=stage2.M0;
		*/

		p0_1.t		= 0;
		p0_1.r		= Rp;
		p0_1.fi		= 0;
		p0_1.v		= 0.001;
		p0_1.theta	= M_PI / 2;
		p0_1.m		= stage1.M0;   //+stage2.MO;


		ofstream p;
		p.open("log_stage1.txt");
		ofstream q;
		q.open("log_stage2.txt");
		double alfa_min_rh = 0, alfa_min_lf = -90 * M_PI / 180;
		double alfa_min_mdl;

		do
		{
			alfa_min_mdl = (alfa_min_rh + alfa_min_lf) / 2;
			stage1.alfa_min = alfa_min_mdl;


			p << "alfa_min_mdl= " << alfa_min_mdl * 180 / M_PI << "  alfa_min_rh= " << alfa_min_rh * 180 / M_PI << "  alfa_min_lf= " << alfa_min_lf * 180 / M_PI;
			pk_1 = calc1(p0_1, stage1);
			p << " theta= " << pk_1.theta * 180 / M_PI << endl;//" theta2= "<<pk_2.theta*180/M_PI<<endl;


			if (pk_1.theta > stage1.theta_k1)// pk_2.theta>stage2.theta_k2)    //!!!
			{
				alfa_min_rh = alfa_min_mdl;
			}
			else
			{
				alfa_min_lf = alfa_min_mdl;
			}




		} while (fabs(pk_1.theta - stage1.theta_k1) > 0.01*M_PI / 180); //&& fabs(pk_2.theta-stage2.theta_k2)>0.01*M_PI/180);

		/*
		p0_2.t=pk_1.t;
		p0_2.r=pk_1.r;
		p0_2.fi=pk_1.fi;
		p0_2.v=pk_1.v;
		p0_2.theta=pk_1.theta;   //  stage2.theta_k2
		p0_2.m=stage2.M0;
		*/
		p0_2 = pk_1;
		p0_2.m = stage2.M0-20.0;
		//calc2(p0_2, stage2);

		stage2.C0 = tan(stage1.theta_k1);
		stage2.C1 = 0;
		double stepC0 = 0.001, stepC1 = 0.001 / 500;

		q << "C0= " << stage2.C0 << " C1= " << stage2.C1;
		pk_2 = calc2(p0_2, stage2);
		q << "h= " << h(pk_2.r) << " theta= " << pk_2.theta * 180 / M_PI << endl;

		while ((fabs(pk_2.theta - stage2.theta_k2) > 0.01*M_PI / 180) || (fabs(h(pk_2.r) - stage2.hk2) > 500)) //&& fabs(pk_2.theta-stage2.theta_k2)>0.01*M_PI/180);

		{


			stage2.C0 = stage2.C0 + stepC0;
			q << "C0= " << stage2.C0 << " C1= " << stage2.C1;
			pk_2_stepC0 = calc2(p0_2, stage2);
			q << "h= " << h(pk_2_stepC0.r) << " theta= " << pk_2_stepC0.theta * 180 / M_PI << endl;
			stage2.C0 = stage2.C0 - stepC0;

			stage2.C1 = stage2.C1 + stepC1;
			q << "C0= " << stage2.C0 << " C1= " << stage2.C1;
			pk_2_stepC1 = calc2(p0_2, stage2);
			q << "h= " << h(pk_2_stepC1.r) << " theta= " << pk_2_stepC1.theta * 180 / M_PI << endl;
			stage2.C1 = stage2.C1 - stepC1;


			double dh_dC1, dh_dC0, dtheta_dC0, dtheta_dC1;

			dh_dC0 = (pk_2_stepC0.r - pk_2.r) / (stepC0);
			dtheta_dC0 = (pk_2_stepC0.theta - pk_2.theta) / (stepC0);

			dh_dC1 = (pk_2_stepC1.r - pk_2.r) / (stepC1);
			dtheta_dC1 = (pk_2_stepC1.theta - pk_2.theta) / (stepC1);

			double a11, a12, b1, b2, a21, a22;

			a11 = dh_dC0;
			a12 = dh_dC1;
			b1	= stage2.hk2 - h(pk_2.r);
			a21 = dtheta_dC0;
			a22 = dtheta_dC1;
			b2	= stage2.theta_k2 - pk_2.theta;

			double op	= (a11*a22) - (a21*a12);
			double op1	= (b1*a22) - (a12*b2);
			double op2	= (a11*b2) - (b1*a21);
			double x1	= op1 / op;
			double x2	= op2 / op;

			stage2.C0 = stage2.C0 + x1;
			stage2.C1 = stage2.C1 + x2;

			q << " C0= " << stage2.C0 << " C1= " << stage2.C1;
			pk_2 = calc2(p0_2, stage2);
			q << " h= " << h(pk_2.r) << " theta= " << pk_2.theta * 180 / M_PI << endl;

		}

		double mpn = pk_2.m - stage2.Mc;
		std::cout << " Mass = " << mpn+20.0 << std::endl;

		prinTT << mpn << ", ";
		//theta_End += 1.0*M_PI / 180.0;
		p.close();
		q.close();
	//}


	prinTT << "];\n theta = [";

	theta_End = 15.0*M_PI / 180.0;

	while (theta_End <= 25.0*M_PI / 180.0)
	{
		theta_End += 1.0*M_PI / 180.0;
		prinTT << theta_End * 180 / M_PI<<", ";
	}

	prinTT << "];\n plot(theta, M,'g');";

	prinTT.close();
	
	theta_End += 1.0*M_PI / 180.0;
}

