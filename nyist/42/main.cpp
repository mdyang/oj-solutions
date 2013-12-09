#include<iostream>
#include<memory.h>
using namespace std;
int f[1001];
int degree[1001];
int father(int x){
    return (f[x]==x)?x:(f[x]=father(f[x]));
}
int p,q;
int main(){
    int t;
    cin>>t;
    while(t--){
        memset(degree,0,sizeof(degree));
        cin>>p>>q;
        for(int i=1;i<=p;i++){
            f[i]=i;
        }
        for(int i=0;i<q;i++){
            int a,b;
            cin>>a>>b;
            degree[a]++;
            degree[b]++;
            int x=father(a);
            int y=father(b);
            if(x!=y)f[x]=y;
        }
        bool failed=false;
        for(int i=1;i<p;i++){
            if(father(i)!=father(i+1)){
                failed=true;
                cout<<"No\n";
                break;
            }
        }
        if(failed)continue;
        int odd=0;
        for(int i=1;i<=p;i++){
            if(degree[i]&1){
                odd++;
            }
        }
        if(odd==0||odd==2)cout<<"Yes\n";
        else cout<<"No\n";
    }
    return 0;
}
