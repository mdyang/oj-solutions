#include<stdio.h>
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n,m;
        scanf("%d %d",&n,&m);
        printf("%s\n",n%(m+1)?"Win":"Lose");
    }
    return 0;
}
