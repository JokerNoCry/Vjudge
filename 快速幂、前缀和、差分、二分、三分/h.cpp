#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5+10;
string a,b;
int idex[maxn];

bool check(int len) {
    bool sign[maxn];
    memset(sign,true,sizeof(sign));
    for(int i=0;i<len;i++) {
        sign[idex[i]-1] = false;
    }
    int la = a.length();
    int lb = b.length();
    int p = 0;
    for(int i=0;i<la;i++) {
        if(sign[i] && p < lb && a[i] == b[p]) p++;
    }
    if( p == lb ) return true;
    else return false; 
}

int main() {
    cin>>a>>b;
    int len = a.length();
    for(int i=0;i<len;i++) {
        cin>>idex[i];
    }
    int l=0,r=len;
    while(l<r)
    {
        int mid = r-(r-l)/2;
        if(check(mid)) {
            l = mid;
        }else {
            r = mid - 1;
        }
    }
    cout<<l;
}