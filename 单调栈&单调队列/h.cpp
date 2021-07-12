#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5+10;
int n;
int a[maxn],id[maxn];
int l[maxn],r[maxn];
int top,s[maxn];
int main() {
    scanf("%d",&n);
    for(int i=1;i<=n;i++) {
        scanf("%d",&a[i]);
        id[a[i]] = i;
    }
    a[0] = a[n+1] = INT32_MAX;
    top = 0; s[0] = 0; 
    for(int i=1;i<=n;i++) {
        while(a[i] > a[s[top]]) top--;
        l[i] = s[top]+1;
        s[++top] = i;
    }
    top = 0; s[0] = n+1;
    for(int i=n;i>=1;i--) {
        while(a[i] > a[s[top]]) top--;
        r[i] = s[top]-1;
        s[++top] = i;
    }
    long long ans = 0;
    for(int i=1;i<=n;i++) {
        if(i - l[i] < r[i] - i) {
            for(int k=l[i];k<i;k++) {
                if(id[a[i]-a[k]] > i && id[a[i]-a[k]] <= r[i]) ans++;
            }
        }else {
            for(int k=i+1;k<=r[i];k++) {
                if(id[a[i]-a[k]] < i && id[a[i]-a[k]] >= l[i]) ans++;
            }
        }
    }

    printf("%lld\n",ans);

}