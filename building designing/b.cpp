#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
using namespace std;

vector <int> red ,black ;
vector <int>::iterator it ;
int max ;

int check_red (int x )
{
	int flag = 0 ;
	for (it = myvector.begin (); it != myvector.end () ; it++)
	{
		if (x > *it)
		{
			x= *it ;
			flag = 1 ;
			break ;
		}
		else flag = 0 ;
	}
	if 
}

int main ()
{
	int testcase,blocks ;
	vector <int> red ,black ;
	cin >> testcase ;
	while (testcase--)
	{
		cin >> blocks ;
		for (int i = 0 ;i <blocks ;i++)
		{
			cin >> number ;
			if (number > 0) 
			red.push_back (number) ;
			else black.push_back (-number) ;
		}
		sort.(red.begin() , red.end() ) ;
		sort.(black.begin () , black.end () ) ;
		int count = 0 ,max  = 0;
		for (int i = 0 ;
		
	}
	

