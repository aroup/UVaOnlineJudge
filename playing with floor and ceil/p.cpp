#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdio>
using namespace std ;

int main ()
{
	int testcase ;
	long long val_1,val_2,p,q,x,k ;
	cin >> testcase ;
	while (testcase--)
	{
		cin >> x >> k ;
		val_2 = ceil ((double)x/(double)k) ;
		val_1 = floor ((double)x/(double)k) ; 
		for (p = 0 ; p * val_1 <= x ; p++)
		{
			if ((x-p *val_1) % val_2 == 0 )
			{
			q = (x-p * val_1) /val_2 ;
			break ;
		    }
		}
		cout << p << ' ' << q << endl ;
	}
	return 0 ;
}
