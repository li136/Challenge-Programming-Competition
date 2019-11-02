//问题描述：给定一个无序数组，求最长子序列。

//时间复杂度n*logn

#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;

const int MAX = 1000 + 10;
const int inf = 1000000;

int a[MAX];
int dp[MAX];

void solve(int n)
{
	fill(dp, dp + n, inf);
	for (int i = 0; i < n; i++)
	{
		*lower_bound(dp, dp + n, a[i]) = a[i];
	}
	printf("%d", lower_bound(dp, dp + n, inf) - dp);
}

int main()
{
	int n;
	//输入
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	solve(n);
	return 0;
}