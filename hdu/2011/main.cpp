#include<stdio.h>
double item(int n){
    return n&1?1.0/n:-1.0/n;
}
double sum[1001]={0.0};
int main(){
    for(int i=1;i<1001;i++)sum[i]=sum[i-1]+item(i);
    int n;
    scanf("%d",&n);
    while(n--){
        int m;
        scanf("%d",&m);
        printf("%.2lf\n",sum[m]);
    }
    return 0;
}
