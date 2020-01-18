#include <iostream>
#include <cstdio>
#include <string>
#include <cmath>
#include <algorithm>
#include <string.h>
using namespace std;
int main()
{
	int n,temp;
	while(scanf("%d",&n)!=EOF)
	{
		temp=n/2+n%2;
		temp-=1;
		printf("%d\n",temp);
	}

	return 0;
}

