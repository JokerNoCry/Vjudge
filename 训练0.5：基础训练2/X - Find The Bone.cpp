#include <iostream>
#include <cstdio>
#include <string>
#include <cmath>
#include <algorithm>
#include <string.h>
using namespace std;
int n,m,k,ui,vi,sign;
int h[1000100],a[1000100];
void swap(int x,int y)
{
	if(a[x]==1 && h[x]==0)
	{
		a[x]=0;
		a[y]=1;
	}else if(a[y]==1 &&h[y]==0)
	{
		a[y]=0;
		a[x]=1;
	}
}
int main()
{
	memset(h,0,sizeof(h));
	memset(a,0,sizeof(a));
	a[1]=1;
	scanf("%d%d%d",&n,&m,&k);
	for(int i=0;i<m;i++)
	{
		scanf("%d",&sign);
		h[sign]=1;
	}
	while(k--)
	{
		scanf("%d%d",&ui,&vi);
		swap(ui,vi);
	}
	for(int i=1;i<=n;i++)
	{
		if(a[i]!=0) printf("%d\n",i);
	}
	return 0;
}

