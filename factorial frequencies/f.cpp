#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
using namespace std ;
char f[10000];
char factorial[1010][10000];
void multiply(int k){
int cin,sum,i;
int len = strlen(f);
cin=0;
i=0;
while(i<len){
sum=cin+(f[i] - '0') * k;
f[i] = (sum % 10) + '0';
i++;
cin = sum/10;
}
while(cin>0){
f[i++] = (cin%10) + '0';
cin/=10;
}
f[i]='\0';
for(int j=0;j<i;j++)
factorial[k][j]=f[j];
factorial[k][i]='\0';}

void fac(){
int k;
strcpy(f,"1");
for(k=2;k<=1000;k++)
multiply(k);
}
void print(int n){
int i;
int len = strlen(factorial[n]);
printf("%d!\n",n);
for(i=len-1;i>=0;i--){
printf("%c",factorial[n][i]);
}
printf("\n");
}
int main(){
int n;
factorial[0][0]='1';
factorial[1][0]='1';
fac();
map <char,int> mymap ;
while(scanf("%d",&n)==1&& n){
for(char i = 1 ; i <= 9 ; i++)
{
		mymap [char (i)] = 0 ;
}
for  (int I = 0 ; factorial[n][I] != '\0' ;I++)
{
	 mymap[factorial[n][I]]++ ;
}
cout << n << "! --" << endl; 
cout <<"   (0)    "<<mymap['0']<<"    (1)    "<<mymap['1']<<"    (2)    "<<mymap['2']<<"    (3)    "<<mymap['3']<<"    (4)    "<<mymap['4']<<endl ;
cout <<"   (5)    "<<mymap['5']<<"    (6)    "<<mymap['6']<<"    (7)    "<<mymap['7']<<"    (8)    "<<mymap['8']<<"    (9)    "<<mymap['9']<<endl ; 
mymap.erase (mymap.begin() ,mymap.end()) ;
}
return 0;
}
