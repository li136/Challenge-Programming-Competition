//问题描述：有n个无区别的物品，将它们划分为不超过m组，求出划分方法数模M的余数。 

/*
所有可能的情况都可以看作是把n划分成m份。只是有的是取0的。
 
思路：
定义题目为n的m划分数。
dp[i][j]表示 j 的 i 划分数。
 
 
分类讨论：
1.j >= i时，dp[i][j] = dp[i-1][j]( j的i-1划分，相当于当前位取0的全部情况 ) + dp[i][j-i]（当前位不取0，先把每一个置为1，再将剩下的j-i分下去）;
2.j < i时，dp[i][j] = dp[i-1][j];  当前位只能取0。
*/

#include<cstdio>  
#include<cstring>
#include<iostream>
using namespace std;

int dp[1010][1010];

int main()  
{  
  int n,m,mod;
  cin >> n >> m >> mod;
  
  
  for(int i = 1;i <= m; i++)
    {
      for(int j = 0;j <= n; j++)
        {
            if(j - i >= 0)
          {
              dp[i][j] = (dp[i-1][j] + dp[i][j-i])%mod;
          }
          else
          {
              dp[i][j] = dp[i-1][j];
          }
        }
    }
    
    cout << dp[m][n] << endl;
    return 0;  
}   