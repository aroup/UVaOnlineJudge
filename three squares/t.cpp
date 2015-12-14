/*
#include  <iostream>
#include <cstdio>
using namespace std ;

int square[101] ;

void generate_square ()
{
	for (int i = 0 ; i <=223; i++)
	{
		square[i] = i * i ;
	}
}

int main ()
{
	generate_square () ;
	int testcase ,number,q,r,a,b,c;
	cin >> testcase ;
	while (testcase--)
	{
		int flag = 0 ;
		cin >> number ;
		for (int i = 0 ; i <= 100 && square[i] <= number &&flag != 1 ;i++)
		{
			q = number - square[i] ;
			//cout << "q = " << q  << endl;
			for (int j = i ; j<= 100 && square[j] <= q && flag != 1 ; j++ )
			{
				r = q - square[j] ;
				//cout << "r = " << r << endl ;
				for (int k = j ; k <=100 && square[k] <= r && flag!= 1 ;k++)
				{
					//cout << "square [k] = " << square[k] << " k = " << k << " r = " << r <<endl ;
					if (square[k] == r )
					{
						flag = 1 ;
						a = i;
						b = j ;
						c = k ;
						//cout << a << ' ' << b << ' ' << c << endl ;
						break ;
					}
					else flag = 0 ;
			    }
			}
		}
		if (flag)
		cout << a << ' ' << b << ' ' << c << endl ;
		else cout  << -1 << endl ;
	}
	return 0 ;
}
	
*/

#include <iostream>
#include <cstdio>
using namespace std ;

///creating a dp table 
///int numbers[50001][3]= {0} ;
int i,j,k,test,numbers[50000+1][3],d;
void pregenerate ()
{
	
	for (i = 0 ; i * i <=50000 ; i++)
    {
		for (j = i ; i * i + j*j <= 500000 ;j++)
		{
			for (k = j ; i*i + j*j + k*k <=50000 ; k++)
			{
				d = i * i + j * j+ k* k ;
				if (!numbers[d][0] && !numbers[d][1] && !numbers[d][2] )
				{
					numbers[d][0]= i ;
					numbers[d][1] = j;
					numbers[d][2] = k ;
				}
			}
		}
	}
} 

int main ()
{
	pregenerate () ;
	int testcase ,n;
	cin >> testcase ;
	while (testcase--)
	{
		cin >> n; 
		if (!numbers[n][0] && !numbers[n][1] && !numbers[n][2])
		{cout << -1 << endl ;
			
		}
		else 
		cout << numbers[n][0] << ' '<< numbers [n] [1] << ' '<< numbers[n][2] << endl ;
		
	}
	return 0 ;
}
	
