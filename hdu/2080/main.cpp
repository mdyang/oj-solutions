#include<stdio.h>
#include<math.h>
#define PI 3.1415926
int main(){
	int c;
	double x1,y1,x2,y2;
	scanf("%d",&c);
	while(c--){
		scanf("%lf %lf %lf %lf",&x1,&y1,&x2,&y2);
		double r = acos((x1*x2+y1*y2)/sqrt((x1*x1+y1*y1)*(x2*x2+y2*y2)));
		r=r*180.0/PI;
		printf("%.2lf\n",r);
	}
	return 0;
}