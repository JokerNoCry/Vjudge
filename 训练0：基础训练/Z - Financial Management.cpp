#include <stdio.h>
#include <math.h>
int main ()
{
	float n,sum=0;
	int m=12;
	while(m--)
	{
		scanf("%f",&n);
		sum+=n;
	}
	sum=sum/12.0;
	printf("$%.2f",sum);
	return 0;
}
