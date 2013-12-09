#include<stdio.h>
bool is[1000];
int cube(int n){return n*n*n;}
bool is_(int n){
    int a=n/100;
    int b=(n%100)/10;
    int c=n%10;
    if(cube(a)+cube(b)+cube(c)==n)return true;
    return false;
}
int main(){
    for(int i=100;i<1000;i++)is[i]=is_(i);
    int i,j;
    while(scanf("%d %d",&i,&j)!=EOF){
        bool has=false;
        for(int k=i;k<=j;k++){
            if(is[k]){
                if(has)printf(" ");
                else has=true;
                printf("%d",k);
            }
        }
        if(!has)printf("no");
        printf("\n");
    }
    return 0;
}
