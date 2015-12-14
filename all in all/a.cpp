///all in all

#include <iostream>
#include <cstdio>
#include  <vector>
using namespace std ;

int main ()
{
	string sub,line;
	int sublen , len ,track ;
	while (cin >> sub >> line)
	{
		track = 0 ;
		len = line.size () ;
		sublen = sub.size () ;
		for( int i = 0 ; i < len ; i++)
		{
			if (line[i] == sub [track])
			track++ ; 
		}
		//cout << track << ' ' << sublen << endl ;
		if (sublen == track )
		cout << "Yes" <<endl ;
		else cout << "No" << endl ;
	}
	return 0 ;
}
