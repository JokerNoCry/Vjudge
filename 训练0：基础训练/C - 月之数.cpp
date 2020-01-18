#include <stdio.h>
#include <math.h>
int main ()
{
	int t,n,ans;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		ans=pow(2,n-1)+(n-1)*pow(2,n-2);
		printf("%d\n",ans);
	}
	return 0;
}
