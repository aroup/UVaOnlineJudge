#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std ;

///creating a dp table 

long long int dp[32] ;

void calculate_catalan ()
{
	dp[0] = 1 ;
    dp[1] = 1 ;
    for (int i = 1 ; i <= 31 ; i++ )
    {
		dp[i+1] = (((2 *(double) i + 2 ) * (2 *(double)i + 1 )) /( ( (double) i + 1 ) * ((double) i + 2 ))) * dp [i] ;
		//cout << i << ' '  <<dp[i] << endl ; 
	}
}

int main ()
{
	calculate_catalan () ;
	long long k ,x ;
	while (cin >> k)
	{
		if ( k ==1 )x = 1 ;
		else
		{
		for (int i = 0 ; i <= 32  ;i++)
		{
			if (dp[i] == k )
			{
				x = i ;
				break ; 
			}
		}
	}
		cout << x <<endl ;
	}
	return 0 ;
}
	
