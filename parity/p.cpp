#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std ;

int c ; 
void binary(int number) {
	c = 0 ;
	int remainder;

	if(number <= 1) {
		cout << number;
		return;
	}

	remainder = number%2;
	binary(number >> 1);    
	cout << remainder;
	if (remainder == 1 ) c++ ;
}

int main ()
{
	int number ;
	while(cin >> number && number)
	{
		cout << "The parity of " ;
		binary(number) ;
		cout  << " is " << c+1 << " (mod 2)." << endl ;
	}
	return 0;
}
