#include <iostream>
#include <cstdio>
#include <vector>

using namespace std ;

long long int fib[101] ; 
long long int suma[101] ;
void calculate_fib()
{
	fib[0] = 1 ;
	fib[1] = 1 ;
	for (int i = 2 ; i< 101 ;i++)
	{
		fib[i] = fib[i-1] + fib[i-2] ;
	}
	int sum = 0 ; 
	for (int i = 0 ; i < 101 ; i++)
	{
		sum = sum + fib[i] ;
		suma[i] = sum ;
	}
}
	

int main ()
{
	int testcase ;
	calculate_fib () ;
	while(cin >> testcase && testcase>=0)
	{
		cout << suma[testcase-1]  << ' '  <<suma[testcase-1] + fib[testcase] << endl ;
	}
	return 0 ;
}
