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
	while(cin>>s)
	{
		count=0;
		int l=s.length();
		for(int i=0;i<l/2;i++)
		{
			if(s[i]!=s[l-1-i]) count++;
		}
		if(count==1||l==1||(count==0&&l%2==1)) printf("YES\n");
		else printf("NO\n");
	}

	return 0;
}

