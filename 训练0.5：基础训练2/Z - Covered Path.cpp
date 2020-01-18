#include <iostream>
#include <cstdio>
#include <string>
#include <cmath>
#include <algorithm>
#include <string.h>
using namespace std;
int main()
{
	int v1,v2,t,d;
	scanf("%d%d",&v1,&v2);
	scanf("%d%d",&t,&d);
	int ans=0;
	while(t--)
	{
		if(v1<v2)
		{
			ans+=v1;
			v1+=d;
		}else
		{
			ans+=v2;
			v2+=d;
		}
	}
	printf("%d\n",ans);
	return 0;
}

