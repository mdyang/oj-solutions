#include<iostream>
#include<memory.h>
#include<cmath>
using namespace std;
typedef struct _item{
    int v;
    int w;
    int sum;
}item;
item items[25];
int n,m,sum[30000];
int main(){
    int t;
    cin>>t;
    while(t--){
        cin>>m>>n;
        memset(sum,0,sizeof(sum));
        for(int i=0;i<n;i++){
            cin>>items[i].v>>items[i].w;
            items[i].sum=items[i].v*items[i].w;
        }
        for(int i=0;i<n;i++){
            for(int j=m;j>=items[i].v;j--){
                int nv=sum[j-items[i].v]+items[i].sum;
                sum[j]=max(nv,sum[j]);
            }
        }
        cout<<sum[m]<<endl;
    }
    return 0;
}
