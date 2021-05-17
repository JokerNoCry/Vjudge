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
#define lowbit(x) ((x)&(-x))
using namespace std;

/***
 * Author Informathons :
 * @author: JokerNoCry
 * @date: 2021-04-30  16:57:30 
***/

const int maxn=1e3+50;
const int mod=1e9+7;

int n,q,t;
int c[maxn][maxn];

void update(int x,int y,int k)
{
    for(int i=x;i<=n;i+=lowbit(i))
    {
        for(int j=y;j<=n;j+=lowbit(j))
        {
            c[i][j] += k;
        }
    }
}

int getsum(int x,int y)   //求单点的值
{
    int res = 0;
    for(int i=x;i>0;i-=lowbit(i))
    {
        for(int j=y;j>0;j-=lowbit(j))
        {
            res += c[i][j];
        }
    }
    return res;
}

int main()
{
    IO;
    cin>>t;
    while(t--)
    {
        cin>>n>>q;
        memset(c,0,sizeof(c));
        char order;
        int x1,y1,x2,y2;
        while(q--)
        {
            cin>>order;
            if(order == 'C')
            {
                cin>>x1>>y1>>x2>>y2;
                update(x1,y1,1);
                update(x1,y2+1,-1);
                update(x2+1,y1,-1);
                update(x2+1,y2+1,1);
            }else
            {
                cin>>x1>>y1;
                cout<<getsum(x1,y1)%2<<endl;
            }
        }
        if(t!=0) cout<<endl;
    }
    return 0;
}