#include <iostream>
#include <cstdio>
#include <string>
#include <cmath>
#include <algorithm>
#include <string.h>
using namespace std;
long long a[100100],c[100100];
long long b[100100];
long long len[12];
long long mod=10e9+7;
int main()
{
	long long n,k;
	len[1]=1;
	for(int i=2;i<=10;i++) len[i]=len[i-1]*10;
	while(scanf("%lld%lld",&n,&k)!=EOF)
	{
		for(int i=1;i<=n/k;i++)	scanf("%lld",&a[i]);
		for(int i=1;i<=n/k;i++) scanf("%lld",&b[i]);
		long long sum=1;
		for(int i=1;i<=n/k;i++)
		{
			if(b[i]!=0)	c[i]=(len[k+1]-1)/a[i]+1-(((b[i]+1)*len[k]-1)/a[i]-(b[i]*len[k]-1)/a[i]);
			else c[i]=(len[k+1]-1)/a[i]-(len[k]-1)/a[i];
			sum=sum*c[i]%mod;
		}
		sum=sum%mod;
		printf("%lld\n",sum);
	}
	return 0;
}

