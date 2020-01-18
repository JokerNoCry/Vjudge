#include <iostream>
#include <string>
using namespace std;
int main()
{
	int t,n;
	cin>>t;
	getchar();
	while(t--)
	{
		string a,b;
		getline(cin,a);
		a.insert(a.begin(),' ');
		n=a.length();
		for(int i=1;i<n;i++)
		{
			if(a[i-1]==' '&&a[i]!=' ')
			{
				b.insert(b.end(),a[i]);
			}
		}
		n=b.length();
		for(int i=0;i<n;i++)
		{
			if(b[i]>='A'&&b[i]<='Z') continue;
			else b[i]=b[i]-32;
		}
		cout<<b<<endl;
	}
	return 0;
}
