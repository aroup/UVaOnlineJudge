#include <iostream>
#include <cmath>

using namespace std ;

int main ()
{
	int testcase ;
	cin >> testcase ;
	int array [testcase] ;
	char c ;
	for(int i = 0 ; i<testcase ;i++)
	{
		if (i == testcase - 1) cin >> array[i]; 
		else  
		cin >> array[i] >> c ;
	}
	for (int i = 0 ; i< testcase ;i++)
	{
		if (array[i] == 2 || array[i] == 3 || array[i] ==  5 || array[i] == 7 || array[i] == 13 || array[i] == 17 || array[i] == 19 || array[i] == 31)
		{
			cout << "Yes" << endl ;
		}
		else cout << "No" << endl ;
	}
	return 0 ;
}
