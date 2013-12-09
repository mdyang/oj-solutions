#include <stdio.h>
#include <math.h>

int main(){

    long long x1,y1,x2,y2,x3,y3;
    while(1){
        scanf("%lld%lld%lld%lld%lld%lld",&x1,&y1,&x2,&y2,&x3,&y3);
        if((x1|y1|x2|y2|x3|y3)==0) break;
        x2-=x1;x3-=x1;y2-=y1;y3-=y1;
        double a=fabs(x2*y3-x3*y2)/2;
        printf("%.1lf\n",a);
    }

    return 0;

}
