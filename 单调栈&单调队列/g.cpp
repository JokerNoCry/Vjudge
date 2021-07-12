#include <bits/stdc++.h>
#define max(a,b) ((a>b) ? (a):(b))
#define min(a,b) ((a<b) ? (a):(b))
using namespace std;
const int maxn = 2e5;
int n,m,d;
long long a[310],b[310],t[310];
long long dp[maxn];  //dp[i][j]  放i个再位置j
long long save[maxn];
long long now[maxn];
int head,tail;
long long que[maxn];
long long pos[maxn];
int main() {
    memset(dp,0,sizeof(dp));
    scanf("%d%d%d",&n,&m,&d);
    for(int i=1;i<=m;i++) scanf("%I64d%I64d%I64d",&a[i],&b[i],&t[i]);
    for(int i=1;i<=n;i++) dp[i] = b[1] - abs(a[1]-i);
    for(int i=2;i<=m;i++) {
        for(int i=1;i<=n;i++) {
            save[i] = dp[i];
            now[i] = INT64_MIN/2;
        }
        head = tail = 0;
        for(int j=1;j<=n;j++) {
            long long temp = save[j];
            while(head < tail && que[tail-1] < temp) tail--;
            que[tail] = temp;
            pos[tail++] = j;
            while(head < tail && j-pos[head] > d*(t[i]-t[i-1])) head++;
            now[j] = max(now[j],que[head]+b[i] - abs(a[i]-j));
        }
        head = tail = 0;
        for(int j=n;j>=1;j--) {
            long long temp = save[j];
            while(head < tail && que[tail-1] < temp) tail--;
            que[tail] = temp;
            pos[tail++] = j;
            while(head < tail && pos[head]-j > d*(t[i]-t[i-1])) head++;
            now[j] = max(now[j],que[head]+b[i] - abs(a[i]-j));
        }
        for(int i=1;i<=n;i++) {
            dp[i] = now[i];
        }
    }
    long long ans = INT64_MIN;
    for(int i=1;i<=n;i++) {
        ans = max(ans,dp[i]);
    }
    printf("%I64d\n",ans);
    return 0;
}