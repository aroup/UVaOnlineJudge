#include  <iostream>
#include  <algorithm>
#include  <vector>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <cstdio>
using namespace std ;

int main ()
{
	char line [10002] ;
	int testcase ;
	cin >> testcase ;
	getchar() ;
	while (testcase--)
	{
		gets (line) ;
		double  l = strlen (line) ;
		if (floor (sqrt (l) ) == ceil (sqrt(l)))
		{
			int  root = sqrt (l) ; 
			for (int i = 0; i < root ; i++)
			{
				for (int j = i ; j < l ; j = j + root)
				{
					cout << line[j]    ;
				} 
			}
			cout << endl ;
		}
		else cout << "INVALID" << endl ;
     }
     return 0 ;
 }
