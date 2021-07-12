#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn = 2e4;
struct person {
    int l,p,s;
}per[maxn];
int n,k;
int dp[110][maxn];
int head,tail,que[maxn];
int pos[maxn];
bool cmp(person a,person b) {
    return a.s < b.s;
}
int main() {
    scanf("%d%d",&n,&k);
    for(int i=1;i<=k;i++) {
        scanf("%d%d%d",&per[i].l,&per[i].p,&per[i].s);
    }
    sort(per+1,per+1+k,cmp);
    memset(dp,0,sizeof(dp));
    for(int i=1;i<=k;i++) {
        head = tail = 0;
        for(int j=max(0,per[i].s-per[i].l);j<per[i].s;j++) {
            int temp = dp[i-1][j] - j*per[i].p;
            while(head < tail && que[tail-1] < temp) tail--;
            que[tail]   = temp;
            pos[tail++] = j;
        }       
        for(int j=1;j<=n;j++) {     
            dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            //dp[i][j] = dp[i-1][k] + (j-k)*per[i].p;
            //         = dp[i-1][k] - k*per[i].p + j*per[i].p; 
            if(j < per[i].s || j > per[i].s + per[i].l) continue;
            while(head < tail && pos[head] + per[i].l < j) head++;
            if(head < tail) dp[i][j] = max(dp[i][j],que[head] + j*per[i].p);
        }
    }
    printf("%d\n",dp[k][n]);
    return 0;
}