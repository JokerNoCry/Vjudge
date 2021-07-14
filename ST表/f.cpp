#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 251;
int n,b,k,x,y;
int a[maxn][maxn];
int st1[maxn][maxn][10];
int st2[maxn][maxn][10];
int Log2[maxn];
void init() {
    Log2[0] = -1;
    for(int i=1;i<=n;i++) {
        Log2[i] = Log2[i/2]+1;
        for(int j=1;j<=n;j++) {
            st1[i][j][0] = a[i][j];
            st2[i][j][0] = a[i][j];
        }
    }
    for(int k=1;k<=9;k++) {
        for(int i=1;i+(1<<k)-1<=n;i++) {
            for(int j=1;j+(1<<k)-1<=n;j++) {
                st1[i][j][k] = st1[i][j][k-1];
                st1[i][j][k] = max(st1[i][j][k],st1[i][j+(1<<(k-1))][k-1]);
                st1[i][j][k] = max(st1[i][j][k],st1[i+(1<<(k-1))][j][k-1]);
                st1[i][j][k] = max(st1[i][j][k],st1[i+(1<<(k-1))][j+(1<<(k-1))][k-1]);
                st2[i][j][k] = st2[i][j][k-1];
                st2[i][j][k] = min(st2[i][j][k],st2[i][j+(1<<(k-1))][k-1]);
                st2[i][j][k] = min(st2[i][j][k],st2[i+(1<<(k-1))][j][k-1]);
                st2[i][j][k] = min(st2[i][j][k],st2[i+(1<<(k-1))][j+(1<<(k-1))][k-1]);
            }
        }
    }
}

int query(int x,int y) {
    //(x,y)  (x+b-1,y+b-1)
    int len = Log2[b];
    int ans1 = -0x7f7f7f7f;
    //st[l][len],st[r-(1<<len)+1][len];
    ans1 = max(ans1,st1[x][y][len]);
    ans1 = max(ans1,st1[x][y+b-(1<<len)][len]);
    ans1 = max(ans1,st1[x+b-(1<<len)][y][len]);
    ans1 = max(ans1,st1[x+b-(1<<len)][y+b-(1<<len)][len]);

    int ans2 = 0x7f7f7f7f;
    ans2 = min(ans2,st2[x][y][len]);
    ans2 = min(ans2,st2[x][y+b-(1<<len)][len]);
    ans2 = min(ans2,st2[x+b-(1<<len)][y][len]);
    ans2 = min(ans2,st2[x+b-(1<<len)][y+b-(1<<len)][len]);
    return ans1 - ans2;
}

int main() {
    scanf("%d%d%d",&n,&b,&k);
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=n;j++) {
            scanf("%d",&a[i][j]);
        }
    }
    init();
    for(int i=1;i<=k;i++) {
        scanf("%d%d",&x,&y);
        printf("%d\n",query(x,y));
    }
    return 0;
}