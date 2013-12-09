#include<stdio.h>
int move(int from,int to){
    return (from<to)?
        ((to-from)*6+5):
        ((from-to)*4+5);
}
int main(){
    for(;;){
        int t;
        scanf("%d",&t);
        if(t==0)break;
        int sum=0;
        int from=0;
        for(int i=0;i<t;i++){
            int to;
            scanf("%d",&to);
            sum+=move(from,to);
            from=to;
        }
        printf("%d\n",sum);
    }
    return 0;
}
