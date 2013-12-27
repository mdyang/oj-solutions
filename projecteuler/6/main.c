#include<stdio.h>
#define sqr(x) (x*x)
int main(){
	int sum=0;
	for(int i=1;i<=100;i++)sum+=sqr(i);
	printf("%d\n",sqr(5050)-sum);
	return 0;
}