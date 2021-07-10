# Problemset

[快速幂、前缀和、差分、二分、三分](https://vjudge.ppsucxtt.cn/contest/445350)

 A	CF 457C	    Elections  
 B	HDU 6514	Monitor  
 C	CF 1073C	Vasya and Robot  
 D	CF 520C	    DNA Alignment  
 E	CF 348A	    Mafia  
 F	CF 776C	    Molly's Chemicals  
 G	HDU 6276	Easy $h$-index  
 H	CF 779D	    String Game  
 I	CF 846D	    Monitor  
 J	Gym 102059J	Histogram Sequence  
 
## 思路
 
### A [CF 456C](https://codeforces.com/problemset/problem/457/C)  Elections 
 
三分查找

时间复杂度O(logn)

考虑两种特殊的情况，如果全部贿赂肯定是能竞选成功，但是这样会花费很大，如果全都不贿赂，不能保证一定贿赂成功。这是会发现有一种情况既能竞选成功，又能花费最小，如果把竞选失败当成是花费无限钱的话，这就相当于是在一个凹曲线找极小值。所以用三分。

从左右两点之间找两个中点，分别计算需要会费的金钱，如果竞选失败就是花费无限金钱(赋一个很大的值，比如INT32_MAX)。然后分别比较mid1和mid2的大小，缩减区间范围直到L>R，在过程中记录最小值就行了。

check函数如下
```cpp
long long check(int Mid)  // Mid 贿赂的人数
{
    int sum = num[0]+Mid;  // 贿赂完总票数
    int tot = 0;long long res = 0;  // 所有必须贿赂的及总价钱
    //票数比我多的都必须得贿赂
    for(int i=1;i<1e5+1;i++)
    {
        for(int j=0;j<=max(-1,num[i]-sum);j++)
        {
            tot++;
            //直接从头开删，需要提前排序
            res += G[i][j];
        } 
    }
    // 必须贿赂的人数比当前贿赂的多，这种方案肯定不行，返回一个比较大的值；
    if(tot > Mid) return INT64_MAX;
    // tot <= Mid 的时候还需要继续贿赂，剩下的人只用贿赂钱少的就行
    //  用一个数组存起来剩下的，然后排序 q用来存
    int cnt = 0;
    for(int i=1;i<1e5+1;i++)
    {
        //有的已经贿赂过了，需要删掉
        //  num[i] 比 sum 大的全都删了
        //贿赂的话一定贿赂了 num[i]-sum人
        for(int j=max(0,num[i]-sum+1);j<num[i];j++)
        {
            q[cnt++] = G[i][j];
        }
    }
    sort(q,q+cnt);
    //还需贿赂 Mid-tot人
    for(int i=0;i<Mid-tot;i++)
    {
        res += q[i];
    }
    return res;
}
```



### B	[HDU 6514](https://acm.dingbacode.com/showproblem.php?pid=6514)	Monitor  

二维前缀和

时间复杂度O(n^2^)

我可以把监控都能看到的点设为1。然后对小偷出现的范围求和，如果大小等于小偷出现范围的面积，就是可以看到，否则看不到。

一开始赋值的时候也可以考虑使用差分，当输入完所有的摄像头范围后求一遍前缀和就得到了每个点的值，然后将它的bool值赋值给他就保证了了有监控的点是1。因为无论有几个监控找照到都是照到，所以只关心它是不是0，所以可以用bool值。之后在求一遍前缀和，方便查询。查询的时候直接做差就能求出区域面积

n和m的值不固定，但n\*m的值是有范围的，如果开二维数组太大了，开不了，所以用一维数组模拟一下二维数组就行了。比如前x个元素是第一行，再x个元素是第二行，以此类推，要求第i行第j列就算一下就行 (i-1)\*x+j

![1](https://img-blog.csdnimg.cn/20210710101205137.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3FxXzMwNDQ1Mzk3,size_16,color_FFFFFF,t_70)

蓝 = 总 - (红+黄) - (红+绿) + 红

这就是二维差分与前缀和的思想

### C	[CF 1073C](https://codeforces.com/problemset/problem/1073/C)	Vasya and Robot  

二分查找+前缀和

时间复杂度O(nlogn)

通过二分区间长度找到合适的值，先记录每一部的x，y轴操作的前缀和。

一个点能到达另一个点的条件有两个 （距离是指abs(x1-x2)+abs(y1-y2)）
- 移动步数要不小于两点间距离
- 移动步数与两点间距离奇偶性要一致(相当于走多了要走回来，如果奇偶性不一致，比如你多走了3步，但你只能往回走2步或者4步，你一定到不了终点)

记录x，y轴操作的前缀和 就是说如果是R可以x+1，如果是L可以x-1类似的
这样sumx[i] 就是i次操作后当前的x轴坐标是哪里。

这样你check的时候枚举每一个长度为len的区间只要用
sum[n] - (sum[i+len] - sum[i]) 就能直到你当前的位置了。


### D	[CF 520C](https://codeforces.com/problemset/problem/520/C)	    DNA Alignment  

快速幂

时间复杂度O(logn)

ACG无论匹配什么，匹配一轮后结果都不会大于3

以为如果是ACG与ACG的话，相当于第一次是3，然后变成ACG与CGA没有匹配的然后ACG与GAC也没有匹配的。
如果是ACG与AAA的话每次都只有一个匹配的。
计算ρ就是将一轮的结果乘n就行了。
以为ACG循环三次分别是ACG、CGA、GAC，他们匹配的对象也分别是ACG、CGA、GAC，CGA与ACG匹配跟ACG与ACG匹配是一样的结果。

AACC 中出现的最多的是A和C，那么答案的xxxx四位中可以任意的填A和C，结果是一样的即相当于每个位置有2种选择

所以这题就相当于找出现次数最多的字母的数量，记为count，答案就是count^n

[快速幂知识](https://blog.csdn.net/qq_30445397/article/details/103463751)

### E	[CF 348A](https://codeforces.com/problemset/problem/384/A)	    Mafia  

二分查找

通过二分玩的总次数，找到需要玩的最小次数

check函数就检查当前查找的len次行不行。
我只需要统计每个人能当裁判的次数总和与总次数的关系就行了。就是累加(总次数-第i个人想玩的次数)

- 如果每个人能当裁判的次数总和小于总次数就说明当前的总次数太小了，不行。
-  如果每个人能当裁判的次数总和大于等于总次数就说明每回合都至少能找到一人当裁判

### F	[CF 776C](https://codeforces.com/problemset/problem/776/C)	    Molly's Chemicals 

前缀和

时间复杂度O(nlogn)

我要求有几个区间的和等于k的幂(可以是一次幂、二次幂······)，无论怎样你到需要直到区间和是多少，所以这个问题可以用前缀和来解决。

区间(i,j) 的和 就是sum[j] - sum[i]

如果我们枚举每一个区间的话，时间复杂度就是O(n^2^)显然不行，我们需要优化，我们观察这个式子，我们要求：

sum[j] - sum[i] = k^x^
因为i，j的范围是(1,n)所以导致时间复杂度O(n^2^)的，但是x的范围不会太大a最大是1e9，最多有1e5的数，所以最大区间是1e14，那么k^x^一定不会超过1e14了，
1^X^ = 1，我们先不考虑1，最小的k就是2，2^64^就是比long long 的最大值还大了，所以x一定不会超过64，甚至更小。那我们把式子变形一下：

sum[j] - k^x^ = sum[i]

这样枚举j和x，时间复杂度O(nlogn)

我们把k^x^存在一个set中，这样就不用每次都求一遍了，然后遍历这个set就行了，可以用迭代器之类的。
然后用map记录sum[i]的数量，这样答案每次直接加map[sum[i]]就行了。


### G	[HDU 6276](https://acm.dingbacode.com/showproblem.php?pid=6276)	Easy $h$-index  

前缀和

时间复杂度O(n)

要求最大的h使得至少有h个大于等于h的paper

我们可以通过前缀和来实现，我们求后缀和，然后判断
sum[i] 是不是 大于等于 i，遇到第一个成立的i就是最大值。边求和边判断更快。



### H	[CF 779D](https://codeforces.com/problemset/problem/779/D)	    String Game  

二分查找

时间复杂度O(nlogn)

二分你可以删除的个数就行了。
check函数只用O(n)的判断一下你想要的字符串还在不在就行了。

### I	[CF 846D](https://codeforces.com/problemset/problem/846/D)	    Monitor  

二维前缀和 + 二分查找

时间复杂度O(n^2^logn)

先把所有用到的坏点按用到的时间排序，时间小的排在前面，然后二分查找用多少点后会导致显示器坏。

check函数可以将坏的点标记成1，好的点标记成0，求一下前缀和。然后枚举每一个k\*k的区域，利用前缀和求出k\*k区域的和，然后判断它是不是等于k\*k如果等于就说明显示器坏了。



### J	[Gym 102059J](https://codeforces.com/gym/102059/problem/J)	Histogram Sequence  


