//1.0
#include <iostream>
#include <string.h>
using namespace std;
int dp[1010][1010];
int value[1010];
int volume[1010];
int n,v,t,ans;
int dfs(int i,int vi)
{
    if(dp[i][vi]>0) return dp[i][vi];
    int res;
    if(i>n) res=0;
    else if(vi<volume[i]) res=dfs(i+1,vi);
    else res=max(dfs(i+1,vi),dfs(i+1,vi-volume[i])+value[i]);
    return dp[i][vi]=res;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>t;
    while(t--)
    {
	cin>>n>>v;
	memset(dp,-1,sizeof(dp));
	memset(value,0,sizeof(value));
	memset(volume,0,sizeof(volume));
	for(int i=1;i<=n;i++) cin>>value[i];
	for(int i=1;i<=n;i++) cin>>volume[i];
	ans=dfs(1,v);
	cout<<ans<<"\n";
    }
    return 0;
}
//2.0
#include <iostream>
#include <string.h>
using namespace std;
int dp[1010][1010];
int value[1010],volume[1010];
int n,v,t;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>t;
    while(t--)
    {
	cin>>n>>v;
	memset(dp,0,sizeof(dp));
	memset(value,0,sizeof(value));
	memset(volume,0,sizeof(volume));
	for(int i=1;i<=n;i++) cin>>value[i];
	for(int i=1;i<=n;i++) cin>>volume[i];
	for(int i=1;i<=n;i++)
	{
	    for(int j=v;j>=0;j--)
	    {
		if(j<volume[i]) dp[i][j]=dp[i-1][j];
		else dp[i][j]=max(dp[i-1][j],dp[i-1][j-volume[i]]+value[i]);
	    }
	}
	cout<<dp[n][v]<<"\n";
    }
    return 0;
}
//3.0
#include <iostream>
#include <string.h>
using namespace std;
int dp[1010];
int value[1010];
int volume[1010];
int n,v,t;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>t;
    while(t--)
    {
	memset(dp,0,sizeof(dp));
	memset(value,0,sizeof(value));
	memset(volume,0,sizeof(volume));
	cin>>n>>v;
	for(int i=1;i<=n;i++) cin>>value[i];
	for(int i=1;i<=n;i++) cin>>volume[i];
	for(int i=1;i<=n;i++)
	{
	    for(int j=v;j>=volume[i];j--)
	    {
		dp[j]=max(dp[j-volume[i]]+value[i],dp[j]);
	    }
	}
	cout<<dp[v]<<"\n";
    }
    return 0;
}
