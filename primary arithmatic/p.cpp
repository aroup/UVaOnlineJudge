#include <iostream>
#include <cstdio>
#include <algorithm>
#define MAX 20 
#include <cstdlib>
#include <cstring>
#include <string>
using namespace std ;

void reverse (char *from ,char *to)
{
	int len = strlen (from);
	int i ;
	for (i =0 ; i <len ;i++)
	{
		to[i] = from [len-1-i] ;
	}
	to[len] = '\0' ;
}

int call_sum (char *first ,char *sec ,char *result )
{
	char F[MAX] ,S[MAX] ,Res[MAX] ;
	int f,s,sum,extra ,now,c = 0;
    
	s = strlen (sec) ;
	f = strlen (first);

	reverse (first,F) ;
	
	reverse (sec,S) ;
	
	for (int k = s ; k < f; k++)
	{
		S[k] = '0' ;
	}
	S[f] = '\0' ; 
 	
	s = strlen (S) ;
	//cout << s << endl ;
	for (now = 0 ,extra= 0 ;(now<f && now<s) ;now++)
	{
		sum = (F[now] -'0' ) + (S[now] -'0' ) +extra ;
	    Res[now] = sum %10 + '0' ; 
	    extra = sum /10 ;
	    if (sum >= 10) c++ ;
        
	}
	
	///cout << S <<endl ;

	return c ;
}
		 

int main ()
{
	char fir[MAX] ,sec [MAX] ,res[MAX] ;
	int k ;
	while (cin >> fir >> sec)
	{
	//	cout << fir << ' ' << sec << endl ;
		if (strcmp(fir,"0") == 0 && strcmp (sec,"0") == 0)
		break ;
	    if (strlen (fir) >= strlen(sec)) 
	    {
			k =  call_sum (fir,sec,res) ;
			if (k== 0) cout << "No carry operation." << endl ;
			else if (k==1) cout <<"1 carry operation." << endl ;
			else cout << k << " carry operations." << endl ;
		}
		else 
		{
			k=  call_sum (sec ,fir ,res ) ;
			if (k== 0) cout << "No carry operation." << endl ;
			else if (k==1) cout <<"1 carry operation." << endl ;
			else cout << k << " carry operations." << endl ;

		}
	}
	return 0;
}	 
