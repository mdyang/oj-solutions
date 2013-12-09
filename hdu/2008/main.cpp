#include<stdio.h>
#include<memory.h>
int loc(double n){
    if(n<0.0)return 0;
    if(n>0.0)return 2;
    return 1;
}
int count[3];
int main(){
    int n;
    while(scanf("%d",&n)!=EOF&&n>0){
        memset(count,0,sizeof(count));
        double t;
        while(n--){
            scanf("%lf",&t);
            count[loc(t)]++;
        }
        printf("%d %d %d\n",count[0],count[1],count[2]);
    }
    return 0;
}
