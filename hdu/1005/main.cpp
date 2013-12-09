#include<iostream>
using namespace std;
typedef struct _matrix{
    int a[2][2];
}matrix;
matrix mmul(matrix,matrix);
matrix mexp(matrix m,int n){
    if(n==1)return m;
    if(n&1)return mmul(mexp(m,n-1),m);
    matrix r=mexp(m,n/2);
    return mmul(r,r);
}
matrix mmul(matrix m,matrix n){
    matrix ret;
    ret.a[0][0]=(m.a[0][0]*n.a[0][0]+m.a[0][1]*n.a[1][0])%7;
    ret.a[0][1]=(m.a[0][0]*n.a[0][1]+m.a[0][1]*n.a[1][1])%7;
    ret.a[1][0]=(m.a[1][0]*n.a[0][0]+m.a[1][1]*n.a[1][0])%7;
    ret.a[1][1]=(m.a[1][0]*n.a[0][1]+m.a[1][1]*n.a[1][1])%7;
    return ret;
}
int main(){
    int a,b,n;
    while(1){
        cin>>a>>b>>n;
        if((a|b|n)==0)break;
        if (n==1||n==2){
            cout<<1<<endl;
            continue;
        }
        matrix m,r;
        m.a[0][0]=a;
        m.a[0][1]=b;
        m.a[1][0]=1;
        m.a[1][1]=0;
        r=mexp(m,n-2);
        cout<<(r.a[0][0]+r.a[0][1])%7<<endl;
    }
    return 0;
}


