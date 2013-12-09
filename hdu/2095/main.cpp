#include<stdio.h>
int main(){
	while(1){
		int c;scanf("%d",&c);
		if(!c)break;
		int a=0,b;
		while(c--){
			scanf("%d",&b);
			a^=b;
		}
		printf("%d\n",a);
	}
	return 0;
}