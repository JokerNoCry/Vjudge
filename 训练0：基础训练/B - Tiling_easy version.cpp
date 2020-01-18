#include <stdio.h>
long long num(int n)
{
	if(n==1) return 1;
	else if(n==2) return 3;
	else return num(n-1)+2*num(n-2);
}
int main ()
{
	int t,n;
	long long ans[31];
	ans[1]=1;
	ans[2]=3;
	for(int i=1;i<=30;i++)
	{
		ans[i]=num(i);
	}
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		printf("%d\n",ans[n]);
	}
}
