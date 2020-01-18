#include <stdio.h>
int main ()
{
	float n;
	float sum;
	while(scanf("%f",&n)!=EOF&&n!=0)
	{
		sum=0;
		for(int i=1;;i++)
		{
			sum+=1.0/(float)(i+1);
			if(sum>=n)
			{
				printf("%d card(s)\n",i);
				break;
			}
		}
	}
}
