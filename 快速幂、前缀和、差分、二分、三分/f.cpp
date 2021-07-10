#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+10;
set<long long> s;
map<long long,int> mp;
long long n,k;
long long a[maxn];
long long sum[maxn];
int main() {
    scanf("%lld%lld",&n,&k);
    sum[0] = 0;
    s.clear();mp.clear();
    for(int i=1;i<=n;i++) {
        scanf("%lld",&a[i]);
        sum[i] = sum[i-1] + a[i];
    }
    long long count = 0;
    long long temp = 1;
    if(k == 1) s.insert(1);
    else if(k == -1) s.insert(1),s.insert(-1);
    else {
        while(abs(temp) < 1e14+1) {
            s.insert(temp);
            temp *= k;
        }
    }
    mp[0] = 1;
    for(int i=1;i<=n;i++) {
        for(set<long long>::iterator it=s.begin();it!=s.end();it++) {
            temp = sum[i] - *it;
            count += mp[temp];
        }
        mp[sum[i]]++;
    }
    printf("%lld\n",count);
    return 0;
}