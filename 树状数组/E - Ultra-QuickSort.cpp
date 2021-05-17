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
 * @date: 2021-05-01  15:07:23 
***/

const int maxn=5e5+10;
const int mod=1e9+7;
struct node
{
    int num;
    int id;
}a[maxn];
int c[maxn];
int Index[maxn];
int n;
LL ans = 0;
bool cmp(node x,node y)
{
    return x.num < y.num;
}

void update(int x,int k)
{
    while(x<=n)
    {
        c[x] += k;
        x += lowbit(x);
    }
}

int getsum(int x)
{
    int res = 0;
    while(x>0)
    {
        res += c[x];
        x -= lowbit(x);
    }
    return res;
}

int main()
{
    while(scanf("%d",&n)!=EOF)
    {
        if(n == 0) break;
        memset(c,0,sizeof(c));
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&a[i].num);
            a[i].id = i;
        }
        sort(a+1,a+n+1,cmp);
        Index[a[1].id] = 1;
        for(int i=2;i<=n;i++)
        {
            if(a[i].num == a[i-1].num) Index[a[i].id] == Index[a[i-1].id];
            else Index[a[i].id] = i;
        }
        ans = 0;
        for(int i=1;i<=n;i++)
        {
            ans += i - 1 - getsum(Index[i]);
            update(Index[i],1);
        }
        printf("%lld\n",ans);
    }
    return 0;
}