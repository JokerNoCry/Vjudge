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
 * @date: 2021-05-02  12:16:41 
***/

const int maxn=1e3+10;
const int mod=1e9+7;

struct node
{
    int b,e;
}a[maxn*maxn];
int t,n,m,k;
int c[maxn];
bool cmp(node x,node y)
{
    if(x.b == y.b)
        return x.e<y.e;
    return x.b < y.b;
}

void update(int x,int k)
{
    while(x<=m)
    {
        c[x] += k;
        x += lowbit(x);
    }
}

int getsum(int x)
{
    int res = 0;
    while(x > 0)
    {
        res += c[x];
        x -= lowbit(x);
    }
    return res;
}

int main()
{
    scanf("%d",&t);
    for(int tc=1;tc<=t;tc++)
    {
        memset(c,0,sizeof(c));
        scanf("%d%d%d",&n,&m,&k);
        int t1,t2;
        for(int i=0;i<k;i++)
        {
            scanf("%d%d",&a[i].b,&a[i].e);
        }
        sort(a,a+k,cmp);
        LL ans = 0;
        for(int i=0;i<k;i++)
        {
            ans += getsum(m) - getsum(a[i].e);
            update(a[i].e,1);
        }
        printf("Test case %d: %lld\n",tc,ans);
    } 
    return 0;
}