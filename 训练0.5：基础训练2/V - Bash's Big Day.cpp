#include <iostream>
#include <cstdio>
#include <string>
#include <cmath>
#include <algorithm>
#include <string.h>
using namespace std;
int main()
{
	int n,t;
	int a[100100];
	while(scanf("%d",&n)!=EOF)
	{
		memset(a,0,sizeof(a));
		while(n--)
		{
			scanf("%d",&t);
			for(int i=1;i*i<=t;i++)
			{
				if(t%i==0)
				{
					a[i]++;
					if(i*i!=t) a[t/i]++;
				}
			}
		}
		int max=1;
		for(int i=2;i<100000;i++)
		if(a[i]>max) max=a[i];
		printf("%d\n",max);
	}
	return 0; 
}

