#define _USE_MATH_DEFINES
#include <cmath>
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <iomanip>


using namespace std;
unsigned int  a = 17, c = 34, m = 2147483647,d = 666;


void sort(double a,int * ranges1,int fnumber)
{
	if (a != 0){
		int count = 0;
		if (fnumber <= 5)
		{
				while (a < 1)
				{
					a += 0.1;
					count++;
				}
			ranges1[count - 1]++;
		}
		else if (fnumber < 9)
		{
			if ((fnumber==6)&&(a>=3))
			{ }
			else
			{
				if ( (fnumber == 7) && (a < 3) && (a > -3))
				{
					while (a < 3)
					{
						a++;
						count++;
					}
					if (count == 0) count = 5;
					ranges1[count - 1]++;
				}
				else if (fnumber==8){
					if ((a<=3)&&(a>=-3))
					{
						while (a < 3)
						{
							a++;
								count++;
						}
						if ((count <= 0) && (count > 9)) count = 5;
							ranges1[count - 1]++;
					}
				}
			}
		}
		else
		{
			if ((a>=0)&&(a<=100))
			{
				ranges1[(int(a) / 10)]++;
			}
			
		}
		
		
	}
	
}

double method1(unsigned int& x0)
{
	x0 = ((a*x0 + c) % m);
	return (float(x0) / float(m));
}

double method2(unsigned int& x0)
{
	x0 = (d*x0 ^ 2 + a * x0 + c) % m;
	return(float(x0) / float(m));
}
double method3(unsigned int& x0)
{
	return 0.1;
}
double method4(unsigned int& x0)
{
	unsigned int x0obern = 1;
	while ((x0*x0obern) % 2048 != 1)
	{
		x0obern++;
	}
	x0 = (a*x0obern + c) % 2048;
	return float(x0) / float(2048);
}

double method5(unsigned int& x0)
{
	double z;
	z = method1(x0) - method2(x0);
	if (z < 0)
		z += 1;

	return z;
}

double method6(unsigned int& x0)
{
	double x;
	double sum=0;
	for (int i = 1; i <= 12; i++)
	{
		sum += method1(x0);
	}
		
	x = (sum - 6);
	return x;
}

double method7(unsigned int& x0)
{
	return 0;
}

double method8(unsigned int& x0)
{
	double x,u,v;
	v = method1(x0);
	//cout << v << "  ";
	u = method1(x0);
	//cout << u << "  ";
	x = (sqrt(8 / M_E ))*((v - 0.5) / u);
	//cout << v << "  "<<endl;
	if (x*x <= 5 - 4 * sqrt(sqrt(M_E))*u)
	{
		//cout << x<< endl;
		return x;
	}
		
	if (x*x >= 4 * pow(M_E, -1.35) / u + 1.4)
	{
		//cout << x<< endl;
		return x;
	}
	while (x>-4*log(u))
	{
		v = method1(x0);
		//cout << v << "  ";
		u = method1(x0);
		//cout << u << "  ";
		x = (sqrt(8 / M_E))*((v - 0.5) / u);
		//cout << x << "  "<<endl;
	}
	//if (x > 3) { x -= 6; }
	//cout << x << endl;
	return x;

}

double method9(unsigned int& x0)
{
	double nu=8,u;
	u = method1(x0);
	//cout << -nu * log(u) << endl;
	return -nu * log(u);
}

double method10(unsigned int& x0)
{
	double x, y;
	int a = 40;
	y = tan(M_PI*method1(x0));
	x = sqrt(2 * a - 1)*y + a - 1;
	return x;
}
void ShowChartBar(int number,int * ranges,int fnumber)
{
	
	if ((fnumber<=5)||(fnumber>8))
	{
		for (int i = 0; i <= 9; i++)
		{
			cout  << i + 1 << " " << setprecision(2)<< float(ranges[i]) / float(number) << endl;
		}
	}
	else if (fnumber < 9)
	{
		for (int i = 0; i <= 5; i++)
		{
			cout<< i + 1 << " " << setprecision(5) <<float(ranges[i]) / float(number) << endl;
		}
			
	}
}




int main()
{	
	unsigned int functionnumber,x0;
	
	srand(time(NULL));
	x0 = rand();
	cout << "Input method number: ";
	cin >> functionnumber;
	if (functionnumber > 10 || functionnumber < 1)
	{
		cout << "incorrect method number"<<endl;
		system("Pause");
		return 0;
	}


	double(*FuncPointerArr[10])(unsigned int&) = { method1,method2,method3,method4,method5,method6,method7,method8,method9,method10 };


	int number =1000000;
	int ranges[10] = {};

	if (functionnumber == 3)
	{
		int xn = ((a*x0 + c) % m);
		int xnminus1 = x0;
		int xnplus1;
		double xnp1double;
		for (int i = 1; i <= number; i++)
		{
			xnplus1 = (xn + xnminus1) % m;
			xnminus1 = xn;
			xn = xnplus1;

			xnp1double = float(xnplus1) / float(m);

			sort(xnp1double, ranges,functionnumber);
		}
		ShowChartBar(number, ranges,functionnumber);
	}
	else if (functionnumber == 7)//--------------------------------------------------------------
	{
		for (int i = 1; i <= number; i++)
		{
			double v1, v2, s=1, x1, x2;
			while(s>=1)
			{
				v1 = 2 * method1(x0) - 1;
				v2 = 2 * method1(x0) - 1;
				s = v1 * v1 + v2 * v2;
			}

			x1 = v1 * sqrt(-2 * log(s) / s);
			x2 = v2 * sqrt(-2 * log(s) / s);
		//	cout <<s<<" " <<v1<<" "<<v2<<" "<< x1 << " " << x2 << " " << "      " << endl;
			sort(x1, ranges, functionnumber);
			sort(x1, ranges, functionnumber);
		}
		

		ShowChartBar(2*number, ranges, functionnumber);
	}
	else
	{
		for (int i = 1; i <= number; i++)
		{
			sort(FuncPointerArr[functionnumber - 1](x0), ranges,functionnumber);
		}

		ShowChartBar(number, ranges,functionnumber);


	}

	system("Pause");
	return 0;
}

