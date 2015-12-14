#include <iostream>
#include  <algorithm>
#include <cstdio>
#include <cmath>

using namespace std ;

int cube[61] ;

void generate_cube ()
{
	for (int i= 0 ; i <= 60 ; i++ )
	{
		cube[i] = i * i* i ;
	}
}

int main ()
{
	int number ;
	int flag = 0 ;
	int x, y ;
	generate_cube () ;
	while (cin >> number && number)
	{
		flag = 0 ;
		int k ;
		for (k = 0 ; k <= 60  && flag == 0;k++)
		{
			 ///cout << cube[k] << endl ;
			 int  l = -number+cube[k] ;
			 ///cout << l << endl ;
		     for (int i = 0 ; i <=60 && flag ==0 ; i++)
		     {
				 if (l == cube[i] )
				 {
					 flag = 1 ;
					 x = k ;
					 y = i ;
					 break ;
				 }
				 else flag = 0 ;
		     }
		 }
		 if (min (x,y) == 0) cout << "No solution" << endl ; 
		 else if (flag == 1 )cout << max (x,y) << ' ' << min (x,y) << endl ;
		 else cout << "No solution" << endl ;
	 }
	 return 0 ;
 }
