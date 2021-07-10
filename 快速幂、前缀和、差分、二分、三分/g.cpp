#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5+10;

int n;
int a[maxn];
int pre[maxn];
int main()
{
    while(~scanf("%d",&n))
    {
        for(int i=0;i<=n;i++)
        {
            scanf("%d",&a[i]);
        }
        pre[n+1] = 0;
        for(int i=n;i>=0;i--)
        {
            pre[i] = pre[i+1] + a[i];
            if(pre[i] >= i)
            {
                printf("%d\n",i);
                break;
            }
        }
    }
    return 0;
}