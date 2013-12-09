#include<stdio.h>
#include<math.h>
int overtake(long int a,long int b){
/*    if(a>0)a=-a;
    if(b>0)b=-b;
    return(a<b);*/
    return abs(a)>abs(b);
}
int main(){
    int r,c;
    long m=0;
    int mr=1,mc=1,temp;
    int i,j;
    while(scanf("%d%d",&r,&c)!=EOF){
        for(i=1;i<=r;i++)
            for(j=1;j<=c;j++){
                scanf("%d",&temp);
                if(overtake(temp,m)){
                    mr=i;mc=j;m=temp;
                }
            }
        printf("%d %d %ld\n",mr,mc,m);
    }
    return 0;
}
