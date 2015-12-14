#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>

using namespace std ;

int main ()
{
	char line[1000] ;
	while (gets(line))
	{
		int sum = 0 ;
		for (int i = 0 ; line[i] != '\0' ; i++)
		{
			
			if (line[i] == '!')
			cout << endl ;
			else 
			{
				if (line[i] >= '0' && line[i] <= '9')
			{
				sum = sum + line[i] - '0' ;
				//cout << '"'<<sum << '"' <<endl ; 
			}
			else if (line[i] == 'b')
			{
				for (int k = 0 ; k < sum ; k++)
				{
					cout << ' ';
					
				}
				sum = 0 ;
			}
			else if ( line[i] >= 'A'&& line[i] <='Z')
			{
				for (int k =0 ; k < sum ; k++)
				{
					cout << line[i] ;
				}
				sum  = 0 ;
			}
			else if (line[i] == '*')
			{
				for (int k = 0 ; k < sum ; k++)
				{
					cout << line[i] ;
				}
				sum  = 0 ;
			}
		}
		}
		cout << endl ;
	}
	return 0 ;
}
			
		
