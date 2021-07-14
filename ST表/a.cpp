#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 5e4+10;
int Log2[maxn];
int n,q,x,y;
int a[maxn];
int st1[maxn][21],st2[maxn][21];
void init() {
    Log2[1] = 0;
    for(int i=2;i<=n;i++) {
        Log2[i] = Log2[i/2]+1;
    }
}
int quert_min(int l,int r) {
    int len = Log2[r-l+1];
    return min(st1[l][len],st1[r-(1<<len)+1][len]);
}
int quert_max(int l,int r) {
    int len = Log2[r-l+1];
    return max(st2[l][len],st2[r-(1<<len)+1][len]);
}

int main() {

    scanf("%d%d",&n,&q);
    init();
    for(int i=1;i<=n;i++) {
        scanf("%d",&a[i]);
        st1[i][0] = st2[i][0] = a[i];
    }
    for(int i=1;i<=20;i++) {
        for(int j=1;j+(1<<i)-1<=n;j++) {
            st1[j][i] = min(st1[j][i-1],st1[j+(1<<(i-1))][i-1]);
            st2[j][i] = max(st2[j][i-1],st2[j+(1<<(i-1))][i-1]);
        }
    }
    for(int i=1;i<=q;i++) {
        scanf("%d%d",&x,&y);
        printf("%d\n",quert_max(x,y)-quert_min(x,y));
    }


    return 0;
}