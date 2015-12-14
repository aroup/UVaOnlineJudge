#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <iomanip>
#include <stack>
#include <vector>
#include <queue>
#include <map>
#include <complex>
#include <cstdio>
#include <cstdlib>

using namespace std ;

int N  = 10000;
int status[10000] ;
void isprime ()
{
        int i ,j ,sqrtN ;
        status[1] = 1 ;
        for (i = 2; i <= N; i += 1)
        {
                status [i] = 0 ;         
        }
        sqrtN = (int) (sqrt ((double) N) ) ;
        for (int i = 3; i <= sqrtN; i += 2)
        {
                if (status[i] ==0)
                {
                        for (j = i*i; j <= N; j += i+i)
                        {
                                status[j] = 1 ;
                        }
                }
                 
        }
        //cout << status[15] << endl ;
}
 

int main (int argc, char const* argv[])
{
		isprime() ;
		vector <int> output_num ,output_A ,output_a;
		vector <int>::iterator it ;
        int testcase ;
        cin >> testcase ;
        char line[10000] ;
        getchar () ;
        for (int k = 1 ; k<=testcase ; k++)
        {
		cin>>line ;
		//int l = strlen (line) ;
		int c ; 
		//int l = strlen (line) ;
		for (int i = 0 ; line[i]!= '\0'; i++)
		{
			c = 0 ;
			if(line[i] >='0' && line[i] <= '9')
			{
				c = 1; 
				for (int j = i+1 ;line[j] != '\0' ; j++)
				{
					if (line[j] == line[i] )
					{
						c++ ;
					    line[j] = '!' ;
				     }
				}
				if (c == 2 ) output_num.push_back ((int)(line[i])) ;
				 else if (status[c] == 0 && c %2 != 0 )
				output_num.push_back ((int)(line[i])) ;
		     }
		     if (line[i] >= 'A' && line[i] <= 'Z' )
		     {
				 c = 1 ;
				 //cout << "dhukse" << endl ;
				 for (int j = i + 1 ;line[j] != '\0' ; j++ )
				 {
					// cout << j << ' ' << i << ' ' << line[j] << ' ' << line[i] << endl ;
					 if (line[j] == line[i] )
					 {
					//  cout << "paisi re mama" ;
					 c++ ;
					 line[j] ='!' ;
				     }
				 }
				 if (c== 2 ) output_A.push_back ((int)(line[i])) ;
				 else if (status[c] == 0 && c%2 != 0  )
				 output_A.push_back ((int)(line[i])) ;
			 }
			 if (line[i] >= 'a' && line[i] <= 'z' )
		     {
				 c = 1 ;
				 for (int j = i + 1 ;line[j] != '\0' ; j++ )
				 {
					 if (line[j] == line[i] )
					 {
					 c++ ;
					 line[j] ='!' ;
				     }
				 }
				 if (c== 2 ) output_a.push_back ((int)(line[i])) ;
				 if (status[c] == 0 && c%2 != 0 )
				 output_a.push_back ((int)(line[i])) ;
			 }
		 }
		 sort (output_num.begin () ,output_num.end()) ; 
		 sort (output_A.begin () ,output_A.end () ) ;
		 sort (output_a.begin () ,output_a.end () ) ;
		 cout << "Case "<< k <<": " ; 
		 if (output_num.size () == 0 && output_A.size () == 0 && output_a.size () == 0 )
		 cout << "empty" << endl; 
		 else
		 { 
		 for (it = output_num.begin () ; it != output_num.end() ;it++)
		 {
			 cout << char(*it) ;
		 }
		 for (it = output_A.begin () ; it != output_A.end() ;it++)
		 {
			 cout << char(*it) ;
		 }
		 for (it = output_a.begin () ; it != output_a.end() ;it++)
		 {
			 cout << char(*it) ;
		 }
		 cout << endl ;
	 }
		 output_num.erase(output_num.begin () ,output_num.end()) ;
		 output_A.erase (output_A.begin () ,output_A.end () ) ;
		 output_a.erase (output_a.begin () ,output_a.end () ) ;
		 
	    }     

        return 0;
}
