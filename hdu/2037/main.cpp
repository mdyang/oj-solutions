#include<iostream>
#include<algorithm>
using namespace std;
typedef struct _p{int x;int y;}p;
p intervals[100];
int index[100];
int comp(int i1,int i2){
    return intervals[i1].y<intervals[i2].y;
}
int main(){
    int n;
    while(cin>>n&&n>0){
        for(int i=0;i<n;i++){
            index[i]=i;
            cin>>intervals[i].x>>intervals[i].y;
        }
        sort(index,index+n,comp);
        int c=1,end=intervals[index[0]].y;
        for(int i=1;i<n;i++)
            if(intervals[index[i]].x>=end){
                end=intervals[index[i]].y;
                c++;
            }
        cout<<c<<endl;
    }
    return 0;
}
