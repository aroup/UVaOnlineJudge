#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
using namespace std ;

int main ()
{
        char line[100000],c ;
        int testcase ;
        cin >> testcase ;
        getchar () ;
        for (int i = 1; i <= testcase; i += 1)
        {
                gets (line) ; 
                for (int k = 0 ; line[k] != '\0' ;k++ )
                {
                      if (line[k] >= 'A' && line[k] <= 'Z')
                      {
                        c =line[k] ;
                      }
                      else if (line[k] >= '0' && line[k] <= '9')
                      {
                         int p = 0 ;
                         p = p+line[k] - '0' ;
                         k++ ;
                         while (line[k] >='0' && line[k] <= '9' )
                         {
                                p = p*10 + line[k] - '0' ;
                                k++ ;
                                }
                                k-- ;
                         for (int q = 0 ; q < p ; q++)
                         {
                                cout << c ;
                                }
                                                                 
                       }
                       }
                       cout << endl ;
                       }
                       return 0 ;
                       }
