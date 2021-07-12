# Problemset

[快速幂、前缀和、差分、二分、三分](https://vjudge.ppsucxtt.cn/contest/445350)

 A POJ 2559 Largest Rectangle in a Histogram  
 B POJ 2823 Sliding Window  
 C HDU 3401 Trade  
 D POJ 1821 Fence  
 E POJ 2373 Dividing the Path  
 F HDU 4374 One hundred layer  
 G CF 372C  Watching Fireworks is Fun  
 H CF 1156E Special Segments of Permutation  
 
## 思路
 
### A [POJ 2559](http://poj.org/problem?id=2559) Largest Rectangle in a Histogram  

单调栈

时间复杂度O(n)

任意一个矩形要想参与构成更大的矩形那一定不能有比它更低的矩形出现，所以我们可以利用一个单调递增的栈来保存每个矩形的高度，同时用一个数组记录当一个矩形入栈时有多少比它高被出栈了。
每出栈一个元素我们就计算一下他所能构成的面积，更新最大值就行了。

![矩形图](https://img-blog.csdnimg.cn/20210712133714766.png)

如果要想使用绿色的矩形，那么前面的所有蓝色矩形就都得出栈，然后将绿色矩形的长度更新为绿色长度+出栈的蓝色长度，也就是4；
蓝色的每出栈一个就要就要计算一下面积，用它的高乘以标记它的宽度。更新答案，最后一个数据结束后要在入栈一个0，确保所有元素已出栈，栈为空。

### B [POJ 2823](http://poj.org/problem?id=2823) Sliding Window  

单调队列

时间复杂度O(n)

如果滑动窗口比数据长度短的话，直接暴力就行了。
如果数据长度比滑动窗口大。就可以用一个单调队列来实现求区间最大和区间最小。
求最大的时候就用一个单调递减的队列，如果当前元素比队尾元素大，就出队。然后把当前元素入队。
在判断一下对头元素还在不在滑动窗口里，如果不在就出队。这是队首元素就是当前滑动窗口的最大值。
求最小值时类似。

### C [HDU 3401](https://acm.dingbacode.com/showproblem.php?pid=3401) Trade  

dp+单调队列

时间复杂度O(n^2^)

dp[i][j] 表示第i天持有j股票的最大收益

状态转移公式很容易就能想到：

现在有j股，什么都不用做就是j股    dp[i][j] = max(dp[i][j],dp[i-1][j]);
现在有k股，再买(j-k)股就变成j股了 dp[i][j] = max(dp[i][j],dp[i-W-1][k]-(j-k)*Ap[i]);
现在有k股，再卖(k-j)股就变成j股了 dp[i][j] = max(dp[i][j],dp[i-W-1][k]+(k-j)*Bp[i]);

但是如果要枚举每一个k的话差不多时间复杂度就到了O(n^3^),肯定是要超时的。

所以我们要想办法去掉一维，如果我们直到k取多少的时候是最优解，那就不用枚举每一个k了，这样就能把时间复杂度降到O(n^2^)了

我们观察式子dp[i-W-1][k]-(j-k)\*Ap[i],我们把和k有关的项提取出来就变成了dp[i-W-1][k]+k\*Ap[i]-j\*Ap[i];如果我们知道了dp[i-W-1][k]+k\*Ap[i]的最大值，就不用枚举k了，这个能用单调队列实现。

每遍历一个j就把W+1天前的dp[i-W-1][j]+j\*Ap[i]push到一个单调递减的队列中去，并用一个数组pos保存当前的j，使用的时候判断一下j和pos[i]的插值是不是超过了当天的限制交易量，根据情况出队就行了。

因为可以从k股买(j-k)股到j股，也可以从k股卖(k-j)股到j股。所以正反两边循环就行了。

初始是假设所有股票都是当天买的，初始话dp

i < W+1 天的时候不能交易直接continue就行(i-W-1是负数，数组越界)


### D [POJ 1821](http://poj.org/problem?id=1821) Fence  

dp+单调队列

时间复杂度O(n^2^)

dp[i][j] 为i个工人涂j个板

状态转移方程为：

第i个人什么都不做  dp[i][j] = max(dp[i][j],dp[i-1][j]);
第i个人涂(j-k)个板 dp[i][j] = max(dp[i][j],dp[i-1][k]+(j-k)\*per[i].p)

式子中k是变量，可以用单调队列优化掉 把式子变形为dp[i-1][k]-k\*per[i].p+j\*per[i].p ,所以每次只用知道dp[i-1][k]-k\*per[i].p的最大值就行了，用一个单调递增的队列存储。

用pos记录当前位置j，判断队首元素的pos和工人i的l之和时候能到j如果不能就出队。

### E [POJ 2373](http://poj.org/problem?id=2373) Dividing the Path  

dp+单调队列

时间复杂度O(n)

dp[i] 表示覆盖(0,i)最少需要多少的喷水器

状态转移方程为:

dp[i] = min(dp[i],dp[k]+1);

只要知道最小的dp[k]就行了，借助单调递增的队列，将dp[i-2*a] 入队，pos数组记录当前位置i

如果当前位置i和队首元素pos之差超过2*b说明这个喷水器喷不到了，出队。

### F [HDU 4374](https://acm.dingbacode.com/showproblem.php?pid=4374) One hundred layer

dp+单调队列

时间复杂度O(n^2^)

dp[i][j] 表示到第i层第j位置时的最大积分

很显然如果是从上一层k位置下来的  dp[i][j] = max(dp[i][j],dp[i-1][k]+c[k]+···+c[j]);

很显然每次都累加c[k]~c[j]的话是在白浪费时间，可以用一个前缀和来保存c数组，c[k]~c[j] = sum[j]-sum[k-1]

这样时间复杂度还是不够，需要使用单调队列优化掉k，不能每次都遍历k

一共有两个方向，分开讨论

从左往右时，(k < j)   dp[i][j] = max(dp[i][j],dp[i-1][k]+(sum[j]-sum[k-1]));
从右往左时, (k > j)   dp[i][j] = max(dp[i][j],dp[i-1][k]+(sum[k]-sum[j-1]));

提取出来k,式子变为 dp[i-1][k]-sum[k-1] + sum[j];  单调队列保存dp[i-1][j]-sum[j-1]; pos数组保存当前位置j

只能移动t步，当前位置j和队首元素pos相差超过t就要出队

反方向类似

首层需要单独考虑，有t的限制不是所有位置到能到，所以dp初始化为很小的负数就行，到不了就是最小的负数。

遍历底层更新答案



### G [CF 372C](https://codeforces.com/problemset/problem/372/C) Watching Fireworks is Fun  

dp+单调队列

时间复杂度O(n^2^)

dp[i][j] 表示放第i个烟花的时候在位置j得到的最大幸福

不难想到你是从位置k移动到j的，所以状态转移方程为：

dp[i][j] = max(dp[i][j],dp[i-1][k]+b[i]-abs(a[i]-j));

写完之后先不管时间怎么样，反正内存时爆掉了，开不了dp[i][j]这么大的数组，观察发下dp[i][]只和dp[i-1]有关，
而答案只和dp[m][]有关,所以我们不需要dp[i][j]了，我们只需要三个数组save[]保存dp[i-1],now[]保存dp[i],更新完后把now[]再拷贝到dp[i]就行了，反正这些操作都是O(n)的，多来几次也没啥影响(总复杂度O(n^2^，相比较而言影响小))。

继续优化时间复杂度(把k去掉)

使用单调递增的队列保存save[j],pos数组记录当前位置j

如果当前位置j和队首的pos相差超过d\*(t[i][t[i-1])了说明跑不过来，出队

可以从左过来，也可以从右过来，再倒着重复一边就行了

最后遍历dp更行答案

### H [CF 1156E](https://codeforces.com/problemset/problem/1156/E) Special Segments of Permutation  
 
单调栈

时间复杂度O(nlogn)

如果直接遍历的话会超时，但是我们缩减范围，数组里没0，所以如果一个数左右两边各有一个数相加等于它，而且它还是这两个数之间最大的数，那只要遍历每个数两边比它小的数就行了，遇到比它大的肯定就跟它没关系了

比如 2  4  3 1 5     对于4的右边只需要考虑3和1，跟5没关系，不然5就是最大的了。

所以我们要利用单调栈求出左右两边的范围，利用单调递减的栈就行了，每次入栈时弹出比它小的元素，栈顶元素就是第一个比它大的，根据情况记录位置，然后把这个元素入栈。

求另一边的范围时就反着再来一遍就行了。

a[0] 和 a[n+1]设为极大值，设定边界。

有了范围就能遍历每个数两边的值，看一看有没有相加等于这个数的，统计一下。

但是发现这样还是会超时，还需要再优化，我们发现对于 

pi  pk  pj

pi + pj = pk

那pi = pk - pj ，我们只要与遍历一边，然后减一下看看对应的数在不在另一边就行，这个可以一开始用一个数组id记录每个数的位置，如果id[pi] < id[pk] 就说明pi在pk的左边，现在只需要看id[pk-pj]和id[pk]的关系就行了。

我们可以先判断左右哪边的数少就遍历那边。
