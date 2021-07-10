#include <bits/stdc++.h>
using namespace std;
const int maxn = 3e5;
int n,m,k,q;
int a[510][510];
struct pixels {

    int x,y;
    int t;

}pix[maxn];
bool check(int num) {
    memset(a,0,sizeof(a));
    for(int i=0;i<num;i++) {
        a[pix[i].x][pix[i].y] = 1;
    }
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=m;j++) {
            a[i][j] += a[i-1][j] + a[i][j-1] - a[i-1][j-1];
        }
    }
    for(int i=k;i<=n;i++) {
        for(int j=k;j<=m;j++) {
            //i-k+1,j-k+1;
            int temp = a[i][j] - a[i-k][j] - a[i][j-k] + a[i-k][j-k];
            if(temp == k*k) return true;
        }
    }
    return false;
}
int main() {

    scanf("%d%d%d%d",&n,&m,&k,&q);
    for(int i=0;i<q;i++) {
        scanf("%d%d%d",&pix[i].x,&pix[i].y,&pix[i].t);
    }
    sort(pix,pix+q,[](pixels t1,pixels t2){ return t1.t < t2.t;});
    int l=0,r=q;
    while(l < r) {
        int mid = l + (r-l)/2;
        if(check(mid)) {
            r = mid;
        }else {
            l = mid + 1;
        }
    }
    if(!check(l)) {
        printf("-1\n");
    }else {
        printf("%d\n",pix[l-1].t);
    }
    return 0;
}