#include<iostream>
#include<deque>
#include<memory.h>
#include<limits.h>
using namespace std;

bool visited[100][100][100];

typedef struct _status{
    int c[3];
    int s;
}status;

int c[3];
int s[3];

// i=>j
status next_status(status s,int i,int j){
    if(s.c[i]==0||s.c[j]==c[j])return s;
    status ret=s;ret.s++;
    if(s.c[i]+s.c[j]>c[j]){
        ret.c[i]=s.c[i]+s.c[j]-c[j];
        ret.c[j]=c[j];
    }
    else{
        ret.c[i]=0;
        ret.c[j]=s.c[i]+s.c[j];
    }
    return ret;
}

int main(){

    int n;
    cin>>n;
    while(n--){
        memset(visited,0,sizeof(visited));
        cin>>c[0]>>c[1]>>c[2]>>s[0]>>s[1]>>s[2];
        if(c[0]==s[0]&&c[1]==s[1]&&c[2]==s[2]){
            cout<<0<<endl;continue;
        }
        status init_s;
        init_s.c[0]=c[0];
        init_s.c[1]=0;
        init_s.c[2]=0;
        init_s.s=0;
        deque<status> q;
        q.push_back(init_s);
        int min_step=INT_MAX;
        while(!q.empty()){
            status cur_s=q.front();
            q.pop_front();
            visited[cur_s.c[0]][cur_s.c[1]][cur_s.c[2]]=true;
            status new_s[6] = {
                next_status(cur_s,0,1),
                next_status(cur_s,0,2),
                next_status(cur_s,1,0),
                next_status(cur_s,1,2),
                next_status(cur_s,2,0),
                next_status(cur_s,2,1)};
            for(int i=0;i<6;i++){
                status _s=new_s[i];
                if(_s.c[0]==s[0]&&_s.c[1]==s[1]&&_s.c[2]==s[2]){
                    if(_s.s<min_step)min_step=_s.s;
                }
                else{
                    if(visited[_s.c[0]][_s.c[1]][_s.c[2]])continue;
                    q.push_back(_s);
                }                    
            }
        }
        if (min_step==INT_MAX) cout<<-1<<endl;
        else cout<<min_step<<endl;
    }

    return 0;

}
