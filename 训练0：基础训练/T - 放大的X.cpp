#include <stdio.h>
void x(int n)
{
	//up
	for(int i=0;i<n/2;i++)
	{
		for(int j=0;j<n-i;j++)
		{
			if(i==j||i+j==n-1) printf("X");
			else printf(" ");
		}
		printf("\n");
	}
	for(int i=0;i<n/2+1;i++)
	{
		if(i==n/2) printf("X");
		else printf(" ");
	}
	printf("\n");
	for(int i=n/2;i>0;i--)
	{
		for(int j=0;j<n+1-i;j++) 
		{
			if(i==j+1||i+j==n) printf("X");
			else printf(" "); 
		}
		printf("\n");
	}
} 
int main()
{
	int t,n;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		x(n);
		printf("\n");
	}
	return 0;
}
