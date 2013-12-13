#include<stdio.h>
int c[21];
int main(){
	c[0]=1;
	for(int i=1;i<=20;i++)c[i]=c[i-1]*3;
	int n;scanf("%d",&n);while(n--){
		int m;scanf("%d",&m);printf("%d\n",c[m-1]+1);
	}
	return 0;
}