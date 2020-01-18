#include <iostream>
#include <cstdio>
#include <string>
#include <cmath>
#include <algorithm>
#include <string.h>
using namespace std;
int a[27];
int b[7];
//0  a  1  
int main()
{
	//aaBblsuur   a B b l s u r
	//            2 1 1 1 1 2 1
	string s;
	while(cin>>s)
	{
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		for(int i=0;i<s.length();i++)
		{
			if(s[i]=='B') b[0]++;
			else if(s[i]>='a'&&s[i]<='z')a[s[i]-'a']++;
		}
		b[1]=a['a'-'a']/2;
		b[2]=a['b'-'a'];
		b[3]=a['l'-'a'];
		b[4]=a['s'-'a'];
		b[5]=a['u'-'a']/2;
		b[6]=a['r'-'a'];
		sort(b,b+7);
		printf("%d\n",b[0]);
	}
	

	return 0;
}

