#include <stdio.h>
int main ()
{
	int n,c,count;
	scanf("%d",&c);
	while(c--)
	{
		count=0;
		scanf("%d",&n);
		while(n)
		{
			if(n%2==0) n/=2;
			else 
			{
				n--;
				count++;
			}
		}
		printf("%d\n",count);
	}
}
