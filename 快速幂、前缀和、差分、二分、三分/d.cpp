#include <bits/stdc++.h>
using namespace std;
long long qpow(long long a, long long n)
{
    long long res = 1;
    long long mod = 1e9+7;
    while(n)
    {
        if(n&1) res = (res*a)%mod;
        a = (a*a)%mod;
        n >>= 1;
    }
    return res;
}
int main()
{
    string s;
    int n;
    cin>>n>>s;
    int len = s.length();
    int a[26] = {0};
    for(int i=0;i<len;i++)
    {
        a[s[i]-'A']++;
    }
    sort(a,a+26);
    int count = 0;
    for(int i=25;i>=0;i--)
    {
        if(a[i] == a[25]) count++;
    }
    cout<<qpow(count,n);
    return 0;
}