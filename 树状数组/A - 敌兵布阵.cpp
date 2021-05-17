#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <algorithm>
#include <vector>
#include <cmath>
#define endl "\n"
#define LL long long
#define IO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define debug(x); cout<<x<<endl;
using namespace std;

/***
 * Author Informathons :
 * @author: JokerNoCry
 * @date: 2021-04-17  13:22:06 
***/

const int maxn=1e5+10;
const int mod=1e9+7;
int t,n;
int a[maxn];
int c[maxn];

int lowbit(int x)
{
    return x&-x;
}

void update(int i,int k)
{
    while(i<=n)
    {
        c[i] += k;
        i += lowbit(i);
    }
}

int getsum(int x)
{
    int ans = 0;
    while(x>0)
    {
        ans += c[x];
        x -= lowbit(x);
    }
    return ans;
}

int main()
{
    IO;
    cin>>t;
    int CASE = 1;
    while(t--)
    {
        cout<<"Case "<<CASE++<<":\n";
        cin>>n;
        for(int i=1;i<=n;i++) 
        {
            cin>>a[i];
            update(i,a[i]);
        }
        string order;
        while(cin>>order)
        {
            int x,y;
            if(order[0] == 'E') break;
            else if(order[0] == 'A')
            {
                cin>>x>>y;
                update(x,y);
            }else if(order[0] == 'S')
            {
                cin>>x>>y;
                update(x,-y);
            }else
            {
                cin>>x>>y;
                cout<<getsum(y) - getsum(x-1)<<endl;
            }
        }
    }
    return 0;
}