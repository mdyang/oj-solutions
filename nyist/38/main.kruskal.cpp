#include<iostream>
#include<algorithm>
using namespace std;
typedef struct _E{
    int from;
    int to;
    int len;
}E;
int f[501];
E arr[125000];
int comp(const E&a, const E&b){
    return a.len<b.len;
}
int father(int x){
    return f[x]==x?x:f[x]=father(f[x]);
}
int main(){
    int c;
    cin>>c;
    while(c--){
        int v,e;
        cin>>v>>e;
        for(int i=0;i<e;i++){
            cin>>arr[i].from>>arr[i].to>>arr[i].len;
        }
        for(int i=0;i<=v;i++)f[i]=i;
        sort(arr,arr+e,comp);
        int len=0;
        for(int i=0;i<e;i++){
            int a=father(arr[i].from);
            int b=father(arr[i].to);
            if(a==b)continue;
            len+=arr[i].len;
            f[a]=b;
        }
        int out;cin>>out;
        for(int i=1;i<v;i++){
            int temp;
            cin>>temp;
            if(temp<out)out=temp;
        }
        len+=out;
        cout<<len<<endl;
    }
    return 0;
}
