//简单照抄了书上源代码

const int MAX_N=10000;

int heap[MAX_N],sz=0;
void push(int x)
{
    int i=sz++;

    while(i>0)
    {
        int p=(i-1)/2;
        if(heap[p]<=x) break;
        heap[i]=heap[p];
        i=p;
    }
    heap[i]=x;
}

int pop()
{
    int ret=heap[0];

    int x=heap[--sz];

    int i=0;
    while(i*2+1<sz)
    {
        int a=i*2+1,b=i*2+2;
        if(b<sz && heap[b]<heap[a]) a=b;
        if(heap[a]>=x) break;
        heap[i] = heap[a];
        i=a;
    }
    heap[i]=x;

    return ret;
}

//STL的priority_queue<int> a;
//有top,pop,empty,push等常见函数
//在默认的优先队列中，优先级高的先出队。在默认的int型中先出队的为较大的数。