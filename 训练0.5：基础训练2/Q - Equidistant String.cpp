#include <iostream>
#include <cstdio>
#include <string>
#include <cmath>
#include <algorithm>
#include <string.h>
using namespace std;
int main()
{
	string a,b;
	int l,count;
	while(cin>>a>>b)
	{
		count=0;
		l=a.length();
		for(int i=0;i<l;i++) 
		{
			if(a[i]!=b[i]) count++;
		}
		if(count%2==1) printf("impossible\n");
		else 
		{
			int flag=0;
			for(int i=0;i<l;i++)
			{
				
				if(a[i]!=b[i])
				{
					if(flag<count/2) printf("%c",a[i]);
					else printf("%c",b[i]);
					flag++;
				}else printf("%c",a[i]);
			}
			printf("\n");
		}
	} 

	return 0;
}

