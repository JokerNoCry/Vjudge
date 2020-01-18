#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
struct need
{
	int Ai;
	int Bi;
}x[55];
bool cmp(need a,need b)
{
	return a.Ai<b.Ai;
}
void gj(int n)
{
	printf(">");
	for(int i=1;i<=n;i++)
	{
		if(i==1||i==n) printf("+");
		else printf("-");
	}
	printf(">\n");
}

int main ()
{
	int t,n;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(int i=0;i<n;i++)
		{
			scanf("%d%d",&x[i].Ai,&x[i].Bi);
		}
		sort(x,x+n,cmp);
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<x[i].Bi;j++)
			{
				gj(x[i].Ai);
			}
			printf("\n");
		}
	}
	return 0;
}
