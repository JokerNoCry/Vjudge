#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e3+10;
int dp[maxn][maxn];      //dp[i][j] 第i天持有j股票 赚多少钱
int t,T,MaxP,W;          //T天数  MaxP最多数量  W间隔天数
int ap[maxn],bp[maxn];   //ap买入价格  bp卖出价格
int as[maxn],bs[maxn];   //as买入数量  bs卖出数量
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
        //如果第i天不交易，那就跟第i-1天一样
        //如果第i天交易了，那结果取决于i-W-1天
        for(int i=2;i<=T;i++) {
            for(int j=0;j<=MaxP;j++) {
                //1.不交易
                dp[i][j] = max(dp[i][j],dp[i-1][j]);
                //2.买k股
                if(i < W+1) continue;
                for(int k=1;k<=min(j,as[i]);k++) {
                    dp[i][j] = max(dp[i][j],dp[i-W-1][j-k]-k*ap[i]);
                }   
                //3.卖出k股
                for(int k=1;k<=min(MaxP-j,bs[i]);k++) {
                    dp[i][j] = max(dp[i][j],dp[i-W-1][j+k]+k*bp[i]);
                }
            }
        }
        int ans = INT32_MIN;
        for(int i=0;i<=MaxP;i++) {
            ans = max(ans,dp[T][i]);
        }
        printf("%d\n",ans);
    }
}