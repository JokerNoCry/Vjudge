#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn = 1e6+10;
int n,k;
int head,tail;
int a[maxn];
struct Node
{
    int first;
    int second;
}q[maxn];
int main() {
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++) {
        scanf("%d",&a[i]);
    }
    if(k >= n) {
        int minnum = 1e9+10;
        int maxnum = 0;
        for(int i=1;i<=n;i++) {
            minnum = min(minnum,a[i]);
            maxnum = max(maxnum,a[i]);
        }
        printf("%d\n%d\n",minnum,maxnum);
        return 0;
    }
    tail = head = 0;
    for(int i=1;i<=n;i++) {  
        while(head < tail && q[tail-1].first >= a[i]) tail--;
        q[tail].first = a[i];q[tail++].second = i;
        while(q[head].second < i-k+1) head++;
        if(i >= k) {
            printf("%d ",q[head].first);
        }   
    }
    printf("\n");
    tail = head = 0; // tail = head 队列为空
    for(int i=1;i<=n;i++) {  
        while(head < tail && q[tail-1].first <= a[i]) tail--;
        q[tail].first = a[i];q[tail++].second = i;
        while(q[head].second < i-k+1) head++;
        if(i >= k) {
            printf("%d ",q[head].first);
        }
    }
    printf("\n");
}





