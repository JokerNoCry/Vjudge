#include <cstdio>
#include <string.h>
using namespace std;
int a[100010];
int cf(int n)
{
	int i=1;
	printf("0.");
	while(i)
	{
		i*=10;
		printf("%d",i/n);
		i%=n;
		if(a[i]) break;
		a[i]=1;
	}
}
int main ()
{
	int n,t;
	scanf("%d",&t);
	while(t--)
	{
		memset(a,0,sizeof(a));
		a[0]=1,a[1]=1;
		scanf("%d",&n);
		if(n<0) 
		{
			printf("-");
			n=-n;
		}
		if(n!=1)
		{
			cf(n);
			printf("\n");
		}else printf("1\n");
		
	}
	return 0;
}
