#include <iostream>
#include <cstdio>
#include <string>
#include <cmath>
#include <string.h>
typedef long long ll;
using namespace std;
int main()
{
	ll n,k;
	while(scanf("%lld%lld",&n,&k)!=EOF)
	{
		ll temp=n/k;
		int ans=temp%2;
		if(ans==0) printf("NO\n");
		else printf("YES\n");
	} 
	
	return 0;
}

