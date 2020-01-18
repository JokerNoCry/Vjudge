#include <iostream>
#include <cstdio>
#include <string>
#include <cmath>
#include <algorithm>
#include <string.h>
using namespace std;
int main()
{
	string s;
	int l;
	int a[5];//UDRL
	int x,y,t;
	int count;
	while(cin>>s)
	{
		l=s.length();
		memset(a,0,sizeof(a));
		count=0;
		if(l%2==1) printf("-1\n");
		else 
		{
			for(int i=0;i<l;i++)
			{
				if(s[i]=='U') a[1]++;
				if(s[i]=='D') a[2]++;
				if(s[i]=='R') a[3]++;
				if(s[i]=='L') a[4]++;
			}
			if(a[1]-a[2]>0) x=a[1]-a[2];
			else x=a[2]-a[1];
			if(a[3]-a[4]>0) y=a[3]-a[4];
			else y=a[4]-a[3];
			if(x-y>0) t=x-y;
			else t=y-x;
			count+=min(x,y);
			count+=t/2;
			printf("%d\n",count);
		}
		
	}

	return 0;
}

