#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define CLR(arr,val) memset(arr,val,sizeof(arr))
const int M=5010,ME=100000;
int INF=0x3fffffff;
class MaxFlow
{
public:
    void clear()
    {
        CLR(Head,-1);top=0;CLR(Flow,0);
    }
    void add(int u,int v,int cap,int cost)
    {
        Next[top] = Head[u];
        Num[top] = v;
        Cap[top] = cap;
        Cost[top] = cost;
        Head[u] = top++;

        Next[top] = Head[v];
        Num[top] = u;
        Cap[top] = 0;
        Cost[top] = -cost;
        Head[v] = top++;
    }
    int GetMinCostMaxFlow(int s,int t) //·µ»Ø×îÖÕµÄcost
    {
        int cost = 0;
        while(SPFA(s,t))
        {
            int cur = t,minflow = INF;
            while(cur != s)
            {
                if(minflow > Cap[pre_edge[cur]]-Flow[pre_edge[cur]])
                    minflow = Cap[pre_edge[cur]]-Flow[pre_edge[cur]];
                cur = Num[pre_edge[cur] ^ 1];
            }
            cur = t ;
            while(cur != s)
            {
                Flow[pre_edge[cur]] += minflow;
                Flow[pre_edge[cur] ^ 1] -= minflow;
                cost += minflow * Cost[pre_edge[cur]];
                cur = Num[pre_edge[cur] ^ 1];
            }
        }
        return cost;
    }
private:
    bool SPFA(int s,int t)
    {
        fill(Len,Len+M,-INF);
        Len[s]=0;
        int head = -1,tail = -1,cur;
        Q[++head] = s;
        while(head != tail)
        {
            ++tail;
            if(tail >= M) tail -= M;
            cur = Q[tail];
            for(int i = Head[cur];i != -1;i = Next[i])
            {
                if(Cap[i]>Flow[i] && Len[Num[i]] < Len[cur] + Cost[i])
                {
                    Len[Num[i]] = Len[cur] + Cost[i];
                    ++head;
                    if(head >= M) head -= M;
                    pre_edge[Num[i]] = i;
                    Q[head] = Num[i];
                }
            }
        }
        return Len[t] != -INF;
    }
    int Head[M],Next[ME],Num[ME],Flow[ME],Cap[ME],Cost[ME],Q[ME],InQ[M],Len[M],pre_edge[M],top;
};
MaxFlow g;
int data;
int main()
{
    int t,m,n;
    scanf("%d",&t);
    while(t--)
    {
        g.clear();
        scanf("%d%d",&m,&n);
        g.add(0,1,2,0);
        g.add(2*(m*n-1),2*(m*n-1)+1,2,0);
        for(int i = 0; i != m; i++)
            for(int j = 0;j != n;j++)
            {
                scanf("%d",&data);
                if(i > 0) g.add(2*((i-1)*n+j)+1,2*(i*n+j),1,0);
                if(j > 0) g.add(2*(i*n+j-1)+1,2*(i*n+j),1,0);
                if(!(i==0 && j==0)&& !(i == m-1 && j == n-1))
                    g.add(2*(i*n+j),2*(i*n+j)+1,1,data);
            }
        printf("%d\n",g.GetMinCostMaxFlow(0,2*(m*n-1)+1));
    }
}
