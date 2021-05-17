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
 * @date: 2021-05-02  12:53:06 
***/

const int maxn=1e5+10;
const int mod=1e9+7;
long long a[maxn];
long long c[maxn];   //存差分 a[i]-a[i-1];
long long b[maxn];    //存 i*c[i];


void update(int i,long long k)  // (a,b)+k  =>  a + k && b+1 - k
{
    int index = i;
    while(index<=maxn)
    {
        c[index] += k;
        b[index] += (i-1)*k;
        index += lowbit(index);
    }
}

long long getsum(int x)
{
    long long ans = 0;
    long long an = 0;
    int index = x;
    while(index > 0)
    {
        an += c[index];
        ans += b[index];
        index -= lowbit(index);
    }    
    ans = x*an - ans;
    return ans;
}

int main()
{
    int n,q;
    long long temp;
    memset(a,0,sizeof(a));
    memset(b,0,sizeof(b));
    memset(c,0,sizeof(c));
    scanf("%d%d",&n,&q);
    for(int i=1;i<=n;i++)
    {
        scanf("%lld",&a[i]);
        update(i,a[i]-a[i-1]);
    }
    getchar();
    char ch;
    int x,y;
    for(int i=0;i<q;i++)
    {
        scanf("%c",&ch);
        if(ch == 'Q')
        {
            scanf("%d%d",&x,&y);
            getchar();
            printf("%lld\n",getsum(y)-getsum(x-1));
        }else
        {
            scanf("%d%d%lld",&x,&y,&temp);
            getchar();
            update(x,temp);
            update(y+1,-temp);
        }
    }
    return 0;
}