#include<stdio.h>
void main(){
	int a=0,b=1,c;
	unsigned long long sum=0;
	while(1){
		c=a+b;
		if(c>4000000)break;
		if(!(c&1))sum+=c;
		a=b;b=c;
	}
	printf("%I64d\n",sum);
}