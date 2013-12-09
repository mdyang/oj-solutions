#include<iostream>
#include<set>
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
set<int> s,r;
// build a segment tree
// tree[i] represents interval [tree[i].left,tree[i].right)
// right-close-left-open interval
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
        tree[i].left=points[n-lm-j-1];
        tree[i].right=points[n-lm-j];
        tree[i].no=0;
    }
    for(int j=0;j<lm;j++,i--){
        tree[i].left=points[n-j-1];
        tree[i].right=points[n-j];
        tree[i].no=0;
    }
    for(;i>0;i--){
        tree[i].left=tree[i*2].left;
        tree[i].right=tree[i*2+1].right;
        tree[i].no=0;
    }
    n=2*n-1;
    //for(int i=1;i<=n;i++){
    //    cout<<'('<<tree[i].left<<','<<tree[i].right<<')';
    //}

    return count;
}
void visit(int i){
    if(i>n)return;
    //cout<<i<<','<<tree[i].no<<endl;
    if(tree[i].no!=0){
        r.insert(tree[i].no);
        return;
    }
    visit(i*2);
    visit(i*2+1);
}
void post(int i,int l,int r,int p){
    //cout<<"post("<<i<<','<<l<<','<<r<<','<<p<<')'<<endl;
    if(i>n)return;
    if(tree[i].left==l&&tree[i].right==r+1){
        tree[i].no=p;
        return;
    }
    if(i*2<n){
        int no=tree[i].no;
        if(no)tree[i*2].no=no;
        if(no)tree[i*2+1].no=no;
        tree[i].no=0;
        int left=max(l,tree[i*2].left);
        int right=min(r,tree[i*2].right-1);
        if(left<=right){
            post(i*2,left,right,p);
        }
        left=max(l,tree[i*2+1].left);
        right=min(r,tree[i*2+1].right);
        if(left<=right){
            post(i*2+1,left,right,p);
        }
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

    int c;
    cin>>c;
    while(c--){
        s.clear();
        int i;
        cin>>i;
        for(int j=0;j<i;j++){
            int a,b;
            cin>>a>>b;
            s.insert(a);
            s.insert(b);
            arr[j].left=a;
            arr[j].right=b;
        }
        n=s.size();
        int _i=0;
        for(set<int>::iterator it=s.begin();it!=s.end();it++){
            points[_i++]=*it;
        }
        points[_i]=points[_i-1]+1;
        init();
        for(int j=0;j<i;j++){
            post(1,arr[j].left,arr[j].right,j+1);
        }
        r.clear();
        visit(1);
        cout<<r.size()<<endl;
    }

    return 0;
}
