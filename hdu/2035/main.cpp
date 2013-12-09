#include<stdio.h>
int mulmod(int a,int b,int m){
    return (a%m)*(b%m)%m;
}
int expmod(int a,int b,int m){
    if(b==0)return 1;
    if(b==1)return a%m;
    if(b&1)return mulmod(expmod(a,b-1,m),a,m);
    int mod=expmod(a,b/2,m);
    return mulmod(mod,mod,m);
}
int main(){
    int a,b;
    while(1){
        scanf("%d%d",&a,&b);
        if((a|b)==0)break;
        printf("%d\n",expmod(a,b,1000));
    }
    return 0;
}
