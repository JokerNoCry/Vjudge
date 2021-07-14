#include <bits/stdc++.h>
using namespace std;
const int maxn = 1010;
string s,t;
int n,m;
int st[maxn][21];
int Log2[maxn];
int ans[maxn];
void init() {
    Log2[0] = -1;
    for(int i=1;i<=n;i++) {
        Log2[i] = Log2[i/2] + 1;
        st[i][0] = i;
    }
    for(int i=1;i<=20;i++) {
        for(int j=1;j+(1<<i)-1<=n;j++) {
            //st[j][i] = min(st[j][i-1],st[j+(1<<(i-1))][i-1]);
            if(s[st[j][i-1]] <= s[st[j+(1<<(i-1))][i-1]]) st[j][i] = st[j][i-1];
            else st[j][i] = st[j+(1<<(i-1))][i-1];
        }
    }
}

int query(int l,int r) {
    int len = Log2[r-l+1];
    //min(st[l][len],st[r-(1<<len)+1][len]);
    if(s[st[l][len]] <= s[st[r-(1<<len)+1][len]]) return st[l][len];
    else return st[r-(1<<len)+1][len];
}

int main() {
    //n个数里删除m个  就相当于保留 n-m 个；
    // 第一个数在(1,x) 则x最大为 n-x = n-m-1 x = m+1;  第二个数 在(temp,m+2)······;
    while(cin>>t>>m) {
        s = "0"+t;
        n = s.length()-1;
        init();
        ans[0] = 0;
        int cnt = 0;
        if(n == m) {
            cout<<"0\n";
            continue;
        }
        int temp = 1;
        for(int i=1;m+i<=n;i++) {
            temp = query(temp,m+i);
            ans[++cnt] = s[temp++]-'0';
        }
        int cnt1 = 1;
        while(ans[cnt1] == 0) cnt1++;
        if(cnt1 > cnt) cout<<"0";
        for(;cnt1<=cnt;cnt1++) {
            cout<<ans[cnt1];
        }
        cout<<"\n";
    }
}