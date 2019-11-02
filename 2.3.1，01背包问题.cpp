/*
 问题描述：
 有n个重量和价值分别为w-i，v-i的物品，从中挑出总重量不超过W的作品，求价值总和的最大值。
*/

#include<cstdio>
#include<algorithm>
#include<cstdlib>
//输入
const int MAX_N=100+5;
const int MAX_W=10000;

int n,W;
int w[MAX_N],v[MAX_N];

//有三种解决方案


//1,二叉树递归
int rec(int i,int j)
{
    int res;
    if(i==n) res=0;
    else if(j<w[i]) res=rec(i+1,j);
    else res=max(rec(i+1,j),rec(i+1,j-w[i])+v[i]);//max()函数
    return res;
}


//2,记录结果重复上次计算
int dp[MAX_N+1][MAX_W+1];

int rec(int i,int j)//i表示已经挑选到第i个物品。j表示剩余空间。
{
    if(dp[i][j]>=0)
        return dp[i][j];
    int res;
    if(i==n) res=0;//已经没东西可拿了。当我们指向最后一个物品是时，处理的是拿不拿下一个物品的决策。
    else if(j<w[i]) res=rec(i+1,j);
    else res=max(rec(i+1,j),rec(i+1,j-w[i])+v[i]);
    
    return dp[i][j]=res;
}

void solve()
{
    memset(dp,-1,sizeof(dp));
    printf("%d\n",rec(0,W));
}


//不写递归函数，直接递推出数组。
//在这里有正向递推和反向递推。正向递推需修改i,j定义。--在前i个物品中选出总重量不超过j的物品的最大值。
int dp[MAX_N+1][MAX_W+1];

void solve()
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<=W;j++)
        {
            if(j<w[i]) dp[i+1][j]=dp[i][j];
            else dp[i+1][j]=max(dp[i][j],dp[i][j-w[i]]+v[i]);
        }
    }
    printf("%d\n",dp[n][W]);
}

//另外还有状态转移-由一个dp[i][j]的值推后面两个的值dp[i+1][j]和dp[i+1][j+w[i]]