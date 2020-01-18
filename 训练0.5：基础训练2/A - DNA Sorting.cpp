#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
using namespace std;
string dna[110];

int num(string s)
{
	int l=s.length();
	int count=0;
	for(int i=0;i<l-1;i++)
	{
		for(int j=i+1;j<l;j++)
		{
			if(s[i]>s[j]) count++;
		}
	}
	return count;
}
bool cmp(string a,string b)
{
	int m,n;
	m=num(a);
	n=num(b);
	return m<n;
}
int main ()
{
	int m,n;
	scanf("%d%d",&m,&n);
	getchar();
	for(int i=0;i<n;i++)
	{
		getline(cin,dna[i]);
	}
	sort(dna,dna+n,cmp);
	for(int i=0;i<n;i++)
	{
		cout<<dna[i]<<endl;
	}
	return 0;
 } 
