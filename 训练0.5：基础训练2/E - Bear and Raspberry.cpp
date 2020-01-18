#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;
int x[110];
int main ()
{
	int n,c;
	int ans;
	while(scanf("%d%d",&n,&c)!=EOF)
	{
		memset(x,0,sizeof(x));
		for(int i=0;i<n;i++)
		{
			scanf("%d",&x[i]);
		}
		ans=x[0]-x[1];
		for(int i=1;i<n-1;i++)
		{
			if(x[i]-x[i+1]>ans) ans=x[i]-x[i+1];
		}
		ans-=c;
		if(ans>0) printf("%d\n",ans);
		else printf("0\n");
	}
}
