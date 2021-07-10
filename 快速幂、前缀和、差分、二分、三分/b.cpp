#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e7+10;
int n,m;
int p,q;
int a[maxn];

int pos(int x, int y) {
    return x * (m+1) + y; 
}

int main() {
    int x1,y1,x2,y2;
    while(~scanf("%d%d",&n,&m)) {
        n++;m++;
        memset(a,0,sizeof(a));
        scanf("%d",&p);
        for(int i=0;i<p;i++) {
            scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
            a[pos(x1,y1)]++;
            a[pos(x2+1,y2+1)]++;
            a[pos(x1,y2+1)]--;
            a[pos(x2+1,y1)]--;
        }
        for(int i=1;i<=n;i++) {
            for(int j=1;j<=m;j++) {
                a[pos(i,j)] += a[pos(i-1,j)] + a[pos(i,j-1)] - a[pos(i-1,j-1)];
            }
        }
        for(int i=1;i<=n;i++) {
            for(int j=1;j<=m;j++) {
                a[pos(i,j)] = (bool)a[pos(i,j)];
            }
        }
        for(int i=1;i<=n;i++) {
            for(int j=1;j<=m;j++) {
                a[pos(i,j)] += a[pos(i-1,j)] + a[pos(i,j-1)] - a[pos(i-1,j-1)];
            }
        }
        scanf("%d",&q);
        while(q--) {
            scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
            int area = (y2-y1+1) * (x2-x1+1);
            int monitor = a[pos(x2,y2)] - a[pos(x1-1,y2)] - a[pos(x2,y1-1)] + a[pos(x1-1,y1-1)];
            if(area == monitor) printf("YES\n");
            else printf("NO\n");
        }
    }
    
}