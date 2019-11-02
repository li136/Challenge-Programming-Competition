/*
驾驶一辆汽车行驶L单位距离，卡车上有P单位的汽油，每行驶一单位距离，消耗一单位的汽油。
途中有N个加油站，第i个加油站距离终点Ai单位的距离，最多可以给卡车加Bi单位汽油。
求卡车是否能到达终点，若可以，输出最少需要加多少次油，否则输出-1.
*/

#include<queue>
#include<cstdio>
#include<algorithm>
using namespace std;

const int MAX_N=1000000+10;

//输入
int L,P,N;
int A[MAX_N+1,B[MAX_N+1];
 
void solve()
{
    A[N]=L;
    B[N]=0;
    N++;

    priority_queue<int> que;

    int ans=0,pos=0,tank=P;

    for（int i=0;i<N;i++）
    {
        int d=A[i]-pos;

        while(tank-d < 0)
        {
            if(que.empty())
            {
                puts("-1");
                return;
            }
            tank += que.top();
            que.pop();
            ans++;
        }
        tank -= d;
        pos = A[i];
        que.push(B[i]);
    }
    printf("%d\n",ans);
}