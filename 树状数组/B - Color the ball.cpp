//区间修改，单点查询
#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <algorithm>
#include <vector>
#include <cmath>
#define endl "\n"
#define LL long long
#define IO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define debug(x); cout<<x<<endl;
using namespace std;

/***
 * Author Informathons :
 * @author: JokerNoCry
 * @date: 2021-04-10  12:48:41 
***/

const int maxn=5e5+10;
const int mod=1e9+7;

int n;
int a[maxn],c[maxn];

int lowbit(int x)
{
    return x&(-x);
}

void update(int i,int j)
{
    while(i<=n)
    {
        c[i] += j;
        i += lowbit(i);
    }
}

int getsum(int i)
{
    int res = 0;
    while(i>0)
    {
        res += c[i];
        i -= lowbit(i);
    }
    return res;
}

int main()
{
    IO;
    while(cin>>n)
    {
        if(n == 0) break;
        memset(c,0,sizeof(c));
        int a,b;
        for(int i=1;i<=n;i++)
        {
            cin>>a>>b;
            update(a,1);
            update(b+1,-1);
        }
        for(int i=1;i<=n;i++)
        {
            cout<<getsum(i);
            if(i == n) cout<<endl;
            else cout<<" ";
        }
    }
    return 0;
}