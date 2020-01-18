#include <stdio.h>
int C(int m,int n)
{
	int ans=1;
	for(int i=1;i<=n;i++)
	{
		ans=ans*(m-n+i)/i;
	} 
	return ans;
}
int main ()
{
	int n,m,t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&m);
		if(n<m) printf("0\n");
		else 
		{
			printf("%d\n",C(n,m));
		}
	}
	return 0;
}
