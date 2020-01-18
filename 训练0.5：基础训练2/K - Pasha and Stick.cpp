#include <iostream>
#include <cstdio>
#include <string>
#include <cmath>
#include <algorithm>
#include <string.h>
using namespace std;
int main()
{
	int n,count;
	while(scanf("%d",&n)!=EOF)
	{
		count=0;
		if(n%2==1)
		{
			printf("0\n");
			continue;
		}
		else 
		{
			for(int i=1;i<n/2;i++)
			{
				if(i%2==0) count++;
			}
		}
		printf("%d\n",count); 
	}

	return 0;
}

