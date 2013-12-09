#include<stdio.h>
#include<deque>
using namespace std;
int t;
int matrix[1002][1002];
struct p{
    int i,j;};
void bfs(){
    deque<p> q;
    p ip;
    ip.i=0;ip.j=0;
    q.push_back(ip);
    while(!q.empty()){
        ip=q.front();
        q.pop_front();
        matrix[ip.i][ip.j]=0;
        p np;
        np=ip;
        np.i--;
        if(np.i>=0&&matrix[np.i][np.j])q.push_back(np);
        np=ip;
        np.i++;
        if(np.i<=t+1&&matrix[np.i][np.j])q.push_back(np);
        np=ip;
        np.j--;
        if(np.j>=0&&matrix[np.i][np.j])q.push_back(np);
        np=ip;
        np.j++;
        if(np.j<=t+1&&matrix[np.i][np.j])q.push_back(np);
    }
}
int count(){
    int ret=0;
    for(int i=0;i<=t+1;i++)
        for(int j=0;j<=t+1;j++)
            if(matrix[i][j])ret++;
    return ret;
}
int main(){
    scanf("%d",&t);
    for(int i=0;i<=t+1;i++){
        matrix[0][i]=
            matrix[i][0]=
            matrix[t+1][i]=
            matrix[i][t+1]=255;
    }
    for(int i=1;i<=t;i++)
        for(int j=1;j<=t;j++)
            scanf("%d",&matrix[i][j]);
    bfs();
    printf("%d\n",count());
    return 0;
}
