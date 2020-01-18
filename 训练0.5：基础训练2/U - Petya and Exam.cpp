#include <iostream>
#include <cstdio>
#include <string>
#include <cmath>
#include <algorithm>
#include <string.h>
using namespace std;
int main()
{
	int cha[26];
	string good,pattern,query,p1,p2;
	int l,l1,l2,lq,n,flag,pos;
	while(cin>>good>>pattern)
	{
		scanf("%d",&n);
		l=pattern.length();
		memset(cha,0,sizeof(cha));
		p1="";
		p2="";
		for(int i=0;i<good.length();i++) cha[good[i]-'a']=1;
		flag=0;pos=-1;
		for(int i=0;i<l;i++)
		{
			if(pattern[i]=='*')
			{
				flag=1;
				pos=i;
				continue;
			}
			if(flag) p2+=pattern[i];
			else p1+=pattern[i];	
		}
		l1=p1.length();
		l2=p2.length();
		while(n--)
		{
			flag=1;
			cin>>query;
			lq=query.length();
			if(l-lq>1) flag=0;
			if(lq<max(l1,l2)) flag=0;
			else 
			{
				for(int i=0;i<l1;i++)
				{
					if(p1[i]!=query[i])
					{
						if(p1[i]=='?')
						{
							if(cha[query[i]-'a']==0)
							{
								flag=0;
								break;
							}
						}
						else
						{
							flag=0;
							break;
						}
					}
				}
				for(int i=0;i<l2;i++)
				{
					if(query[lq-1-i]!=p2[l2-1-i])
					{
						if(p2[l2-1-i]=='?')
						{
							if(cha[query[lq-1-i]-'a']==0) 
							{
								flag=0;
								break;
							}
						}else
						{
							flag=0;
							break;
						}
					}
				}
				if(pos==-1 && l<lq) flag=0; 
				for(int i=pos;i<pos+lq-l1-l2;i++)
				{
					if(cha[query[i]-'a']==1) 
					{
						flag=0;
						break;
					}
				}
			} 
			if(flag) printf("YES\n");
			else printf("NO\n");
		}
	}
	
	return 0;
}

