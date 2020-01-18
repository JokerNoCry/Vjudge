#include <stdio.h>
int main ()
{
	int yellow,red;
	char a[20];
	int n;
	while(scanf("%d",&n)!=EOF&&n!=0)
	{
		getchar();
		red=0,yellow=0;
		for(int i=0;i<n;i++)
		{
			scanf("%c",&a[i]);
		}
		for(int i=0;i<n;i++)
		{
			if(a[i]=='R') red++;
			else if(a[i]=='Y') yellow++;
			else if(a[i]=='B')
			{
				if(red==7) printf("Red\n");
				else printf("Yellow\n");
				break;
			}
			else if(a[i]=='L')
			{
				if(yellow==7) printf("Yellow\n");
				else printf("Red\n");
				break;
			}
		}
	}
	return 0;
}
