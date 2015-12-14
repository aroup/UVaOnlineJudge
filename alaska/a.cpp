#include <iostream>
#include <algorithm>

using namespace std ;

int main ()
{
	int array[1423],number ,flag1 ,flag2 ;
	int testcase ;
	while (cin >> testcase && testcase)
	{
		flag1 = 0 ;
		for (int i = 0 ; i < 1423 ;i++)
		{
			array [i] = 0 ;
		}
		for (int i = 0 ; i < testcase ;i++)
		{
			cin >> number ;
			array[number] = 1 ;
		}
		int gascounter ;
		for (int i = 0 ; i < 1423 ; i++)
		{
			if (array[i] == 1) 
			gascounter = 200 ;
			else gascounter-- ;
			if (gascounter == 0)
			{
				flag1 = 1 ;
				break ;
			}
		}
		//cout << gascounter << endl; 
		if (flag1 == 1)
		cout << "IMPOSSIBLE" << endl ;
		else
		{
			flag2 = 0 ;
			for (int i = 1422 ; i >= 0 ; i-- )
			{
				if (array[i] ==1 )
				gascounter = 200 ;
				else gascounter-- ;
				if (gascounter == 0)
				{
					flag2 =1 ;
					break ;
				}
			}
			if (flag2 == 0 ) cout << "POSSIBLE" << endl ;
			else cout << "IMPOSSIBLE" << endl ;
     	}
     }
     return 0 ;
 }
	
	
