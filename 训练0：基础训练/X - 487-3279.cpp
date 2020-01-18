#include<iostream>
#include<string>
#include<string.h>
#include<algorithm>
#include<stdio.h>
using namespace std;
int flag=0;
string str[100010],num;
int main()
{
	int t,count=1;
	cin>>t;
	getchar();
	for(int i=0;i<t;i++)
	{
		num="";
		getline(cin,str[i]);
		for(int j=0;j<str[i].length();j++)
		{
			if(str[i][j]=='A'||str[i][j]=='B'||str[i][j]=='C') str[i][j]='2';
			if(str[i][j]=='D'||str[i][j]=='E'||str[i][j]=='F') str[i][j]='3';
			if(str[i][j]=='G'||str[i][j]=='H'||str[i][j]=='I') str[i][j]='4';
			if(str[i][j]=='J'||str[i][j]=='K'||str[i][j]=='L') str[i][j]='5';
			if(str[i][j]=='M'||str[i][j]=='N'||str[i][j]=='O') str[i][j]='6';
			if(str[i][j]=='P'||str[i][j]=='R'||str[i][j]=='S') str[i][j]='7';
			if(str[i][j]=='T'||str[i][j]=='U'||str[i][j]=='V') str[i][j]='8';
			if(str[i][j]=='W'||str[i][j]=='X'||str[i][j]=='Y') str[i][j]='9';
		}
		for(int k=0;k<str[i].length();k++)
		{
			if(str[i][k]>('0'-1)&&str[i][k]<('9'+1)) num+=str[i][k];
		}
			while(num.length()<7)
			{
				num='0'+num;
			}
			str[i]=num;
	}
	sort(str,str+t);
		for(int i=1;i<t+1;i++)
	{
		if(str[i]==str[i-1])
		{
			count++;
		}
		else
		{
			if(count>1)
			{
			  cout<<str[i-1].substr(0,3)<<"-"<<str[i-1].substr(3,7)<<" "<<count<<endl;	
			  count=1;
			  flag=1;
			} 
		} 
	}

	if(flag==0) cout<<"No duplicates."<<endl; 
}
