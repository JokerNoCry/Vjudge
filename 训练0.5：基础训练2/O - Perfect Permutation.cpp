#include <iostream>
#include <cstdio>
#include <string>
#include <cmath>
#include <algorithm>
#include <string.h>
using namespace std;
int main()
{
	int n;
	int a[110];
	for(int i=0;i<110;i++) a[i]=i+1;
	for(int i=0;i<55;i++)
	{
		int temp=a[2*i];
		a[2*i]=a[2*i+1];
		a[2*i+1]=temp;
	}
	while(scanf("%d",&n)!=EOF)
	{
		if(n%2==1) printf("-1\n");
		else 
		{
			int flag=0;
			for(int i=0;i<n;i++)
			{
				if(flag) printf(" ");
				flag=1;
				printf("%d",a[i]);
			}
			printf("\n");
		}
	}

	return 0;
}

