#include <iostream>
#include <cstdio>
using namespace std ;

int main ()
{
	int a ,b, c,d,e,f, k,testcase;
	cin >> testcase ;
	for (int i = 0 ; i < testcase ;i++)
	{
		scanf("%d/%d/%d",&a,&b,&c) ;  /// current date
		scanf("%d/%d/%d",&d,&e,&f) ;  /// birth date
		k = c-f ;
		if (b < e)
		k-- ;
		else if ( b==e)
		{
			if (a < d)
			k--;
		}
		if (k < 0)
		cout << "Case #" << i+1 << ":" << " Invalid birth date" << endl ;
		else if ( k> 130 )
		cout << "Case #" << 1+i << ":" << " Check birth date" << endl ; 
		else
		cout << "Case #" << 1+i << ": " << k << endl ;
	}
	return 0 ;
} 
	
