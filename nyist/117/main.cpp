#include<stdio.h>
int main(){
	int n;
	scanf("%d",&n);
	while(n--){
		long long len=0,last=0,curr=0,c=0;
		scanf("%lld",&len);
		scanf("%lld",&last);len--;
		while(len--){
			scanf("%lld",&curr);
			if(last>curr)c++;
			last=curr;
		}
		printf("%lld\n",c);
	}
	return 0;
}