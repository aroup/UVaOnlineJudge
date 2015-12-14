#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <cstring>
#include <string>
#include <cstdlib>
#include <cstdio>

using namespace std ;

int main () 
{
	map <char ,char> mymap ;
	string mapa = "`1234567890-=qwertyuiop[]\\asdfghjkl;'zxcvbnm,./";
    string caps = "~!@#$%^&*()_+QWERTYUIOP{}|ASDFGHJKL:\"ZXCVBNM<>?";
    string weird = "`123qjlmfp/[]456.orsuyb;=\\789aehtdck-0zx,inwvg'";
    string weirdcaps = "~!@#QJLMFP?{}$%^>ORSUYB:+|&*(AEHTDCK_)ZX<INWVG\"";
    for (int i = 0 ; mapa[i]!= '\0' ; i++ )
    {
		mymap[mapa[i]] = weird[i] ;
	}
	for (int i = 0 ; caps[i] != '\0' ; i++)
	{
		mymap[caps[i]] = weirdcaps[i] ;
	}
	char line[10000] ;
	while (gets(line))
	{
		for (int i = 0 ; line[i]!= '\0' ; i++ )
		{
			if (line[i] == ' ') cout << ' ' ;
			else
			cout << mymap[line[i]] ;
		}
		cout << endl ;
	}
	return 0 ;
}
	
		
	
