#include<stdio.h>
unsigned long long table[51];
int main(){
    table[0]=0;
    table[1]=1;
    for(int i=2;i<51;i++)table[i]=table[i-2]+table[i-1];
    int temp;
    while(1){
        scanf("%d",&temp);
        if(temp==-1)break;
        printf("%I64d\n",table[temp]); // on g++ should be %llu
    }
    return 0;
}
