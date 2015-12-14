// AC

#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cctype>
#include<cmath>
#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<queue>
#include<map>
#include<algorithm>
#include<set>
#include<sstream>
#include<stack>

using namespace std;

int N=1000;
int status[1005];

int main()
{
    int i, j;
	for (i=3; i<=N; i+=2)
		status[i]=0;
	int sqrtN=sqrt(N);
	//cout<<sqrtN<<endl;
	status[1]=1;
	for (i=3; i<=sqrtN; i+=2)
	{
		if (status[i]==0)
		{
			for (j=i*i; j<=N; j+=i+i)
				status[j]=1;
		}
	}
	int primes[500];
	int k=1;
	primes[0]=2;
	for (i=3; i<=N; i+=2)
	{
		if (status[i]==0)
			primes[k++]=i;
	}
	int n, m;
	int div[32];
	while(cin>>n)
	{
		if (n==0)
			break;
		m=n;
		int j=0;
		for (i=0; i<k; i+=1) ///this technique is important
		{
			while(n!=1 && n%primes[i]==0)
			{
				div[j++]=primes[i];
				n=n/primes[i];
			}
		}
		if (n!=1)
			div[j++]=n;
		int count=1;
		for (i=0; i<j-1; i++)
		{
			if (div[i+1]!=div[i])
				count++;
		}
		printf("%d : %d\n", m, count);
	}
	return 0;
}
