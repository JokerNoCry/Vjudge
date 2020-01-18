#include <iostream>
#include <cstdio>
#include <string>
#include <cmath>
#include <algorithm>
#include <string.h>
using namespace std;
int main()
{
	int n,m,count;
	int a[500][500];
	int b[500][500];
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		count=0;
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<2*m;j++) scanf("%d",&a[i][j]);
		}
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++) 
			{
				b[i][j]=max(a[i][2*j],a[i][2*j+1]);
				if(b[i][j]==1) count++;
			}
		}
		printf("%d\n",count);
	}

	return 0;
}

