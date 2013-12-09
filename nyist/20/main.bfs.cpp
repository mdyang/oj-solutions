#include <iostream>
#include <deque>
#include <vector>
#include <memory.h>

using namespace std;

vector<int> graph[100001];
int path[100001];
bool visited[100001];

void bfs(int s){
    deque<int> q;
    q.push_back(s);
    while(!q.empty()){
        int n = q.front();
        visited[n]=true;
        q.pop_front();
        for(int i=0;i<graph[n].size();i++){
            if(visited[graph[n][i]])continue;
            path[graph[n][i]]=n;
            q.push_back(graph[n][i]);
        }
    }
}

int main(){
    int m;
    cin>>m;
    while(m--){
        memset(graph,0,sizeof(graph));
        memset(visited,0,sizeof(visited));
        for(int i=0;i<100001;i++)graph[i].clear();
        int n,s;
        cin>>n>>s;
        for(int i=1;i<n;i++){
            int from,to;
            cin>>from>>to;
            graph[from].push_back(to);
            graph[to].push_back(from);
        }
        if(n==1){
            cout<<-1<<endl;
            continue;
        }
        path[s]=-1;
        bfs(s);
        for(int i=1;i<=n;i++)cout<<path[i]<<' ';
        cout<<endl;
    }
}
