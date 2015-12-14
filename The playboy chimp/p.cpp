#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>

using namespace std ;

int main ()
{
	int chimps,queries,flag;
	scanf("%d",&chimps);
	int array[chimps] ;
	for (int i = 0 ; i< chimps ; i++ )
	{
		scanf("%d",&array[i] ) ;
	}
	scanf("%d",&queries) ;
	int query[queries] ;
	for (int i = 0 ; i < queries ; i++)
	{
		scanf("%d",&query[i] ) ;
	}
	
	for (int i = 0 ; i < queries ; i++ )
	{
		 int x = 0 ,j,k;
		 flag = 0 ;
	     for(j = 0 ; j< chimps && flag == 0 ;j++)
	     {
			 if (array[j] < query[i])
			 {
			 x = array[j] ;
			// cout << x << endl ;
		     }   
			 else 
			 flag = 1 ;
		 }
		 //cout << "fuck " << endl ;
		 int y = -1 ;
		 flag = 0;
		 //cout << j << endl ;
		 for (k = j-1 ; k < chimps && flag == 0 ; k++)
		 {
			// cout << query[i] << ' ' << array[k] << endl ;
			 if (query[i] < array[k] )
			 {
			 y = array[k] ;
		//	 cout << y << endl ;
			 flag = 1 ;
		     }
		 }
		 if (x== 0) printf("X ") ;
		 else printf ("%d ",x) ;
		 if (y == -1 ) printf("X\n") ;
		 else printf ("%d\n",y) ;
		 
	 }
	 return 0 ;
 }
