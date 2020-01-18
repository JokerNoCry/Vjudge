#include <stdio.h>
int C(int m,int n)
{
	int s=1;
	for(int i=1;i<=n;i++)
	{
		s=s*(m-n+i)/i;
	}
	return s;
}
int main ()
{
	int t,m,n,sum;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&m);
		sum=C(n+1,2)*C(m+1,2);
		printf("%d\n",sum);
	}
	return 0;
}
