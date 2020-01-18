#include <iostream>
#include <string>
using namespace std;
int main ()
{
	string a,b;
	int n,l1,l2;
	scanf("%d",&n);
	getchar();
	while(n--)
	{
		getline(cin,a);
		getline(cin,b);
		l1=a.length();
		l2=b.length();
		a.insert(l1/2,b);
		cout<<a<<endl;
	}
	return 0;
 } 
