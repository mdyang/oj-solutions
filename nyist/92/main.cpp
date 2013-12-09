#include<iostream>
#include<deque>
#include<memory.h>
using namespace std;
typedef unsigned short uc;
uc image[961][1441];
typedef struct _p{
    uc x;uc y;}p;
uc w,h;
void push(deque<p>& q,uc x,uc y){
    p p1;p1.x=x;p1.y=y;q.push_back(p1);
}

void bfs(uc x,uc y){
    deque<p> q;
    image[x][y]=0;
    push(q,x,y);
    while(!q.empty()){
        p p1=q.front();
        q.pop_front();
        //left
        if(p1.y>0&&image[p1.x][p1.y-1]){
            if(image[p1.x][p1.y-1]){
                image[p1.x][p1.y-1]=0;
                push(q,p1.x,p1.y-1);
            }
        }
        //right
        if(p1.y<w-1&&image[p1.x][p1.y+1]){
            if(image[p1.x][p1.y+1]){
                image[p1.x][p1.y+1]=0;
                push(q,p1.x,p1.y+1);
            }
        }
        //top
        if(p1.x>0&&image[p1.x-1][p1.y]){
            if(image[p1.x-1][p1.y]){
                image[p1.x-1][p1.y]=0;
                push(q,p1.x-1,p1.y);
            }
        }
        //down
        if(p1.x<h-1&&image[p1.x+1][p1.y]){
            if(image[p1.x+1][p1.y]){
                image[p1.x+1][p1.y]=0;
                push(q,p1.x+1,p1.y);
            }
        }
    }
}

void dfs(int x,int y){
    if(!image[x][y])return;
    image[x][y]=0;
    if(y>0)dfs(x,y-1);
    if(y<w-1)dfs(x,y+1);
    if(x>0)dfs(x-1,y);
    if(x<h-1)dfs(x+1,y);
}

int main(){
    int n;
    cin>>n;
    while(n--){
        memset(image,0,sizeof(image));
        cin>>w>>h;
        for(int i=0;i<h;i++)
            for(int j=0;j<w;j++)
                cin>>image[i][j];
        for(int i=0;i<w;i++){
            if(image[0][i])bfs(0,i);
            if(image[h-1][i])bfs(h-1,i);
        }
        for(int i=0;i<h;i++){
            if(image[i][0])bfs(i,0);
            if(image[i][w-1])bfs(i,w-1);
        }
        for(int i=0;i<h;i++){
            for(int j=0;j<w;j++)
                cout<<image[i][j]<<' ';
            cout<<endl;
        }
    }
    return 0;
}
