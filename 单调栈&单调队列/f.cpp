#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e4+10;
int n,m,x,t;
int c[110][maxn];
int dp[110][maxn];
int sum[110][maxn];
int head,tail,que[maxn];
int pos[maxn];
int main() {
    //freopen("data.in","r",stdin);
    while(~scanf("%d%d%d%d",&n,&m,&x,&t)) {
        for(int i=0;i<=n;i++) {
            for(int j=0;j<=m;j++) {
                dp[i][j] = INT32_MIN/2;
            }
        }
        memset(sum,0,sizeof(sum));
        for(int i=1;i<=n;i++) {
            for(int j=1;j<=m;j++) {
                scanf("%d",&c[i][j]);
                sum[i][j] = sum[i][j-1]+c[i][j];
            }
        }
        for(int i=max(1,x-t);i<=min(m,x+t);i++) {
            if(i > x) dp[1][i] = max(dp[1][i],sum[1][i]-sum[1][x-1]);
            else dp[1][i] = max(dp[1][i],sum[1][x]-sum[1][i-1]); 
        }
        for(int i=2;i<=n;i++) {
            head = tail = 0;
            //dp[i-1][k]-sum[i][k-1]+sum[i][j];
            for(int j=1;j<=m;j++) {
                int temp = dp[i-1][j]-sum[i][j-1];
                while(head < tail && que[tail-1] < temp) tail--;
                que[tail] = temp;
                pos[tail++] = j;
                while(head < tail && j-pos[head] > t) head++;
                dp[i][j] = max(dp[i][j],que[head] + sum[i][j]);
            }
            head = tail = 0;
            //dp[i-1][k]+sum[i][k]-sum[i][j-1];
            for(int j=m;j>=1;j--) {
                int temp = dp[i-1][j]+sum[i][j];
                while(head < tail && que[tail-1] < temp) tail--;
                que[tail] = temp;
                pos[tail++] = j;
                while(head < tail && pos[head]-j > t) head++;
                dp[i][j] = max(dp[i][j],que[head] - sum[i][j-1]);
            }
        }
        int ans = INT32_MIN;
        for(int i=1;i<=m;i++) {
            ans = max(ans,dp[n][i]);
        }
        printf("%d\n",ans);
    }
    return 0;
}