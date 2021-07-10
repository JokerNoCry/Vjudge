#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+10;
int num[maxn];
vector<int>G[maxn];
int n;
int q[maxn];
long long check(int Mid)  // Mid 贿赂的人数
{
    int sum = num[0]+Mid;  // 贿赂完总票数
    int tot = 0;long long res = 0;  // 所有必须贿赂的及总价钱
    //票数比我多的都必须得贿赂
    for(int i=1;i<1e5+1;i++)
    {
        for(int j=0;j<=max(-1,num[i]-sum);j++)
        {
            tot++;
            //直接从头开删，需要提前排序
            res += G[i][j];
        } 
    }
    // 必须贿赂的人数比当前贿赂的多，这种方案肯定不行，返回一个比较大的值；
    if(tot > Mid) return INT64_MAX;
    // tot <= Mid 的时候还需要继续贿赂，剩下的人只用贿赂钱少的就行
    //  用一个数组存起来剩下的，然后排序 q用来存
    int cnt = 0;
    for(int i=1;i<1e5+1;i++)
    {
        //有的已经贿赂过了，需要删掉
        //  num[i] 比 sum 大的全都删了
        //贿赂的话一定贿赂了 num[i]-sum人
        for(int j=max(0,num[i]-sum+1);j<num[i];j++)
        {
            q[cnt++] = G[i][j];
        }
    }
    sort(q,q+cnt);
    //还需贿赂 Mid-tot人
    for(int i=0;i<Mid-tot;i++)
    {
        res += q[i];
    }
    return res;
}

int main()
{
    int a,b;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d%d",&a,&b);
        if(a == 0 || b == 0) num[0]++;
        else num[a]++,G[a].emplace_back(b);
    }
    // 可能不需要贿赂就已经行了,可以一边排序，一边判断
    bool flag = true;
    for(int i=1;i<1e5+1;i++)
    {
        sort(G[i].begin(),G[i].end());
        if(num[i] >= num[0]) flag = false;
    }
    if(flag) 
    {
        printf("0\n");
        return 0;
    }
    //需要删除的时候三分
    int L = 1, R = n;
    long long ans = INT64_MAX;
    while(L<=R)
    {
        int mid1 = L+(R-L)/3;
        int mid2 = R-(R-L)/3;
        long long f1 = check(mid1);
        long long f2 = check(mid2);
        if(f1<=f2)
        {
            R = mid2-1;
            ans = min(ans,f1);
        }else
        {
            L = mid1+1;
            ans = min(ans,f2);
        }
    }
    printf("%lld\n",ans);
    return 0;
}