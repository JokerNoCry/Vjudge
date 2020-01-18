#include <stdio.h>
int a[1100];
int main()
{
	for(int i=1;i<1100;i++)
	{
		a[i]=i*i*i;
	}
	int t,x,sum;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&x);
		sum=0;
		for(int i=1;;i++)
		{
			sum+=a[i];
			if(sum>=x) 
			{
				a[0]=i;
				break;
			}
		}
		printf("%d\n",a[0]);
	}
	return 0;
}
