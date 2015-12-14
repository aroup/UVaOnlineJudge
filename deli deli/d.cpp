#include <iostream>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std ;

int main()
{
	map <string ,string> mymap ;
	string a ,b,c ;
	int irregular , testcase ,l;
	cin >> irregular >> testcase ;
	for (int i = 1 ; i <=irregular ;i++)
	{
		cin >> a >> b ;
		mymap [a] = b ;
	}
	for (int i = 0 ; i< testcase ;i++)
	{
		cin >> c ;
		if (mymap.find (c) != mymap.end())
		{
			cout << mymap[c] << endl ;
		}
		else 
		{
			l = c.size () ;
			if (c[l-1] == 'y' && c[l-2] != 'a' && c[l-2] !='e' && c[l-2] != 'i'&& c[l-2] !='o' && c[l-2] !='u' )
			{
				for (int k = 0 ; k <=l-2 ; k++)
				{
					cout << c[k] ;
				}
				cout << "ies" << endl ;
 			} /// "o", "s", "ch", "sh" or "x"
 			else if ( c[l-1] == 'o' || c[l-1] == 'x' || c[l-1] =='s' || (c[l-1] =='h' && c[l-2] == 'c') || (c[l-1] == 'h' && c[l-2] == 's')) 
 			{
				cout << c << "es" << endl ;
			}
			else cout << c << 's' << endl ;
         }
	 }
	 return 0 ;
 }
