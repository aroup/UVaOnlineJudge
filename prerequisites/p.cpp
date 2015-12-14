#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <cstring>
#include <string>
using namespace std ;

int main ()
{
	int k ,m ,r,c ;
	char course [5] ;
	while (cin >> k && k )
	{
		char line[k][5] ;
		cin >> m ;
		for (int i = 0 ; i < k ; i++ )
		{
			cin >> line[i] ;
		}
		int flag[m];
		for (int o = 0 ; o <m ;o++)
		{
			flag[o] = 1; 
		}
		for (int i = 0  ;i <m ;i++)
		{
		int R = 0 ;	
		cin >> c >> r ;
		for (int j = 0 ; j < c ; j++ )
		{
			cin >> course ;
			for (int l = 0 ; l < k ; l++)
			{
				if (strcmp (line[l] ,course) == 0)
				R++ ;
			}
		}
		if (R>= r)
		flag[i] = 1;
		else flag[i] = 0 ;
	}
	int boobs = 0 ;
	for (int i = 0 ; i <= m ;i++ )
	{
		if (flag[i] == 0)
		{
			boobs = 1;
			break ;
		}
	}
	if (boobs==0)
	cout << "yes" << endl ;
	else cout << "no" << endl; 
}
return 0 ;
}
		
