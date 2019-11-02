/*
问题描述：
    有n种不同大小的数字a_i，每种m_i个。判断是否可以从中选出若干使总和为K
*/

#include <iostream>
#define Max_N   105
#define Max_K   100005
using namespace std;

int n,K;
int a[Max_N],m[Max_N];
bool dp[Max_N][Max_K];
int Dp[Max_N][Max_K];
int DP[Max_K];

//基本动态规划
void solve1()
{
    //初始化
    for(int i=1; i<=K; i++)
        dp[0][i]=false;
    for(int i=0; i<=n; i++)
        dp[i][0]=true;
    //递推
    for(int i=1; i<=n; i++)
        for(int j=1; j<=K; j++)
            for(int k=0; k<=m[i]&&k*a[i]<=j; k++)
                dp[i][j]|=dp[i-1][j-k*a[i]];
    //结果
    if(dp[n][K])
        cout<<"Yes"<<endl;
    else
        cout<<"NO"<<endl;
}
//优化动态规划
void solve2()
{
    //初始化
    for(int i=1; i<=K; i++)
        Dp[0][i]=-1;
    for(int i=1; i<=n; i++)
        Dp[i][0]=m[i];
    Dp[0][0]=0;
    //递推
    for(int i=1; i<=n; i++)
        for(int j=1; j<=K; j++)
        {
            if(Dp[i-1][j]>=0)
                Dp[i][j]=m[i];
            else if(j<a[i]||Dp[i][j-a[i]]<=0)
                Dp[i][j]=-1;
            else
                Dp[i][j]=Dp[i][j-a[i]]-1;
        }

    if(Dp[n][K]>=0)
        cout<<"YES"<<endl;
    else
        cout<<"NO"<<endl;
}

//内存优化，数组重用
void solve3()
{
    for(int i=1; i<=K; i++)
        DP[i]=-1;
    DP[0]=0;
    for(int i=1; i<=n; i++)
        for(int j=0; j<=K; j++)
        {
            if(DP[j]>=0)
                DP[j]=m[i];
            else if(j<a[i]||DP[j-a[i]]<=0)
                DP[j]=-1;
            else
                DP[j]=DP[j-a[i]]-1;
        }
    if(DP[K]>=0)
        cout<<"YES"<<endl;
    else
        cout<<"NO"<<endl;
}

int main()
{
    cin>>n>>K;
    for(int i=1; i<=n; i++)
        cin>>a[i]>>m[i];
    solve1();
    solve2();
    solve3();
    return 0;
}
/*
3 17
3 3
5 2
8 2
*/
