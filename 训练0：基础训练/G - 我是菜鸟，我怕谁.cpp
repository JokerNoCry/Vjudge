#include <stdio.h>
int main ()
{
	int n,t,s,v;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		s=0;
		for(int i=1;i<=n;i++)
		{
			
			v=2*i-1;
			s+=v;
			s=s%10000;
		}
		printf("%d\n",s);
	}
	return 0;
} 
