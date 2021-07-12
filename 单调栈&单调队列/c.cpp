#include <bits/stdc++.h>
using namespace std;
const int maxn = 2010;
int t,T,MaxP,W;
int ap[maxn],bp[maxn],as[maxn],bs[maxn];
int dp[maxn][maxn];
int head,tail,que[maxn],num[maxn];
int main() {
    
    scanf("%d",&t);
    while(t--) {
        scanf("%d%d%d",&T,&MaxP,&W);
        for(int i=1;i<=T;i++) {
            scanf("%d%d%d%d",&ap[i],&bp[i],&as[i],&bs[i]);
        }
        memset(dp,10000000,sizeof(dp));
        for(int i=1;i<=T;i++) {
            for(int j=0;j<=min(MaxP,as[i]);j++) {
                dp[i][j] = max(dp[i][j],-j*ap[i]);
            }
        }
        for(int i=2;i<=T;i++) {
            dp[i][0] = max(dp[i][0],0);
            for(int j=0;j<=MaxP;j++) {
                dp[i][j] = max(dp[i][j],dp[i-1][j]);
            }
            //dp[i][j] = max(dp[i][j],dp[i][k] - (j-k)*ap[i]);
            //  dp[i][k] + k*ap[i] - j*ap[i];
            //dp[i][j] = max(dp[i][j],dp[i][k] + (k-j)*bp[i]);
            //  dp[i][k] + k*bp[i] - j*bp[i];
            if(i < W+1) continue;
            head = tail = 0;
            for(int j=0;j<=MaxP;j++) {
                int temp = dp[i-W-1][j] + j*ap[i];
                while(head < tail && que[tail-1] < temp) tail--; 
                que[tail]     = temp;
                num[tail++] = j;
                while(head < tail && j-num[head] > as[i]) head++;
                dp[i][j] = max(dp[i][j],que[head]-j*ap[i]); 
            }
            head = tail = 0;
            for(int j=MaxP;j>=0;j--) {
                int temp = dp[i-W-1][j] + j*bp[i];
                while(head < tail && que[tail-1] < temp) tail--;
                que[tail]     = temp;
                num[tail++] = j;
                while(head < tail && num[head]-j > bs[i]) head++;
                dp[i][j] = max(dp[i][j],que[head]-j*bp[i]);
            }
        }
        int ans = 0;
        for(int i=0;i<=T;i++) {
            ans = max(ans,dp[T][i]);
        }
        printf("%d\n",ans);
    }
    
    return 0;
}
