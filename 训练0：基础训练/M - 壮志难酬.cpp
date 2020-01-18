#include <stdio.h>
#include <string.h>
int main ()
{
	int t,n,b[10];
	double a;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%lf%d",&a,&n);
		a=a-(int)a;
		a+=0.00000001; 
		a=a*1000000;
		b[0]=(int)a;
		for(int i=6;i>=1;i--)
		{
			b[i]=b[0]%10;
			b[0]/=10;
		} 
		printf("%d\n",b[n]);
	}
	return 0;
}
