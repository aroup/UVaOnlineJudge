#include <iostream>
#include <cstdio>

using namespace std ;

int main ()
{
	int i , j,number ,top,testcase;
	int ans[2] ;
	cin >> testcase ;
	for (i = 1 ; i<=testcase ;i++)
	{
		cin >> number ;
		top = 0 ;
		for (j = 2 ; top <2 && j*j <= number ;j++)
		{
			if (number % j == 0)
			{
				ans[top++] =  j ;
			}
		}
		printf("Case #%d: %d = %d * %d = %d * %d\n",i,number,ans[0],number/ans[0],ans[1],number/ans[1]);
	}
	return 0 ;
}
