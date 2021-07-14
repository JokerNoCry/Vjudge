#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+10;
int n,q;
int a[maxn];  // a[i] 表示位置i的数据属于 a[i]块
int Log2[maxn];
int x,y;
int st[maxn][21];

struct Block {
    int num;
    int count;
    int left;
    int right;
}block[maxn];   //分块记录  每块记录数字，总数，左右节点

void input() {
    //read data
    int now = 0;
    block[0].num = -0x3f3f3f3f;
    block[0].count = -1;
    block[0].left = 0;
    block[0].right = 0;
    int temp;
    for(int i=1;i<=n;i++) {
        scanf("%d",&temp);
        if(temp == block[now].num) {
            a[i] = now;
            block[now].count++;
        }else {
            block[now].right = i-1;
            now++;
            block[now].left = i;
            block[now].num = temp;
            block[now].count = 1;
            a[i] = now;
        }
    }
    block[now].right = n;
}

void init() {
    //build st
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
        memset(st,0,sizeof(st));
        input();
        init();
        for(int i=1;i<=q;i++) {
            scanf("%d%d",&x,&y);
            if(a[x] == a[y]) {
                printf("%d\n",y-x+1);
            }else if(a[y] - a[x] == 1) {
                int t1 = block[a[y]].count - (block[a[y]].right-y);
                int t2 = block[a[x]].count - (x-block[a[x]].left);
                printf("%d\n",max(t1,t2));
            }else {
                int t1 = block[a[y]].count - (block[a[y]].right-y);
                int t2 = block[a[x]].count - (x-block[a[x]].left);
                x = block[a[x]].right+1; y = block[a[y]].left-1;
                int ans = max(t1,t2);
                ans = max(ans,query(x,y));
                printf("%d\n",ans);
            }
        }
    }
    return 0;
}