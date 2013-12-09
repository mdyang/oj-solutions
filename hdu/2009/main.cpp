#include<stdio.h>
#include<math.h>

int main(){
    int n,m;
    while(scanf("%d %d",&n,&m)!=EOF){
        double sum=n;
        double current=sqrt(n);
        for(int i=1;i<m;i++,current=sqrt(current)){
            sum+=current;
        }
        printf("%.2f\n",sum);
    }
    return 0;
}
