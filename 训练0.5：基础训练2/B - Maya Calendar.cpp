#include <iostream>
#include <string>
#include <cstdio>
using namespace std;
string tzd[20]={"imix","ik","akbal","kan","chicchan","cimi","manik","lamat","muluk","ok","chuen","eb","ben","ix","mem","cib","caban","eznab","canac","ahau"};
string hm[19]={"pop","no","zip","zotz","tzec","xul","yoxkin","mol","chen","yax","zac","ceh","mac","kankin","muan","pax","koyab","cumhu","uayet"};
int days(int d,string m,int y)
{
	int sum=0;
	sum=sum+y*365;
	sum=sum+d+1;
	int i;
	for(i=0;;i++)
	{
		if(hm[i]!=m);
		else break;
	}
	sum=sum+i*20;
	return sum;
}
int main ()
{
	int n,d,y,all,mo;
	string m;
	char junk;
	string data;
	scanf("%d",&n);
	getchar();
	cout<<n<<endl;
	while(n--)
	{
		cin>>d>>junk>>m>>y;
		all=days(d,m,y);
		y=all/260;
		all=all%260;
		mo=all%20;
		if(mo==0) mo=20;
		d=all%13;
		if(d==0) d=13;
		m=tzd[mo-1];
		cout<<d<<" "<<m<<" "<<y<<endl;
	}
	return 0;
 } 
