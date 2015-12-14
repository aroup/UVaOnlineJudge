#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std ;

int main()
{
	const double PI = 2*acos(0.0);
	double V ,D  ;
	cout << fixed ;
	cout.precision (3) ;
	while (cin >> D >> V)
	{
		if (V ==0 && D ==0)
		break ;
		else cout << pow(((PI * pow(D,3) -6 * V) /PI),(1./3.)) << endl ;
	}
	return 0 ;
} 
