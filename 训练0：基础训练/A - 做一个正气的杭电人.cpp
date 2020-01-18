#include <stdio.h>
int main ()
{
	int n,m,i,j;
	scanf("%d",&n);
	while (n--)
	{
		scanf("%d",&m);
		for(i=0;i<3*m;i++)
		{
			for(j=0;j<m;j++)
			{
				printf("HDU");
				if(j==m-1) printf("\n");
			}
		}
	}
	return 0;
}
