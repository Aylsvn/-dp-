/*### P1048 [NOIP2005 普及组] 采药
https://www.luogu.com.cn/problem/P1048
#### 思路：
#### 这题就是很经典的01背包问题，所以很容易得出状态转移方程=
### dp[i][j]=max(dp[i−1][j],dp[i−1][j−time[i]]+val[i])(j>=time[i])
#### //代码里是ti[i],因为洛谷上编译time这个命名报错，我自己的编译器是没有报错的，不懂。
#### 而不采摘(背包容量不够),则时间不变,当前采摘的药等于采摘的第i-1株药
### dp[i][j] = dp[i - 1][j] ;
#### 代码如下：
```*/
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<map>
#include<stack>
#include<queue>
using namespace std;
const int maxn = 1e7+10;
const int mod = 1e8-3;
const int inf = 0x3f3f3f;
int ti[1005],val[1005];
int dp[1005][1005];
int main()
{
    int t,m;
    cin>>t>>m;
    for(int i = 1 ; i <= m ; ++i)
    {
        cin>>ti[i]>>val[i];
        for(int j = 1 ; j <= t ; ++j)
        {
            dp[i][j] = dp[i-1][j];
            if(j >= ti[i]) 
                dp[i][j] = max(dp[i][j],dp[i-1][j-ti[i]] + val[i]);
        }
    }
    cout<<dp[m][t];
    return 0;
}
```
