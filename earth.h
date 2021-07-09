#pragma once

#include <iomanip>
#include <iostream>
#include <fstream>
using namespace std;
const double g0 = 9.80665;
const double Gp = 398602e9;
const double Rp = 6371000;
const double Beta = 1.0 / 7153;
const double Plot0 = 1.225;
const double Davl0 = 101325;
const double Vsound = 295;



double h(double R)                    //  ���������� ������
{
	return R - Rp;
}


double g(double R)                         //����������
{
	return Gp / (R*R);
}

/*
template< class T1 >//��������� ��������� � ������� ������������

double  plot(T1 h)
{
	h = h / 1000;
//	ofstream y;
	//y.open("work.txt");
	if (h < 0)
	{
		return Plot0;
	}
	else
	{


		double H[] = { -2, -1.5, -1, -0.5, 0, 0.5, 1, 1.5, 2, 2.5, 3   , 4, 5, 6, 7, 8, 9, 10, 11, 12, 14, 16, 18, 20,
			24, 28, 32, 36, 40, 50, 60, 80,
			100, 150, 200, 500, 700, 1000 };
		double q[] = { 1.4782, 1.4114, 1.347, 1.2849, 1.225, 1.1673, 1.1117, 1.0581, 1.0065, 0.9569, 0.9093   , 0.8194, 0.7365, 0.6601, 0.59, 0.5258, 0.4671, 0.4135,
	0.3648, 0.3119, 0.2279, 0.1665, 0.1216, 0.0889, 0.0469, 0.0251, 0.0136, 0.00726, 0.004, 0.00103, 0.0003, 1.8e-5, 5.55e-7, 2.00e-9, 2.52e-10, 1.92e-11, 5.21e-13,
	3.07e-14 };
		int size1, size2;
		size1 = size(H);
		size2 = size(q);



		int n, i, j, k;

		double d, s;

		n = size2;
		double **a = new double *[n];  //������ ����������� ������� ��������� ��� ������ �
		for (i = 0; i <= n; i++)
			a[i] = new double[n];

		double *b = new double[n];		//������ ��� ���� ���� ����� ��������� � �������


		double *A = new double[n];		//������ ����������� ������������ "a"
		double *B = new double[n];		//������  ����������� ������������ "b"
		double *C = new double[n];		//������ ��� ����������� ������������ "�"
		double *D = new double[n];		//������  ����������� ������������ "d"
		double *hag = new double[n];		//������ �����

		///////////////////////////////////������ �����
		for (int i = 1; i < size1; i++)
		{
			hag[i] = H[i] - H[i - 1];

		}

		////////////////////////////////
		//---------------------------------------------------------------------------------------------------------------------
		//������ ������������ ������� ���������
		for (i = 2; i < n; i++)
		{
			for (j = 0; j < n - 2; j++)
			{
				if (i == 2)				//��� ������� ���������
				{
					if (j == 0)
					{
						a[i - 1][j + 1] = 2 * (hag[1] + hag[2]);
					}
					else if (j == 1)
					{
						a[i - 1][j + 1] = hag[2];
					}
					else if (j > 2)
					{
						a[i - 1][j + 1] = 0;
					}
					else if (j == 2)
					{
						a[i - 1][j + 1] = 0;
					}
				}
				else if (i == n - 1)				//��� ���������� ���������
				{
					if (j == n - 4)
					{
						a[i - 1][j + 1] = hag[n - 1];// h[n-2];
					}
					else if (j == n - 3)
					{
						a[i - 1][j + 1] = 2 * (hag[n] + hag[n - 1]);// (h[n-2]+h[n-2]);
					}
					else
					{
						a[i - 1][j + 1] = 0;
					}


				}
				else				//��� ��������� ��������� �������
				{
					if (j == i - 3)
					{
						a[i - 1][j + 1] = hag[i - 1];
					}
					else if (j == i - 2)
					{
						a[i - 1][j + 1] = 2 * (hag[i] + hag[i - 1]);
					}
					else if (j == i - 1)
					{
						a[i - 1][j + 1] = hag[i];
					}
					else
					{
						a[i - 1][j + 1] = 0;
					}

				}
			}
		}
		//---------------------------------------------------------------------------------------------------------------------


		//������ �� ���� ���������� ������ ��������� �������
		for (int i = 2; i < n; i++)
		{
			if (i <= n - 1)
			{
				b[i - 1] = 3 * (((q[i] - q[i - 1]) / hag[i]) - (q[i - 1] - q[i - 2]) / hag[i - 1]);

			}
			else if (i == n)
			{
				b[i - 1] = 3 * (((q[n] - q[n - 1]) / hag[n]) - (q[n - 1] - q[n - 2]) / hag[n - 1]);

			}


		}
		//----------------------------------------------------------------------------------------------------------------------

		int n1 = n - 2;
		//----------------------------------------------------------------------------------------------------------------------
		/////////////////////////////////////////////   Gauss method//////////////////////////////////////

		//������ ���

		for (k = 1; k <= n1; k++) // ������ ���
		{
			for (j = k + 1; j <= n1; j++)
			{
				d = a[j][k] / a[k][k];

				for (i = k; i <= n1; i++)
				{
					a[j][i] = a[j][i] - d * a[k][i];

				}

				b[j] = b[j] - d * b[k];
			}
		}

		//----------------------------------------------------------------------------------------------------------------------
		C[0] = 0;
		//�������� ���
		for (k = n1; k >= 1; k--) // �������� ���
		{
			d = 0;
			for (j = k + 1; j <= n1; j++)
			{
				s = a[k][j] * C[j];
				d = d + s;
			}
			C[k] = (b[k] - d) / a[k][k];
		}
		//----------------------------------------------------------------------------------------------------------------------



		/////////////////////////////////////////////////////----end----/////////////////////////////////////////////////////////////

		//���������� ������� ������������ "�"

		for (int i = 1; i <= n - 1; i++)
		{
			A[i] = q[i - 1];
		}
		//----------------------------------------------------------------------------------------------------------------------



		//���������� ������� ������������ "�"

		for (int i = 1; i <= n; i++)
		{
			if (i == n - 1)
			{
				B[n - 1] = ((q[n - 1] - q[n - 2]) / hag[i]) - 2 * hag[i] * C[n - 2] / 3;
			}
			else if (i < n)
			{
				B[i] = ((q[i] - q[i - 1]) / hag[i]) - hag[i] * (C[i] + 2 * C[i - 1]) / 3;
			}
		}
		//----------------------------------------------------------------------------------------------------------------------


		//���������� ������� ������������ "D"
		for (int i = 1; i <= n; i++)
		{
			if (i == n)
			{
				D[n - 1] = -(C[n - 2] / (3 * hag[i - 1]));

			}
			else if (i < n - 1)
			{
				D[i] = (C[i] - C[i - 1]) / (3 * hag[i - 1]);
			}
		}
		//----------------------------------------------------------------------------------------------------------------------



		//� [�] � [D] [A] �������� ���������� � 1,    [C] �������� � ������� ����������� � 0



		//������� �������
		double f;

		int size11;
		size11 = size(H);
		int point;


		//����������� ������� ������� ���������� ����������
		for (int i = 0; i < size11; i++)
		{
			if (h < H[i + 1] && h >= H[i])
			{
				point = i + 1;
			}
		}

		f = A[point] + B[point] * (h - H[point - 1]) + C[point - 1] * pow((h - H[point - 1]), 2) + D[point] * pow((h - H[point - 1]), 3);
		//----------------------------------------------------------------------------------------------------------------------

		//system("pause");




		delete[] hag;
	delete[] D;
	delete[] B;
	delete[] A;
	delete[] b;



	for (i = 0; i <= n; i++)
		delete a[i];// = new double[n];
	//delete[] a;
	return f;
	}

}
*/

double plot(double h)                      // ��������� ���������
{
	if (h < 0) return Plot0;
	return Plot0 * exp(-Beta * h);
}

double davl(double h)                      // ���������� ��������
{
	if (h < 0) return Davl0;
	return Davl0 * exp(-Beta * h);
}
