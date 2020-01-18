#include <iostream>
#include <cstdio>
#include <string>
#include <cmath>
#include <algorithm>
#include <string.h>
using namespace std;
int main()
{
	int a,n,count;
	int pr[110],hhh=1;
	int *p,*q;
	while(scanf("%d%d",&n,&a)!=EOF)
	{
		count=0;
		p=&pr[a-1];
		q=&pr[a-1];
		memset(pr,0,sizeof(pr));
		for(int i=0;i<n;i++) scanf("%d",&pr[i]);
		for(int i=0;i<n;i++)
		{	
			if(*q==1 && *p==1)  count+=2;
			if(q==&hhh && *p==1) count--;
			if(p==&hhh && *q==1) count--;
			if(p==pr||p==&hhh) p=&hhh;
			else p--;
			if(q==&pr[n-1]||q==&hhh) q=&hhh;
			else q++;
		
		 } 
		 if(pr[a-1]==1) count--;
		 printf("%d\n",count);
	}
	return 0;
}

