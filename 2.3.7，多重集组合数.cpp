/*
问题描述：
有n种物品，第i种物品有a_i个。不同种类可以互相区分但相同种类无法区分。
从中取出m个，有多少种取法？求方案数模M的余数
*/

#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>
#include <cmath>
using namespace std;
const int maxn =105;
int a[maxn];
int dp[maxn][maxn];

int main()
{
    int n,m;
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    int M;
    cin>>M;
    dp[0][0]=1;//空集为1
    for(int i=1;i<=n;i++)
    {
        dp[i][0]=1;
        for(int j=1;j<=m;j++)
        {
            if(j>a[i]) dp[i][j]=(dp[i-1][j]-dp[i-1][j-a[i]-1]+dp[i][j-1]+M)%M;
            else dp[i][j]=dp[i][j-1]+dp[i-1][j];
        }
    }
    printf("%d\n",dp[n][m]);
    return 0;
}
