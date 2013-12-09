#include<stdio.h>
#include<memory.h>
#include<iostream>
using namespace std;
char maze[21][21];
bool visited[20][20];
struct point{
    int i;
    int j;
};
point start;
bool gate[26];
point gate_points[26];
bool found,sth_new;
int keycount[26];
int cur_keycount[26];
int m,n;
bool iskey(int i,int j){
    return (maze[i][j]>='a'&&maze[i][j]<='z');
}
bool isgate(int i,int j){
    return(maze[i][j]>='A'&&maze[i][j]<='Z');
}
void dfs(int i,int j){
    // skip if under/overflow, can't pass or visited
    if(i<0||j<0||i>=m||j>=n||maze[i][j]=='X'||visited[i][j])return;
//    printf("dfs(%d,%d)\n",i,j);
    // found the gold, end
    if(maze[i][j]=='G'){
        found=true;
        throw true;
    }
    // it's a visitable place
    visited[i][j]=true;
    // found a key
    if(iskey(i,j)){
        // have discovery!
        sth_new=true;
        // pick up the key
        cur_keycount[maze[i][j]-'a']++;
        maze[i][j]='.';
    }
    if(maze[i][j]=='.'){
        dfs(i-1,j);
        dfs(i+1,j);
        dfs(i,j-1);
        dfs(i,j+1);
    }
    // encountered a locked gate
    if(isgate(i,j)){
        int index=maze[i][j]-'A';
        gate[index]=true;
        // discovery! new gate
        sth_new=true;
        // remember the position of the gate
        gate_points[index].i=i;
        gate_points[index].j=j;
    }
}
void go(){
    while(1){
        memset(visited,0,sizeof(visited));
        sth_new=false;
        try{
            dfs(start.i,start.j);
        }catch(...){return;}
        // no new key and no new gate
        // this implicitly means there is no new place to explore
        if(!sth_new)return;
        // if there is a new gate that could be opened
        bool opened_new=false;
        for(int i=0;i<26;i++){
            // open the gate
            if(cur_keycount[i]==keycount[i]&&gate[i]){
                gate[i]=false;
//                printf("open gate %c with key\n",'a'+i);
                maze[gate_points[i].i][gate_points[i].j]='.';
                opened_new=true;
            }
        }
        // if no new gate could be opened, 
        // this implicitly means that only new gate is discovered in last dfs()
        if(!opened_new)break;
    };
}
int main(){
    while(1){
        scanf("%d %d",&m,&n);getchar();
        if(!(m|n))break;
        memset(gate,0,sizeof(gate));
        memset(keycount,0,sizeof(keycount));
        memset(cur_keycount,0,sizeof(cur_keycount));
        found=false;         
        for(int i=0;i<m;i++){
//            gets(maze[i]);
            for(int j=0;j<n;j++){
                cin>>maze[i][j];
                if(maze[i][j]=='S'){
                    start.i=i;
                    start.j=j;
                    maze[i][j]='.';
                }
                if(iskey(i,j)){
                    keycount[maze[i][j]-'a']++;
                }
            }
        }
        go();
        if(found)printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
