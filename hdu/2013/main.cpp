#include<stdio.h>
int peaches[30]={1};
int main(){
    for(int i=1;i<30;i++)peaches[i]=(peaches[i-1]+1)*2;
    int n;
    while(scanf("%d",&n)!=EOF){
        printf("%d\n",peaches[n-1]);
    }
    return 0;
}
