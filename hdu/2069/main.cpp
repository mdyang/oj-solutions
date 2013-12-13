#include<stdio.h>
int cent[5]={50,25,10,5,1};
int stack[5];
int calc(int c){
	int sp=0,remain=c,count=0,coins=0;
	bool in=true;
	while(1){
		if(sp<0)break;
		if(sp==4){
			if(coins+remain<=100)count++;
			sp--;
			in=false;
		}
		if(in){
			stack[sp]=remain/cent[sp];
			coins+=stack[sp];
			remain%=cent[sp];
			sp++;
		}
		else{
			stack[sp]--;
			if(stack[sp]<0){
				sp--;
				in=false;
			}
			else{
				coins--;
				remain+=cent[sp];
				sp++;
				in=true;
			}
		}
	}
	return count;
}
int main(){
	int c;
	while(scanf("%d",&c)!=EOF)printf("%d\n",calc(c));
	return 0;
}