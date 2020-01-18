#include <iostream>
#include <cstdio>
#include <string>
#include <cmath>
#include <algorithm>
#include <string.h>
using namespace std;
string a,b;
void turn1(void)
{
	for(int i=0;i<b.length();i++)
	{
		if(b[i]!='9') b[i]++;
		else b[i]='0'; 
	}
}
void turn2(void)
{
	char c=b[b.length()-1];
	for(int i=b.length()-1;i>=0;i--)
	{
		b[i]=b[i-1];
	}
	b[0]=c;
}
int main()
{
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		getchar();
		cin>>a;
		b=a;
		for(int i=0;i<=10;i++)
		{
			turn1();
			for(int i=0;i<n;i++)
			{
				turn2();
				if(b<a) a=b;
			}
		}
		cout<<a<<endl;
	}
	return 0;
}

