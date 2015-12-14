#include <iostream>
#include <cstdio>

using namespace std ;

int main ()
{
	int i , a ,b ,c ;
	while (cin >> i >> a >> b >> c )
	{
		if ( !i && !a && !b && !c)
		break ;
		else 
		cout << 720 + 360 + (((a>i?(40-a)+i:(i-a)) + (b<a?(40-a)+b:(b-a)) + (c>b?(40-c)+b:(b-c))))*9 << endl ;
	}
	return 0 ;
}
