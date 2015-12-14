#include <iostream>
#include <algorithm>

using namespace std ;

int main ()
{
	long long int A, B ,testcase = 1;
	while (cin >> A >> B )
	{
		if (A==0 && B==0)
		break ;
		else cout << "Case " << testcase++ <<": "  <<(((A * (A-1)) /2) * ((B * (B-1) )/2)) << endl ;
	}
	return 0 ;
}
