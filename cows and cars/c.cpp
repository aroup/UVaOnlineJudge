#include <iostream>
#include <algorithm>
#include <vector>
using namespace std ;

int main ()
{
	double NCOWS ,NSHOW ,NCARS ;
	cout<< fixed ;
	cout.precision (5) ;
	while (cin >> NCOWS >> NCARS >> NSHOW )
	{
		cout << (NCOWS / (NCOWS+NCARS)) * (NCARS / (NCARS+NCOWS-NSHOW-1)) + ((NCARS-1) / (NCARS+NCOWS-NSHOW-1)) * (NCARS / (NCARS+NCOWS)) << endl  ;
		
	}
	return 0 ;
}
