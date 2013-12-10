#include<stdio.h>
char ss[32];
int main(){
	int n;bool first=true;
	scanf("%d",&n);
	while(n--){
		if(first)first=false;
		else printf("\n");
		int m;
		scanf("%d",&m);
		double sum=0,credits=0,c,s;
		bool illegal=false;
		while(m--){
			scanf("%s %lf %lf",ss,&c,&s);
			if(s<60)illegal=true;
			else{
				credits+=c;
				sum+=(c*s);
			}
		}
		if(illegal)printf("Sorry!\n");
		else printf("%.2lf\n",sum/credits);
	}
	return 0;
}