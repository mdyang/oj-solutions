#include <stdio.h>
#include <stdlib.h>
#include <math.h>

long long sqr(long long a){
    return a*a;
}

int main(){

    long long x1,y1,x2,y2,x3,y3;
    while(1){
        scanf("%lld%lld%lld%lld%lld%lld",&x1,&y1,&x2,&y2,&x3,&y3);
        if((x1|y1|x2|y2|x3|y3)==0) break;
        double a = sqrt(sqr(x1-x2)+sqr(y1-y2));
        double b = sqrt(sqr(x1-x3)+sqr(y1-y3));
        double c = sqrt(sqr(x3-x2)+sqr(y3-y2));
        double p = (a+b+c)/2;
        double s = sqrt(p*(p-a)*(p-b)*(p-c));
        printf("%.1lf\n",s);
    }

    return 0;

}
