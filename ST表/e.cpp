#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 1e5+10;
int n,q,x,y;
int a[maxn];
int Log2[maxn];
int st[maxn][21];
struct Data {
    int num;
    int left;
    int right;
    int count;
}block[maxn];

void input() {
    block[0].num = -0x3f3f3f3f;
    block[0].left = 0;
    block[0].count = 0;
    int temp;
    int now = 0;
    for(int i=1;i<=n;i++) {
        scanf("%d",&temp);
        if(temp == block[now].num) {
            block[now].count++;
            a[i] = now;
        }else {
            block[now].right = i-1;
            now++;
            block[now].num = temp;
            block[now].left = i;
            block[now].count = 1;
            a[i] = now;
        }
    }
    block[now].right = n;
}

void init() {
    Log2[0] = -1;
    for(int i=1;i<=n;i++) {
        Log2[i] = Log2[i/2] + 1;
        st[i][0] = block[a[i]].count;
    }
    for(int i=1;i<=20;i++) {
        for(int j=1;j+(1<<i)-1<=n;j++) {
            st[j][i] = max(st[j][i-1],st[j+(1<<(i-1))][i-1]);
        }
    }
}

int query(int l,int r) {
    int len = Log2[r-l+1];
    return max(st[l][len],st[r-(1<<len)+1][len]);
}

int main() {
    while((~scanf("%d",&n)) && n) {
        scanf("%d",&q);
        input();
        init();
        for(int i=1;i<=q;i++) {
            scanf("%d%d",&x,&y);
            if(a[x] == a[y]) {
                printf("%d\n",y-x+1);
            }else if(a[y] - a[x] == 1) {
                int t1 = block[a[x]].count - (x - block[a[x]].left);
                int t2 = block[a[y]].count - (block[a[y]].right - y);
                printf("%d\n",max(t1,t2));
            }else {
                int t1 = block[a[x]].count - (x - block[a[x]].left);
                int t2 = block[a[y]].count - (block[a[y]].right - y);
                int ans = max(t1,t2);
                x = block[a[x]].right+1;
                y = block[a[y]].left-1;
                ans = max(ans,query(x,y));
                printf("%d\n",ans);
            }
        }
    }
}