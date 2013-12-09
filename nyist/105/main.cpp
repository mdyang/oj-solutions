#include<stdio.h>
#include<string.h>
char s[1000001];
int main(){
	int c;scanf("%d",&c);while(c--){
		scanf("%s",s);
		int len=strlen(s),sum=0;
		for(int i=0;i<len;i++)sum+=(s[i]-'0');
		printf("%d\n",sum%9);
	}
	return 0;
}