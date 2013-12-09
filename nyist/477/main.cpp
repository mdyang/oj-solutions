#include <stdio.h>
#include <math.h>

const double prec = 1e-5;

bool equal(double a, double b){
    return (fabs(a-b)<prec)?true:false;
}

int main(){

    int c;
    scanf("%d",&c);
    while(c--){
        double a,b,c;
        scanf("%lf%lf%lf",&a,&b,&c);
        if (equal(a+b,c)) printf("Yes\n");
        else printf("No\n");
    }
}
