#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+10;
int n;
long long sum;
long long a[maxn];

bool check(long long num) {
    long long sup = 0;
    for(int i=0;i<n;i++) {
        if(num < a[i]) return false;
        sup += num - a[i];
    }
    if(sup < num) return false;
    else return true;
}

int main() {
    sum = 0;
    cin>>n;
    for(int i=0;i<n;i++) {
        cin>>a[i];
        sum += a[i];
    }
    long long l = 0,r=sum;
    while(l < r) {
        long long mid = l + (r-l)/2;
        if(check(mid)) {
            r = mid;
        }else {
            l = mid+1;
        }
    }
    cout<<r<<endl;
    return 0;
}