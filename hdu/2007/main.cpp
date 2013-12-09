#include<stdio.h>
#define SQR(n) (n*n)
#define CUB(n) (n*n*n)
int main(){
    int m,n;
    while(scanf("%d%d",&m,&n)!=EOF){
        if(m>n){int temp=m;m=n;n=temp;}
        int sume=0,sumo=0;
        for(int i=m;i<=n;i++)
            if(i&1)sumo+=CUB(i);
            else sume+=SQR(i);
        printf("%d %d\n",sume,sumo);
    }
    return 0;
}
