#include <iostream>
#include <vector>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std ;

int main ()
{
	char miss ,line[10000] ; 
	while (cin >> miss >> line)
	{
		if (miss == '0' && strcmp (line,"0") == 0) 
		break ;
		int i ;
		for (i = 0 ; line[i] != '\0' ; i++)
		{
			if (line[i] == miss)
			{
				line[i] = 'v' ;
			}
		}
		i = 0 ;
		while (line[i] == 'v' || line[i] == '0' )
		{
			if (line[i] == '0')
			line[i] = 'v' ;
			i++ ;
		}
		int c = 0 ;
		for (int i = 0 ; line[i] != '\0' ;i++)
		{
			if (isdigit (line[i]))
			c++ ;
		}
		if (c == 0 )cout << 0 <<endl ;
		else 
		{
			for (int i = 0; line[i] != '\0' ;i++)
			{
				if (isdigit (line[i] ) )
				cout << line[i] ;
			}
			cout << endl ;
		}
	}
	return 0 ;
}
