#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <queue>
 
using namespace std;
 
typedef long long LL;
 
const int N = 1000;
const int INF = 0x3f3f3f3f;
//可以使用memset(array, 0x3f, sizeof(array))来为数组设初值为0x3f3f3f3f，因为这个数的每个字节都是0x3f
 
int dis[N], G[N][N], n, s;
bool vis[N];
 
void dijkstra()
{
    for(int i = 1; i <= n; i++)
        dis[i] = G[1][i];//代表起点到各个节点的距离
    dis[1] = 0;
    for(int i = 1; i <= n; i++)//这里也可以事先标记起点已访问，然后遍历n-1个节点
    {
        int k = -1;
        for(int j = 1; j <= n; j++)
        {
            if(!vis[j] && (k==-1 || dis[j]<dis[k]))
                k = j;
        }
        if(k == -1) break;//已经遍历所有的点
        vis[k] = true;
        for(int j = 1; j <= n; j++)
        {
            if(!vis[j]) dis[j] = min(dis[j], dis[k]+G[k][j]);
        }
    }
    printf("%d\n", dis[n]);
}
 
void floyd()
{
    for(int k = 1; k <= n; k++)
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= n; j++)
                G[i][j] = min(G[i][j], G[i][k]+G[k][j]);
    printf("%d\n", G[1][n]);
}
 
void spfa()
{
    queue<int>que;
    for(int i = 1; i <= n; i++)
        dis[i] = INF;//初值记得赋无穷，而不是G数组中的值！
    dis[1] = 0;
    vis[1] = true;
    que.push(1);
    while(!que.empty())
    {
        int now = que.front();
        que.pop();
        vis[now] = false;//记得还原！！
        for(int i = 1; i <= n; i++)
        {
            if(dis[now]+G[now][i]<dis[i])
            {
                dis[i] = dis[now]+G[now][i];
                if(!vis[i])
                {
                    vis[i] = true;
                    que.push(i);
                }
            }
        }
    }
    printf("%d\n", dis[n]);
}
 
int main()
{
   // freopen("in.txt", "r", stdin);
    int m, e, w;
    while(~scanf("%d%d", &n, &m))
    {
        if(n == 0 && m == 0) break;
        memset(vis, 0, sizeof(vis));
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= n; j++)
            {
                if(i == j) G[i][j] = 0;
                else G[i][j] = INF;
            }
        for(int i = 1; i <= m; i++)
        {
            scanf("%d%d%d", &s, &e, &w);
            G[s][e] = G[e][s] = w;
        }
      //  dijkstra();
     // floyd();
        spfa();
    }
    return 0;
}