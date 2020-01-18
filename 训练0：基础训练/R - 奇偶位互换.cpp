#include <iostream>
#include <string>
#include <cstdio>
using namespace std;
int main ()
{
	int c,l;
	string a;
	char tmp;
	scanf("%d",&c);
	getchar();
	while(c--)
	{
		getline(cin,a);
		l=a.length();
		for(int i=0;i<l;i+=2)
		{
			tmp=a[i];
			a[i]=a[i+1];
			a[i+1]=tmp;
		}
		cout<<a<<endl;
	}
	return 0;
}
