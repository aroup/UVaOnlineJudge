#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
using namespace std ;

int main ()
{
	int testcase ,flag;
	char name[21] ,test[21];
	cin >> testcase ;
	while (testcase--)
	{
		cin >> name ;
		cin >> test ;
		if (strlen(name ) != strlen(test) )
		{
			 cout << "No" << endl ;
		 }
		 else 
		 {
			 flag = 1 ;
			 for (int i = 0 ;name[i]!= '\0' && flag ==1 ;i++)
			 {
				 if (name[i]=='a' || name[i]== 'i' || name[i]=='e' || name[i]=='o' || name[i]=='u')
				 {
					 if (test[i]=='a' || test[i]== 'i' || test[i]=='e' || test[i]=='o' || test[i]=='u')
					 ;
					 else
					 {
						 flag =0 ;
						 break ;
					 }
				 }
				 else
				 {
					 if (name[i] == test[i] )
					 ;
					 else 
					 {
						 flag = 0 ;
						 break ;
					 }
				 }
			 }
			 if (flag==1)
			 cout << "Yes" << endl ;
			 else cout << "No" << endl ;
		 }
	 }
	 return 0 ;
 }
