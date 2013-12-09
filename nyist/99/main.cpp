#include<iostream>
#include<string>
#include<algorithm>
#include<memory.h>
using namespace std;
int c;
int f;
string words[1000];
int order[1000];
int concat[1000];
bool visited[1000];
int route[1000];
int fathers[26];
int indegree[26];
int outdegree[26];
bool letter_occur[26];
int letter_count=0;
char letters[26];
int father(int x){
    return(x==fathers[x])?x:(fathers[x]=father(fathers[x]));
}
int comp(const int i,const int j){
    return words[i].compare(words[j])<0;
}
int first(char ch,int i,int j){
    int l=i,r=j;
    while(l<=r){
        int m=(l+r)/2;
        if(words[order[m]][0]==ch&&
                (m==0||(m>0&&words[order[m-1]][0]<ch))) 
            return m;
        if(words[order[m]][0]<ch)l=m+1;
        else r=m-1;
    }
    return -1;
}

int first(char ch){
    return first(ch,0,c-1);
}
void find(int i){
    if(visited[i])return;
    visited[i]=true;
    route[f++]=order[i];
    if(f==c)throw true;
    char ch=words[order[i]][words[order[i]].size()-1];
    int j=first(ch);
    if(j!=-1){
        for(int k=j;k<c&&words[order[k]][0]==ch;k++){
            find(k);
        }
    }
    visited[i]=false;
    f--;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        cin>>c;
        cin.ignore();
        memset(visited,0,sizeof(visited));
        memset(indegree,0,sizeof(indegree));
        memset(outdegree,0,sizeof(outdegree));
        memset(letter_occur,0,sizeof(letters));
        letter_count=0;
        for(int i=0;i<26;i++)fathers[i]=i;
        for(int i=0;i<c;i++){
            getline(cin,words[i]);
            order[i]=i;
            int last=words[i][words[i].size()-1]-'a';
            int first=words[i][0]-'a';
            int x=father(first);
            int y=father(last);
            if(x!=y) fathers[x]=y;
            outdegree[first]++;
            indegree[last]++;
            letter_occur[first]=letter_occur[last]=true;
        }
        for(int i=0;i<26;i++){
            if(letter_occur[i])letters[letter_count++]=i;
        }
        bool failed=false;
        for(int i=0;i<letter_count-1;i++){
            if(father(letters[i])!=father(letters[i+1])){
                cout<<"***\n";
                failed=true;
                break;
            }
        }
        if(failed)continue;
        bool start_found=false,end_found=false;
        for(int i=0;i<26;i++){
            if(indegree[i]!=outdegree[i]){
                if(outdegree[i]-indegree[i]==1&&start_found==false)start_found=true;
                else if(indegree[i]-outdegree[i]==1&&end_found==false)end_found=true;
                else{
                    cout<<"***\n";
                    failed=true;
                    break;
                }
            }
        }
        if(failed)continue;
        f=0;
        sort(order,order+c,comp);
        try{
            for(int i=0;i<c;i++){
                find(i);
            }
        }catch(...){
            cout<<words[route[0]];
            for(int i=1;i<c;i++){
                cout<<'.'<<words[route[i]];
            }
            cout<<endl;
        }
    }

    return 0;
}
