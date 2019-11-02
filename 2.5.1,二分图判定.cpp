/*
 问题描述：
 给定一个具有n个顶点的图，要给图上每个顶点染色，并且使相邻的顶点颜色不同。
 问能否有最多2个颜色染色。
*/  
//输入
const int MAX_V=10000;

vector<int> G[MAX_V];
int V;
int color[MAX_V];

bool dfs(int v,int c)
{
    color[v]=c;
    for(int i=0;i<G[v].size();i++)
    {
        if(color[G[v][i]]==c)  return false;
        if(color[G[v][i]]==0 && !dfs(g[v][i],-c))  return false;
    }
    return true;
}

void solve()
{
    for(int i=0;i<V;i++)
    {
        if(color[i]==0)
        {
            if(!dfs(i,1))
            {
                printf("No\n");return;
            }
        }
    }
    printf("Yes\n");
}