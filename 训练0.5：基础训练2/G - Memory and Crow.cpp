#include <iostream>
#include <cstdio>
#include <string.h>
using namespace std;
int a[100100],b[100100];
int main()
{
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		for(int i=0;i<n;i++)
		{
			scanf("%d",&a[i]);
		}
		for(int i=n-1;i>=0;i--)
		{
			b[i]=a[i]+a[i+1];
		}
		int flag=0;
		for(int i=0;i<n;i++)
		{
			if(flag) printf(" ");
			flag=1;
			printf("%d",b[i]);
		}
		printf("\n");
	}
	return 0;
}
