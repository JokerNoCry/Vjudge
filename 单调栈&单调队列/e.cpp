#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
const int maxn = 1e3+10;
int n,l;
int a,b;
struct cow
{
    int s,e;
}c[maxn];
int dp[maxn*maxn];
int sign[maxn*maxn];
int head,tail,que[maxn*maxn];
int pos[maxn*maxn];
int main() {
    scanf("%d%d",&n,&l);
    scanf("%d%d",&a,&b);
    for(int i=1;i<=n;i++) scanf("%d%d",&c[i].s,&c[i].e);
    memset(dp,0x77,sizeof(dp));
    memset(sign,0,sizeof(sign));
    for(int i=1;i<=n;i++) {
        for(int j=c[i].s+1;j<c[i].e;j++) {
            sign[j] = 1;
        }
    }
    dp[0] = 0;
    head = tail = 0;
    for(int i=2*a;i<=l;i+=2) {
        while(head < tail && que[tail-1] > dp[i-2*a]) tail--;
        que[tail] = dp[i-2*a];
        pos[tail++] = i-2*a;
        while(head < tail && pos[head] < i-2*b) head++;
        if(sign[i]) continue; 
        if(head < tail) dp[i] = min(dp[i],que[head]+1); 
        
    }
    if(dp[l] > l) dp[l] = -1;
    printf("%d\n",dp[l]);

    return 0;
}