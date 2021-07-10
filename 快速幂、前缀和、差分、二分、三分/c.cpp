#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5+10;
int n;
string s;
int x,y;
int sumx[maxn];
int sumy[maxn];

bool check(int len)
{
    for(int i=1;i+len-1<=n;i++)
    {
        int _x = sumx[n] - sumx[i+len-1] + sumx[i-1];
        int _y = sumy[n] - sumy[i+len-1] + sumy[i-1];

        int sum = abs(x-_x)+abs(y-_y);
        if(sum <= len && (sum & 1) == (len & 1))
        {
            return true;
        }
    }
    return false;
}


int main()
{
    cin>>n>>s>>x>>y;
    int all = abs(x) + abs(y);
    if(all > n || (all & 1) != (n & 1))
    {
        cout<<"-1\n";
        return 0;
    }
    sumx[0] = sumy[0] = 0;
    for(int i=0;i<n;i++)
    {
        sumx[i+1] = sumx[i];
        sumy[i+1] = sumy[i];
        if(s[i] == 'L') sumx[i+1] = sumx[i] - 1;
        else if(s[i] == 'R') sumx[i+1] = sumx[i] + 1;
        else if(s[i] == 'U') sumy[i+1] = sumy[i] + 1;
        else sumy[i+1] = sumy[i] - 1; 
    }
    int l = 0,r = n;
    while(l<r)
    {
        int mid = l + (r-l)/2;
        if(check(mid))
        {
            r = mid;
        }else
        {
            l = mid+1;
        }
    }
    cout<<r<<endl;
    return 0;
}