#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <iomanip>
#include <stack>
#include <vector>
#include <queue>
#include <map>
#include <complex>
#include <cstdio>
#include <cstdlib>

using namespace std ;

int N  = 10000;
int status[10000] ;
int primes [1240] ;
void isprime ()
{
        int i ,j ,sqrtN ;
        status[1] = 0 ;
        for (i = 2; i <= N; i += 1)
        {
                status [i] = 0 ;         
        }
        sqrtN = (int) (sqrt ((double) N) ) ;
        for (int i = 3; i <= sqrtN; i += 2)
        {
                if (status[i] ==0)
                {
                        for (j = i*i; j <= N; j += i+i)
                        {
                                status[j] = 1 ;
                        }
                }
                 
        }
        primes[0] = 2 ;
        int K = 1 ;
        for (int i = 3 ; i <= 9999 ; i= i + 2 )
		{
			//cout << "dhukse" << endl ;
			if (status[i] == 0 )
			{primes[K] = i ;
			K++;
		}
		}
        //cout << status[15] << endl ;
}
 

int main (int argc, char const* argv[])
{
		isprime() ;
		int testcase ,number,answer;
		cin >> testcase ;
		for (int i= 0 ; i< testcase ; i++)
		{
			cin >> number ;
			for (int k = 0 ; k <= 1230 ; k++)
			{
				if ( 2 * primes[k] > number )
					{
					answer = primes[k] ;
					break ;
				}
			}
			cout << answer << endl ;
		}
		return 0 ;
	}
