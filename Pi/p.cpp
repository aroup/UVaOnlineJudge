#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std ;

unsigned int Euclid_gcd (unsigned int a ,unsigned int b)
{
	if (b== 0)
	return a ;
	else return Euclid_gcd (b,a%b) ;
}

int main ()
{
	int testcase ;
	cout << fixed ;
	cout.precision (6) ;
	while (cin >> testcase && testcase )
	{
		int array[testcase] ;
		for (int i = 0 ;i < testcase ;i++)
		{
			cin >> array[i] ;
		}
		sort (array ,array+testcase) ;
		int c = 0 ;
		for (int i = 0 ; i< testcase-1 ;i++)
		{
			for (int j = i+1 ;j < testcase ; j++)
			{
				int x = array[j] ;
				int y = array[i] ;
				if (Euclid_gcd (x,y) ==1)
				{
					//cout << array [i] << ' '<<array[j] << endl ;
					c++ ;
				}
				
			}
		}
		int d =(testcase*(testcase-1))/2; ;
		if (c == 0) cout << "No estimate for this data set." << endl ;
		else cout << sqrt((6*d)/(c*1.0)) << endl ;
	}
	return 0;
}
		
	
