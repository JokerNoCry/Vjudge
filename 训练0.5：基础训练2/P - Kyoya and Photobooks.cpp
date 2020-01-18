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
	int l,sign,count;
	while(cin>>s)
	{
		l=s.length();
		sign=l;
		for(int i=1;i<l;i++) 
		{
			if(s[i]==s[i-1]) sign--;
		}
		count=(26-l)*(l+1)+l*l;
		printf("%d\n",count);
	}

	return 0;
}

