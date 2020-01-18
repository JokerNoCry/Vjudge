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
	int count;
	int a[6000];
	while(cin>>s)
	{
		count=0;
		memset(a,0,sizeof(a));
		int l=s.length();
		a[l-1]=5;
		for(int i=0;i<l-3;i++)
		{
			if(s[i]=='b' &&s[i+1]=='e' &&s[i+2]=='a' &&s[i+3]=='r')
			{
				a[i]=1;a[i+1]=2;a[i+2]=3;a[i+3]=4;
			}
		}
		for(int i=0;i<l;i++)
		{	
			int flag=0;
			for(int j=i;j<l;j++)
			{
				if(a[j]==1 &&a[j+3]==4)
				{
					count+=l-j-3;
					break;
				}
			}
		}
		printf("%d\n",count);
	 } 

	return 0;
}

