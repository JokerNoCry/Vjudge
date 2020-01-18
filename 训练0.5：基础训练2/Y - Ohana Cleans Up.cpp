#include <iostream>
#include <cstdio>
#include <string>
#include <cmath>
#include <algorithm>
#include <string.h>
using namespace std;
int main()
{
	string s[110];
	int n;
	scanf("%d",&n);
	getchar();
	for(int i=0;i<n;i++) getline(cin,s[i]);
	sort(s,s+n);
	int sign=1,m=1;
	for(int i=1;i<n;i++)
	{
		if(s[i]==s[i-1]) sign++;
		else sign=1;
		m=max(m,sign);
	}
	printf("%d\n",m);
	return 0;
}

