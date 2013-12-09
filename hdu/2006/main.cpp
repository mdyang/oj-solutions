#include<stdio.h>
int main(){
    int n;
    while(scanf("%d",&n)!=EOF){
        int prod=1;
        int temp;
        while(n--){
            scanf("%d",&temp);
            if(temp&1)prod*=temp;
        }
        printf("%d\n",prod);
    }
    return 0;
}
