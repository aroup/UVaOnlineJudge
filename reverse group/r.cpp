#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <cstring>

using namespace std ;
void reverse_func(char *line1,int a,int b)
{
        char temp ;
        for (int p = a ,q = b-1 ; p < q ;p++ ,q--)
        {
                  temp = line1[p] ;
                  line1[p] = line1[q] ;
                  line1[q] = temp ;
                  //cout << "completed" << endl;
        }
}


int main ()
{
	int number ;
	char line[200] ;
	while (cin>> number && number)
	{
		cin >> line ;
		int l = strlen (line) ;
		int group = l / number ;
		for (int i = 0 ; i < l ; i = i+ group  )
		{
			reverse_func (line , i , i+ group ) ;
		}
		cout << line << endl ;
	}
	return 0 ;
}
