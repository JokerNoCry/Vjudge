#include <iostream>
#include <cstdio> 
#include <string.h>
using namespace std;
int main ()
{
	int a[110];
	int b[110][110];
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		memset(b,0,sizeof(b));
		for(int i=0;i<n;i++)
		{
			a[i]=1;
		}
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				scanf("%d",&b[i][j]);
				if(b[i][j]==1) a[i]--;
				else if(b[i][j]==2) a[j]--;
				else if(b[i][j]==3)
				{
					a[i]--;
					a[j]--;
				}
			}
		}
		int count=0;
		for(int i=0;i<n;i++)
		{
			if(a[i]==1) count++;
		}
		printf("%d\n",count);
		int flag=0;
		for(int i=0;i<n;i++)
		{
			if(flag) printf(" ");
			if(a[i]==1) 
			{
				printf("%d",i+1);
				flag=1;
			}
		}
		if(flag) printf("\n");
	}
	return 0;
}
