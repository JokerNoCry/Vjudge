#include <bits/stdc++.h>
using namespace std;
const int maxn = 301;
int m,n,q,r1,r2,c1,c2;
int a[maxn][maxn];
unsigned int st[maxn][maxn][9][9];
unsigned int Log2[maxn];
void init() {
    Log2[0] = -1;
    for(int i=1;i<=max(m,n);i++) Log2[i] = Log2[i/2] + 1;
    for(int i=1;i<=m;i++) {
        for(int j=1;j<=n;j++) {
            st[i][j][0][0] = a[i][j];
        }
    } 
    for(int k1=0;k1<9;k1++) {
        for(int k2=0;k2<9;k2++) {
            if(k1 == 0 && k2 == 0) continue;
            for(int i=1;i+(1<<k1)-1<=m;i++) {
                for(int j=1;j+(1<<k2)-1<=n;j++) {
                    if(k1 != 0) {
                        st[i][j][k1][k2] = max(st[i][j][k1-1][k2],st[i+(1<<(k1-1))][j][k1-1][k2]);
                    }else {
                        st[i][j][k1][k2] = max(st[i][j][k1][k2-1],st[i][j+(1<<(k2-1))][k1][k2-1]);
                    }
                }
            }
        }
    }
}

unsigned query(int r1,int c1,int r2,int c2) {
    int len1 = Log2[r2-r1+1];
    int len2 = Log2[c2-c1+1];
    unsigned int ans = 0;
    ans = max(ans,st[r1][c1][len1][len2]);
    ans = max(ans,st[r1][c2-(1<<len2)+1][len1][len2]);
    ans = max(ans,st[r2-(1<<len1)+1][c1][len1][len2]);
    ans = max(ans,st[r2-(1<<len1)+1][c2-(1<<len2)+1][len1][len2]);
    return ans;
}

int main() {
    while(~scanf("%d%d",&m,&n)) {
        for(int i=1;i<=m;i++) {
            for(int j=1;j<=n;j++) {
                scanf("%ud",&a[i][j]);
            }
        }
        init();
        scanf("%d",&q);
        while(q--) {
            scanf("%d%d%d%d",&r1,&c1,&r2,&c2);
            unsigned int out = query(r1,c1,r2,c2);
            bool flag = false;
            if(out == a[r1][c1]) flag = true;
            if(out == a[r2][c2]) flag = true;
            if(out == a[r1][c2]) flag = true;
            if(out == a[r2][c1]) flag = true;
            if(flag) printf("%d yes\n",out);
            else printf("%d no\n",out); 
        }
    }
    return 0;
}
