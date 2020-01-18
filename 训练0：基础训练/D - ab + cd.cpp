#include <stdio.h>
#include <math.h>
int gy(int n,int m)
{
	if(n<m)
	{
		int temp=n;
		n=m;
		m=temp;
	}
	while(n%m)
	{
		int sign=m;
		m=n%m;
		n=sign;
	}
	return m;
}
int main ()
{
	int a,b,c,d,t,e,f,x;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d%d%d",&a,&b,&c,&d);
		f=b*d;
		e=a*d+b*c;
		x=gy(e,f);
		printf("%d %d\n",e/x,f/x);
	}
	return 0;
}
