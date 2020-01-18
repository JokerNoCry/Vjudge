#include <iostream>
#include <cstdio>
#include <string.h>
#include <algorithm>
using namespace std;
int a[1000];
int main ()
{
	int c,v,w,n,sum,num;
	float nd;
	scanf("%d",&c);
	while(c--)
	{
		memset(a,0,sizeof(a));
		scanf("%d%d%d",&n,&v,&w);
		for(int i=0;i<n;i++)
		{
			scanf("%d",&a[i]);
		}
		sort(a,a+n);
		sum=0;
		num=0;
		nd=0;
		for(int i=0;i<n;i++)
		{
			sum+=a[i];
			num++;
			nd=(float)sum/(float)num;
			if(nd>w)
			{
				num--;
				sum-=a[i];
				if(num==0) nd=0;
				else nd=(float)sum/(float)num;
				break;
			}
		}
		printf("%d %.2f\n",v*num,nd/100.0);
	}
	return 0;
}
 
