#include <iostream>
#include <cstdio>
#include <cstring>
#define max(a,b) ((a>b) ? (a) : (b))
using namespace std;
const int maxn = 1e5+10;
int n,p;
long long ans;
int a[maxn],s[maxn],w[maxn];

int main() {
    while(~scanf("%d",&n) && n) {
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        ans = p = a[n+1] = 0;
        memset(s,0,sizeof(s));
        memset(w,0,sizeof(w));
        for(int i=1;i<=n+1;i++) {
            if(a[i] > s[p]) {
                s[++p] = a[i];
                w[p] = 1;
            }else {
                int len = 0;
                while(s[p] > a[i]) {
                    len += w[p];
                    ans = max(ans,1ll * len * s[p]);
                    p--;
                }
                s[++p] = a[i];
                w[p] = len+1;
            }
        }
        printf("%lld\n",ans);
    }
}