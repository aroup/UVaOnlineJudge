#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std ;

int countSetBits(int N) {
  int result = 0;
  while (N) { result++; N &= N-1; }
  return result;
}
int hex_to_dec (int y)
{
	int sum = 0 ;
	int power = 0 ;
	do{
	  	sum = sum + (y%10) * pow (16,power) ;
		power++ ;
		y = y/10 ;
		//cout<< y << endl ;
	}while(y != 0 );
	return sum ;
}

int main ()
{
     int x,testcase ,b1 ,b2 ;
     cin >> testcase ;
     for(int i = 0 ; i< testcase ;i++)
     {
		 cin >> x ;
		 b1 = countSetBits (x) ;
		 b2 = countSetBits (hex_to_dec (x)) ;
		 cout << b1 << ' ' << b2 << endl ; 
	 }
	 return 0 ;
     
 }
