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
 * @date: 2021-04-30  17:53:32 
***/

const int maxn=150;
const int mod=1e9+7;

int c[maxn][maxn];
bool flag[maxn][maxn];
int t;

void update(int x,int y,int k)
{
    for(int i=x;i<=maxn;i+=lowbit(i))
    {
        for(int j=y;j<=maxn;j+=lowbit(j))
        {
            c[i][j] += k;
        }
    }       
}

int getsum(int x,int y)
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
    cin>>t;
    string order;
    int x,y,l;
    memset(c,0,sizeof(c));
    memset(flag,false,sizeof(flag));
    while(t--)
    {
        cin>>order>>x>>y>>l;
        if(order[0] == 'B')
        {
            for(int i=x;i<x+l;i++)
            {
                for(int j=y;j<y+l;j++)
                {
                    if(!flag[i][j])
                    {
                        update(i,j,1);
                        flag[i][j] = true;
                    }
                }
            }
        }else if(order[0] == 'W')
        {
            for(int i=x;i<x+l;i++)
            {
                for(int j=y;j<y+l;j++)
                {
                    if(flag[i][j])
                    {
                        update(i,j,-1);
                        flag[i][j] = false;
                    }
                }
            }
        }else
        {
            cout<<getsum(x+l-1,y+l-1)-getsum(x-1,y+l-1)-getsum(x+l-1,y-1)+getsum(x-1,y-1)<<endl;
        }
    }
    return 0;
}