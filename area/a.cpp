#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
using namespace std ;

int function (double _x ,double _y,double _a)
{
	if (((_x * _x + _y *_y <= _a *_a )&& ((_x-_a) * (_x-_a) + _y*_y <= _a*_a ) && ((_x-_a) * (_x-_a) + (_y-_a) * (_y-_a) <= _a*_a) && (_x *_x +(_y-_a) * (_y-_a) <= _a*_a )) )
	return 1 ;
	else return 0 ;
}

int main ()
{
	int testcase,M ;
	double a,x,y ;
	cout <<fixed ;
	cout.precision (5) ;
	while (	cin >> testcase >> a )
	{
		M = 0 ;
		if (testcase == 0 && a== 0)
		break ;
		for (int i = 0 ;i <testcase ;i++)
		{
			cin >> x >> y ;
		    if (function (x,y,a) ) M++ ;
	    }
	    cout << ((double)M * a *a ) / (double)testcase << endl ; 
	   }
	 return 0 ;
 }
