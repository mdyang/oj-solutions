#include<iostream>
using namespace std;
typedef struct _elem{
    int left;
    int right;
    int no;
}elem;
elem arr[10000];
elem tree[40000];
int points[20000];
int n;
int pow2(int);
// build a segment tree
int init(){
    int _n=n,count=0;
    while((_n/=2)>0)count++;
    // leaves on the last line
    int ll=(n-pow2(count))*2;
    // leaves on the second last line
    // i.e nodes remains after scanning the last line
    int lm=n-ll;
    // index of the last node
    int i=2*n-1;
    for(int j=0;j<ll;j++,i--){
        tree[i].left=tree[i].right=points[n-1-lm-j];
        tree[i].no=0;
    }
    for(int j=0;j<lm;j++,i--){
        tree[i].left=tree[i].right=points[n-1-j];
        tree[i].no=0;
    }
    for(;i>0;i--){
        tree[i].left=tree[i*2].left;
        tree[i].right=tree[i*2+1].right;
        tree[i].no=0;
    }
    n=2*n-1;

    return count;
}
void visit(int i){
    if(i>n)return;
    cout<<'('<<tree[i].left<<','<<tree[i].right<<')';
    if(i*2<=n){
        cout<<'[';
        visit(i*2);
        visit(i*2+1);
        cout<<']';
    }
}
int pow2(int n){
    if(n==1)return 2;
    if(n&1)return 2*pow2(n-1);
    else{
        int t=pow2(n/2);
        return t*t;
    }
}
int main(){

    n=5;
    for(int i=0;i<n;i++)points[i]=i;
    init();
    visit(1);
    cout<<endl;

    n=8;
    for(int i=0;i<n;i++)points[i]=i;
    init();
    visit(1);
    cout<<endl;

    return 0;
}
