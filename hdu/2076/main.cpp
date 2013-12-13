#include<math.h>
#include<stdio.h>
int main(){
	int c;double h,m,s;
	scanf("%d",&c);while(c--){
		scanf("%lf %lf %lf",&h,&m,&s);
		if(h>12)h-=12;
		m+=(s/60);
		h+=(m/60);
		m=fabs(h*5-m);
		if(m>30)m=60-m;
		printf("%d\n",(int)(m*6));
	}
	return 0;
}