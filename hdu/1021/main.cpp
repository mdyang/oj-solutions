#include<stdio.h>
int i=0;
unsigned char num[1000000];
void init(){
    num[i++]=1;
    num[i++]=2;
    for(;;){
        num[i]=(num[i-1]+num[i-2])%3;
        if(++i >= 1000000)break;
    }
}
int main(){
    init();
    int t;
    while(scanf("%d",&t)!=EOF){
        printf((num[t]==0)?"yes\n":"no\n");
    }
    return 0;
}
