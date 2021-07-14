#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+10;
int Log2[maxn];
int n,s,l;
int a[maxn];
int st1[maxn][31],st2[maxn][31];
int dp[maxn];
void init() {
    Log2[1] = 0;
    for(int i=2;i<=n;i++) {
        Log2[i] = Log2[i/2] + 1;
    }
    memset(dp,0x3f,sizeof(dp));
}
int query(int l,int r) {
    int len = Log2[r-l+1];
    return max(st2[l][len],st2[r-(1<<len)+1][len]) - min(st1[l][len],st1[r-(1<<len)+1][len]);
}
int main()
{
    scanf("%d%d%d",&n,&s,&l);
    init();
    for(int i=1;i<=n;i++) {
        scanf("%d",&a[i]);
        st1[i][0] = st2[i][0] = a[i];
    }
    for(int i=1;i<=30;i++) {
        for(int j=1;j+(1<<(i-1))-1<=n;j++) {
            st1[j][i] = min(st1[j][i-1],st1[j+(1<<(i-1))][i-1]);
            st2[j][i] = max(st2[j][i-1],st2[j+(1<<(i-1))][i-1]);
        }
    }
    dp[0] = 0;
    int pre = 0;
    for(int i=1;i<=n;i++) {
        while(i-pre >= l && (query(pre+1,i) > s || dp[pre] == 0x3f3f3f3f)) pre++;
        if(i-pre >= l) {
            dp[i]= min(dp[pre]+1,dp[i]);
        }
    }
    if(dp[n] == 0x3f3f3f3f) printf("-1\n");
    else printf("%d\n",dp[n]);

    return 0;
}