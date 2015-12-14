#include <iostream>
#include <cmath>

using namespace std ;

long long factorial ( int n )
{
	if (n == 0 )
	return 1 ;
	else return n * factorial(n-1) ;
}

int main ()
{
	int number ,testcase ;
	cin >> testcase; 
	while (testcase--)
	{
		cin >> number ;
		long int l = factorial (number) ;
		if (number == 1) 
		cout << 0 << '/' << 1 << endl ;
		else cout <<(int)floor ((exp(1) + exp (-1))*l ) - (int)floor (exp (1) * l) << '/' << l << endl ;
	}
	return 0 ;
}	 
	
