/*### P1216 [USACO1.5][IOI1994]数字三角形
https://www.luogu.com.cn/problem/P1216
#### 思路：
#### 设dp[i][j]表示从(1,1)到(i,j)的最大和
#### 所以递推式为dp[i][j]=max(f[i-1][j],f[i-1][j-1])+a[i][j]
#### 因为(i,j)这个点只能从(i-1,j)和(i-1,j-1)出发到达
#### 有一说一，数组还是得开大，不然会RE。。
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
int a[1005][1005];
int dp[1005][1005];
int main(int argc, char const *argv[])
{
    int n;
    cin>>n;
    for (int i = 1; i <= n; ++i)
    {
        for(int j = 1; j <= i; j++){
            cin>>a[i][j];
            dp[i][j] = a[i][j];
        }
    }
    for(int i = n-1; i >= 1; --i){
        for(int j = 1; j <= i; ++j)
            dp[i][j] = max(dp[i+1][j],dp[i+1][j+1])+a[i][j];
    }
    cout<<dp[1][1];
    return 0;
}
```
