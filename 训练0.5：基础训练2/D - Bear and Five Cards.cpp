#include <stdio.h>
#include <string.h>
int a[110],b[5];
int main ()
{
	int n,sum;
	while(scanf("%d",&n)!=EOF)
	{
		sum=0;
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		a[n]++;
		sum+=n;
		for(int i=0;i<4;i++)
		{
			scanf("%d",&n);
			a[n]++;
			sum+=n;
		}
		int flag=0;
		for(int i=0;i<=100;i++)
		{
			if(a[i]>=3) 
			{
				if(i*3>flag) flag=i*3;
			}else if(a[i]>=2)
			{
				if(i*2>flag) flag=i*2;
			}
		}
		sum-=flag;
		printf("%d\n",sum);
	}
	return 0;
}
