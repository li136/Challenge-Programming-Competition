//表示节点的结构体
struct node
{
    int val;
    node *lch, *rch;
};

//插入数值x
node *insert(node *p,int x)
{
    if(p==nullptr)
    {
        node *q=new node;
        q->val=x;
        q->lch=q->rch=nullptr;
        return q;
    }
    else
    {
        if(x < p->val)  p->lch= insert(p->lch,x);
        else  p->rch=insert(p->rch,x);
        return p;
    }
}

//查找数值
bool find(node *p,int x)
{
    if(p==nullptr)  return false;
    else if(x==p->val)  return true;
    else if(x<p->val)   return find(p->lch,x);
    else return find(p->rch,x);
}
 
//删除数值x
node *remove(node *p,int x)
{
    if(p==nullptr)  return nullptr;
    else if()//懒得写了
}
