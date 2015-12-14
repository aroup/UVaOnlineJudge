#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std ;
int main ()
{
	int testcase,number,flag,i ,k,j;
	cin >> testcase;
	char c ,d  ; 
	for (int ii = 1 ;ii <=testcase ;ii++)
	{
		int flag2 = 0 ;
		flag = 0 ;
		cin >> c >> d >> number  ;
	//	cout << number << endl ;
		long long int array [number][number];
		for (k = 0 ;k<number ;k++)
		{
		    for ( int l = 0 ;l <number ;l++)
		    {
				cin >> array[k][l] ;
				if ( array[k][l] < 0) flag2 = 1 ;
				//cout << k << ' ' << l <<' ' <<array[k][l] << endl ;
			}
		}
		if (flag2 == 1 ) cout << "Test #" <<ii << ": Non-symmetric." << endl ;
		if (flag2 == 0)
		{
	    if (number%2 == 0)
		{
			k = number /2 - 1 ;
			//cout << "k = " <<k << endl ;
			j = number/2  ;
			//cout << "j = " << j << endl ; 
			for (i = k ; i >= 0&& flag==0 ; i--)
			{
			    int K = number-1 ; 
			   // cout << K << endl ;
				for ( int I = 0 ; I < number && K >= 0 && flag == 0 ; I++ , K-- )
				{
				//	cout << i << ' ' << I << ' ' << array[i][I] << ' ' <<  j << ' ' << K << ' ' <<  array[j] [K]  << endl ; 
					if (array [i] [I] != array[j] [K] )
					{
				    flag  =1 ;
					break ;
				    }
				}
				j++ ;
			}
		}
		else
		{
			//cout << "dhukse " << endl ;
			k = number /2 - 1 ;
			//cout << "k = " <<k << endl ;
			j = number/2 + 1 ;
			//cout << "j = " << j << endl ; 
			for (i = k ; i >= 0&& flag==0 ; i--)
			{
			    int K = number-1 ;   
				for ( int I = 0 ; I < number && K >= 0 && flag == 0 ; I++ , K-- )
				{
					//cout << i << ' ' << I << ' ' << array[i][I] << ' ' <<  j << ' ' << K << ' ' <<  array[j] [K]  << endl ; 
					if (array [i] [I] != array[j] [K] )
					{
				    flag  =1 ;
					break ;
				    }
				}
				j++ ;
			}
			//cout << flag << endl ;
			if (flag == 0)
			{
				//cout << "dhukse" << endl ;
				int ASS = (number -1 ) /2 ;
				for (int y = 0 , z = number-1 ; y < z ; y++ ,z--)
				{
					//cout << ASS << ' ' << y << ' ' << ASS << ' '  << z << ' ' << array [ASS][y]  << ' '<<  array[ASS][z] << endl ;
					if (array [ASS][y] != array[ASS][z] )
					{
						 flag = 1 ;
						 break ;
					}
				} 
			}
		}
		if (flag == 1 ) cout << "Test #" <<ii << ": Non-symmetric." << endl ;
		else cout << "Test #" <<ii << ": Symmetric." << endl ;
	} 	
        }
	return 0 ;
}
