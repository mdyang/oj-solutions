#include<stdio.h>
int T[302];
int W[301];
void init(){
    T[1]=1;
    for(int i=2;i<=301;i++){
        T[i]=T[i-1]+i;
    }
    W[1]=T[2];
    for(int i=2;i<=300;i++){
        W[i]=W[i-1]+i*T[i+1];
    }
}
int main(){
    init();
    int t;
    scanf("%d",&t);
    for(int i=1;i<=t;i++){
        int n;
        scanf("%d",&n);
        printf("%d %d %d\n",i,n,W[n]);
    }
    return 0;
}
