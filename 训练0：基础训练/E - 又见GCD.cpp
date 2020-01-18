#include <stdio.h>
#include <math.h>
int gcd(int m,int n)
{
	if(m<n)
	{
		int temp=m;
		m=n;
		n=temp;
	}
	while(m%n)
	{
		int sign=n;
		n=m%n;
		m=sign;
	}
	return n;
}
int main ()
{
	int n,a,b;
	scanf("%d",&n);
	while (n--)
	{
		scanf("%d%d",&a,&b);
		for(int i=2;;i++)
		{
			if(gcd(a,b*i)==b)
			{
				printf("%d\n",b*i);
				break;
			}
		}
	}
	return 0;
}
