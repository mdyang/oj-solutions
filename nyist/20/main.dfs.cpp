#include<iostream>
#include<memory.h>
#include<vector>

using namespace std;

vector<int> graph[100001];
int path[100001];
bool visited[100001];
int S;

void dfs(int p){
    if (visited[p]) return;
    visited[p] = true;
    S--;
    if (!S) throw true;
    for (int i=0;i<graph[p].size();i++){
        if (visited[graph[p][i]]) continue;
        path[graph[p][i]]=p;
        dfs(graph[p][i]);
    }
}

int main(){

    int c;
    cin>>c;
    while(c--){
        memset(visited,0,sizeof(visited));
        memset(path,0,sizeof(path));
        for(int i=0;i<100001;i++)graph[i].clear();
        int n,s;
        cin>>n>>s;
        S=n;
        if(n==1){
            cout<<-1<<endl;
            continue;
        }
        for(int i=1;i<n;i++){
            int from,to;
            cin>>from>>to;
            graph[from].push_back(to);
            graph[to].push_back(from);
        }
        path[s]=-1;
        try{
            dfs(s);
        }catch(...){}
        for(int i=1;i<=n;i++) cout<<path[i]<<' ';
        cout<<endl;
    }

    return 0;
}
